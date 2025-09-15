#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 
#include <time.h>

// Configuração da Simulação 
#define DB_SIZE 10     
#define N_READERS 5    
#define M_WRITERS 2     
#define NUM_ROUNDS 10  

// Recursos Compartilhados
int database[DB_SIZE];
pthread_rwlock_t db_rwlock;     // O Read-Write Lock
pthread_barrier_t barrier;      // A Barreira de sincronização

typedef struct {
    int id;
    unsigned int seed;
} thread_args_t;


// @brief Função da thread Escritora.
void *writer_function(void *arg) {
    thread_args_t *args = (thread_args_t *)arg;
    int id = args->id;
    unsigned int seed = args->seed;

    for (int i = 0; i < NUM_ROUNDS; i++) {
        usleep((rand_r(&seed) % 100 + 50) * 1000); // Simula trabalho

        // 1. Adquire o lock de ESCRITA (exclusivo)
        pthread_rwlock_wrlock(&db_rwlock);

        // Início da Seção Crítica (Escrita)
        int index = rand_r(&seed) % DB_SIZE;
        int value = rand_r(&seed) % 100;
        printf(">>> Escritor %d: Alterando database[%d] de %d para %d\n", 
               id, index, database[index], value);
        database[index] = value;
        usleep(10 * 1000); 

        // 2. Libera o lock
        pthread_rwlock_unlock(&db_rwlock);
    }

    printf("Escritor %d terminou. Esperando na barreira...\n", id);
    
    // 3. Espera na barreira
    pthread_barrier_wait(&barrier);
    
    free(args);
    return NULL;
}


// @brief Função da thread Leitora.
void *reader_function(void *arg) {
    thread_args_t *args = (thread_args_t *)arg;
    int id = args->id;
    unsigned int seed = args->seed;

    for (int i = 0; i < NUM_ROUNDS; i++) {
        usleep((rand_r(&seed) % 80 + 20) * 1000); // Simula trabalho

        // 1. Adquire o lock de LEITURA (compartilhado)
        pthread_rwlock_rdlock(&db_rwlock);

        // Início da Seção Crítica (Leitura)
        printf("    (Leitor %d: Lendo...)\n", id);
        long long sum = 0;
        for (int j = 0; j < DB_SIZE; j++) {
            sum += database[j];
            usleep(5 * 1000); // Simula processamento
        }

        // 2. Libera o lock
        pthread_rwlock_unlock(&db_rwlock);
        
        printf("    (Leitor %d: Leitura concluída. Soma = %lld)\n", id, sum);
    }

    printf("Leitor %d terminou. Esperando na barreira...\n", id);
    
    // 3. Espera na barreira
    pthread_barrier_wait(&barrier);
    
    free(args);
    return NULL;
}


int main() {
    pthread_t readers[N_READERS];
    pthread_t writers[M_WRITERS];
    
    srand(time(NULL)); 

    // 1. Inicializa os recursos compartilhados
    for (int i = 0; i < DB_SIZE; i++) {
        database[i] = i + 1;
    }

    pthread_rwlock_init(&db_rwlock, NULL);

    // Inicializa a Barreira para esperar TODAS as threads
    int total_threads = N_READERS + M_WRITERS;
    pthread_barrier_init(&barrier, NULL, total_threads);

    printf("Criando %d threads leitoras e %d threads escritoras.\n", N_READERS, M_WRITERS);

    // 2. Cria as threads Escritoras
    for (int i = 0; i < M_WRITERS; i++) {
        thread_args_t *args = malloc(sizeof(thread_args_t));
        args->id = i;
        args->seed = rand();
        
        if (pthread_create(&writers[i], NULL, writer_function, args) != 0) {
            perror("Falha ao criar thread escritora");
        }
    }

    // 3. Cria as threads Leitoras
    for (int i = 0; i < N_READERS; i++) {
        thread_args_t *args = malloc(sizeof(thread_args_t));
        args->id = i;
        args->seed = rand();
        
        if (pthread_create(&readers[i], NULL, reader_function, args) != 0) {
            perror("Falha ao criar thread leitora");
        }
    }

    // 4. Espera (join) todas as threads terminarem
    for (int i = 0; i < M_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }
    for (int i = 0; i < N_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    // 5. Limpeza dos recursos
    printf("\nTodas as %d Threads passaram pela barreira.\n", total_threads);

    pthread_rwlock_destroy(&db_rwlock);
    pthread_barrier_destroy(&barrier);

    // 6. Exibe o resultado final
    printf("Estado final do 'Banco de Dados':\n[ ");
    long long final_sum = 0;
    for (int i = 0; i < DB_SIZE; i++) {
        printf("%d ", database[i]);
        final_sum += database[i];
    }
    printf("]\nSoma final: %lld\n", final_sum);

    return 0;
}

/*
Testes Adicionais e Análise Conceitual (Respostas Breves)
O que acontece se removermos o rwlock?
Sem o rwlock, teríamos condições de corrida (race conditions). Um leitor poderia ler o vetor enquanto um escritor o modifica, 
resultando em uma soma calculada sobre dados inconsistentes ou "rasgados" (metade novos, metade antigos). Além disso, dois escritores 
poderiam tentar alterar o mesmo índice simultaneamente, levando a atualizações perdidas e corrupção de dados. O programa se tornaria 
imprevisível e incorreto, pois a integridade do database não estaria garantida.

Qual a diferença prática entre read lock e write lock?
A diferença é a exclusividade. O read lock (pthread_rwlock_rdlock) é compartilhado: múltiplos leitores podem possuir o lock ao mesmo 
tempo, permitindo alta concorrência de leitura, mas ele bloqueia qualquer escritor. O write lock (pthread_rwlock_wrlock) é exclusivo: 
apenas uma thread escritora pode obtê-lo, e ele bloqueia todas as outras threads (leitores e escritores), garantindo que a modificação 
dos dados seja atômica e isolada.

Como a barreira garante que o programa não termine antes de todas as threads concluírem suas rodadas?
A barreira (pthread_barrier_t) atua como um ponto de encontro sincronizado. Ela é inicializada com o número total de threads (N+M) e, 
ao ser chamada (pthread_barrier_wait()), bloqueia cada thread que chega. Somente quando a última thread (a N+M-ésima) chama a função é 
que todas as threads são desbloqueadas para continuar. Como a função main espera as threads com pthread_join(), e as threads só podem 
terminar após passarem pela barreira, o main é efetivamente forçado a esperar que todas as threads completem suas rodadas.

Qual seria o impacto se tivéssemos muitos mais leitores que escritores?
Este cenário (ex: 100 leitores, 2 escritores) maximizaria o benefício do rwlock, permitindo um alto paralelismo de leitura, pois os 
100 leitores poderiam executar suas somas simultaneamente. O contraponto negativo é o alto risco de inanição de escritores 
(writer starvation): os escritores poderiam ficar bloqueados indefinidamente, pois a chance de haver sempre pelo menos um leitor 
ativo com o read lock seria muito alta, impedindo os escritores de obterem o write lock exclusivo.
*/
