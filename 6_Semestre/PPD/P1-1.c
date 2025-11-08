#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

typedef struct {
    int id;
    int N;
    int num_threads;
    double **A;
    double **B;
    double **C;
} thread_args;

double **aloca_matriz(int N);
void libera_matriz(double **mat, int N);
void preenche_matriz(double **mat, int N);
void *multiplica(void *arg);
int compara_resultados(double **A, double **B, int N, double tol);

int main() {
    int N, num_threads;

    printf("Digite a dimensão da matriz (N): ");
    scanf("%d", &N);

    printf("Digite o número de threads: ");
    scanf("%d", &num_threads);

    if(N <= 0 || num_threads <= 0) {
        fprintf(stderr, "Valores devem ser maiores que zero.\n");
        return 1;
    }

    if(num_threads > N) {
        printf("Ajustando número de threads para %d.\n", N);
        num_threads = N;
    }

    srand(time(NULL));

    double **A = aloca_matriz(N);
    double **B = aloca_matriz(N);
    double **C_seq = aloca_matriz(N);
    double **C_par = aloca_matriz(N);

    preenche_matriz(A, N);
    preenche_matriz(B, N);

    struct timespec ini, fim;
    double t_seq, t_par;

    // Versão sequencial
    clock_gettime(CLOCK_MONOTONIC, &ini);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            C_seq[i][j] = 0.0;
            for(int k = 0; k < N; k++) {
                C_seq[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &fim);

    t_seq = (fim.tv_sec - ini.tv_sec) + (fim.tv_nsec - ini.tv_nsec) / 1e9;
    printf("\nTempo sequencial: %.6f s\n", t_seq);

    // Versão paralela
    pthread_t threads[num_threads];
    thread_args args[num_threads];

    clock_gettime(CLOCK_MONOTONIC, &ini);
    for(int i = 0; i < num_threads; i++) {
        args[i].id = i;
        args[i].N = N;
        args[i].num_threads = num_threads;
        args[i].A = A;
        args[i].B = B;
        args[i].C = C_par;
        pthread_create(&threads[i], NULL, multiplica, &args[i]);
    }

    for(int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    clock_gettime(CLOCK_MONOTONIC, &fim);

    t_par = (fim.tv_sec - ini.tv_sec) + (fim.tv_nsec - ini.tv_nsec) / 1e9;
    printf("Tempo paralelo (%d threads): %.6f s\n", num_threads, t_par);

    if(compara_resultados(C_seq, C_par, N, 1e-6)) {
        printf("Resultados idênticos!\n");
    } else {
        printf("Diferença entre os resultados!\n");
    }

    double speedup = (t_par > 0) ? t_seq / t_par : 0.0;
    double eficiencia = speedup / num_threads;

    printf("\nDesempenho:\n");
    printf("N: %d\nThreads: %d\n", N, num_threads);
    printf("Speedup: %.4f\nEficiência: %.2f%%\n", speedup, eficiencia * 100);

    libera_matriz(A, N);
    libera_matriz(B, N);
    libera_matriz(C_seq, N);
    libera_matriz(C_par, N);

    return 0;
}

double **aloca_matriz(int N) {
    double **mat = (double **)malloc(N * sizeof(double *));
    if(mat == NULL) {
        perror("Erro ao alocar matriz");
        exit(1);
    }
    for(int i = 0; i < N; i++) {
        mat[i] = (double *)malloc(N * sizeof(double));
        if(mat[i] == NULL) {
            perror("Erro ao alocar linha");
            exit(1);
        }
    }

    return mat;
}

void libera_matriz(double **mat, int N) {
    for(int i = 0; i < N; i++) {
        free(mat[i]);
    }

    free(mat);
}

void preenche_matriz(double **mat, int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            mat[i][j] = (double)(rand() % 100) / 10.0;
        }
    }
}

void *multiplica(void *arg) {
    thread_args *args = (thread_args *)arg;
    int id = args->id;
    int N = args->N;
    int num_threads = args->num_threads;
    double **A = args->A;
    double **B = args->B;
    double **C = args->C;

    int linhas_por_thread = N / num_threads;
    int inicio = id * linhas_por_thread;
    int fim = (id == num_threads - 1) ? N : inicio + linhas_por_thread;

    for(int i = inicio; i < fim; i++) {
        for(int j = 0; j < N; j++) {
            C[i][j] = 0.0;
            for(int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    pthread_exit(NULL);
}

int compara_resultados(double **A, double **B, int N, double tol) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            double diff = A[i][j] - B[i][j];
            if(diff < 0) {
                diff = -diff;
            }
            if(diff > tol) {
                return 0;
            }
        }
    }

    return 1;
}