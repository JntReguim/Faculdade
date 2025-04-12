// Bibliotecas
#include<stdio.h>
#include<stdbool.h>

// Definições globais
#define MAX 1000

// Estrutura para Conjunto
typedef struct{
    int A[MAX];    // Conjunto A
    int qtdA;      // Quantidade de elemntos no conjunto A
    int B[MAX];    // Conjunto B
    int qtdB;      // Quantidade de elementos no conjunto B
} tConjunto;

// Protótipos
void lerConjunto(tConjunto *c);
void adicionavalorConjunto(tConjunto *c);
void adicionavaloresCojunto(tConjunto *c);
void removeConjunto(tConjunto *c);
void imprimeConjunto(tConjunto *c);
void imprimeordenadoConjunto(tConjunto *c);
void verificavazioConjunto(tConjunto *c);
void qtdelementosConjunto(tConjunto *c);
void verificavalorConjunto(tConjunto *c);
void uniaoConjunto(tConjunto *c);
void intersecaoConjunto(tConjunto *c);
void diferencaConjunto(tConjunto *c);
void contidoConjunto(tConjunto *c);
void contidoouigualConjunto(tConjunto *c);
void contemConjunto(tConjunto *c);
void contemouigualConjunto(tConjunto *c);

// Função main
int main(){
    // Definições locais
    tConjunto Conjunto;
    int op;
    
    // Menu de opções
    printf("Escolha uma operação:\n\n");
    printf("1. Inserir um elemento em um conjunto.\n");
    printf("2. Inserir vários elementos em um conjunto.\n");
    printf("3. Remover um elemento de um conjunto.\n");
    printf("4. Impressão dos cojunto na ordem de leitura.\n");
    printf("5. Impressão dos conjunto em ordem crescente.\n");
    printf("6. Verificar se um conjunto está vazio.\n");
    printf("7. Retornar a quantidade de elementos dos conjunto.\n");
    printf("8. Verificar se um valor está em um conjunto.\n");
    printf("9. Retornar a união entre os conjuntos.\n");
    printf("10. Retornar a interseção entre os conjuntos.\n");
    printf("11. Diferença entre conjuntos.\n");
    printf("12. Verificar se o Conjunto A está contido no Conjunto B.\n");
    printf("13. Verificar se o Conjunto A está contido, ou é igual, ao Conjunto B.\n");
    printf("14. Verificar se o Conjunto A contem o Conjunto B.\n");
    printf("15. Verificar se o Conjunto A contem, ou é igual, ao Conjunto B.\n");
    printf("16. Sair.\n\n");
    
    // Lendo escolha de opção
    scanf("%d", &op);
    
    switch (op){
        // Inserir um elemnto em um conjunto
        case 1:
        printf("\n");
        lerConjunto(&Conjunto);
        adicionavalorConjunto(&Conjunto);
        break;
        
        // Inserir vários elementos em um conjunto
        case 2:
        lerConjunto(&Conjunto);
        adicionavaloresCojunto(&Conjunto);
        break;
        
        // Remove elemento de um conjunto
        case 3:
        lerConjunto(&Conjunto);
        removeConjunto(&Conjunto);
        break;
        
        // Impressão dos conjuntos em ordem de leitura
        case 4:
        lerConjunto(&Conjunto);
        imprimeConjunto(&Conjunto);
        break;
        
        // Impressão dos contos de forma ordenada (Crescente)
        case 5:
        lerConjunto(&Conjunto);
        imprimeordenadoConjunto(&Conjunto);
        break;
        
        // Verificar se um conjunto está vazio
        case 6:
        lerConjunto(&Conjunto);
        verificavazioConjunto(&Conjunto);
        break;
        
        // Retorna a quantidade de elementos de um conjunto
        case 7:
        lerConjunto(&Conjunto);
        qtdelementosConjunto(&Conjunto);
        break;
        
        // Verificar se um valor está presentre no conjutno
        case 8:
        lerConjunto(&Conjunto);
        verificavalorConjunto(&Conjunto);
        break;
        
        // União entre A e B
        case 9:
        lerConjunto(&Conjunto);
        uniaoConjunto(&Conjunto);
        break;
        
        // Interseção entre A e B
        case 10:
        lerConjunto(&Conjunto);
        intersecaoConjunto(&Conjunto);
        break;
        
        // Diferença entre A e B
        case 11:
        lerConjunto(&Conjunto);
        diferencaConjunto(&Conjunto);
        break;
        
        // Verificar se A está contido em B
        case 12:
        lerConjunto(&Conjunto);
        contidoConjunto(&Conjunto);
        break;
        
        // Verificar se A está contido, ou é igual, a B
        case 13:
        lerConjunto(&Conjunto);
        contidoouigualConjunto(&Conjunto);
        break;
        
        // Verificar se A contém em B
        case 14:
        lerConjunto(&Conjunto);
        contemConjunto(&Conjunto);
        break;
        
        // Verificar se A contém, ou é igual, a B
        case 15:
        lerConjunto(&Conjunto);
        contemouigualConjunto(&Conjunto);
        break;
        
        // Em caso de saída
        case 16:
        printf("Saindo...\n");
        break;
        
        // Valor fora das opções de operação
        default:
        printf("Opção inválida!\n");
    }
    
    return 0;
} // Fim da main

// Função para ler os dados de dois conjuntos A e B
void lerConjunto(tConjunto *c){
    // Pula linha
    printf("\n");
    
    // Quantidade de elementos presentes no conjunto A
    printf("Digite a quantidade de elementos que terá o conjunto Conjunto A: ");
    scanf("%d", &c->qtdA);
    
    // Entrada de dados para conjunto A
    if(c->qtdA != 0){
        for(int i=0; i < c->qtdA; i++){
            printf("Conjunto A (N°%d): ", i+1);
            scanf("%d", &c->A[i]);
        }
    }
    
    // Pula linha
    printf("\n");
    
    // Quantidade de elementos presentes no conjunto B
    printf("Digite a quantidade de elementos que terá o conjunto Conjunto B: ");
    scanf("%d", &c->qtdB);
    
    // Entrada de dados para conjunto B
    if(c->qtdB != 0){
        for(int i=0; i < c->qtdB; i++){
            printf("Conjunto B (N°%d): ", i+1);
            scanf("%d", &c->B[i]);
        }
    }
    
    // Pula linha
    printf("\n");
}

// Função para adicionar um valor em um dos dois Conjuntos [A ou B]
void adicionavalorConjunto(tConjunto *c){
    // Definições locais 
    char conjunto;
    int Elemento;

    printf("Escolha qual conjunto [A ou B] o elemento será adicionado: ");
    scanf(" %c", &conjunto); // Espaço antes do %c
    printf("\n");
    
    // Caso conjunto escolhido seja A
    if(conjunto == 'A'){
        // Verificando se o Conjunto A não está cheio
        if(c->qtdA < MAX){
            // Entrada de um novo elemento
            printf("Digite um novo elemento para adicionar ao Conjunto A: ");
            scanf("%d", &Elemento);
            printf("\n");
            
            // Adicionando novo Elemento
            c->A[c->qtdA] = Elemento;
            c->qtdA++;
            
            // Impressão do novo Conjunto A
            printf("O Conjunto A, agora tem %d elementos válidos!\n", c->qtdA);
            printf("O novo Conjunto A é:\n");

            for(int i=0; i < c->qtdA; i++){
                printf("%d ", c->A[i]);
            }
            
            // Pula linha
            printf("\n");
        } 
        // Conjunto A cheio, impressão de erro
        else{
            printf("ERRO. Conjunto A já está cheio!\n");
        }
    }
    
    // Caso conjunto escolhido seja B
    else if(conjunto == 'B'){
        // Verificando se o Conjunto B não está cheio
        if(c->qtdB < MAX){
            // Entrada de um novo elemento
            printf("Digite um novo elemento para adicionar ao Conjunto B: ");
            scanf("%d", &Elemento);
            printf("\n");
            
            c->B[c->qtdB] = Elemento;
            c->qtdB++;
            
            // Impressão do novo Conjunto B
            printf("O Conjunto B, agora tem %d elementos válidos!\n", c->qtdB);
            printf("O novo Conjunto B é:\n");

            for(int i=0; i < c->qtdB; i++){
                printf("%d ", c->B[i]);
            }
            
            // Pula linha
            printf("\n");
        }
        // Conjunto B cheio, impressão de erro
        else{
            printf("ERRO. Conjunto B já está cheio!\n");
        }
    }
    // conjunto != A ou B
    else{
        printf("Conjunto inválido.\n");
    }
    
    // Pula linha
    printf("\n");
}

// Função para adicionar vários valores em um dos dois Conjuntos [A ou B]
void adicionavaloresCojunto(tConjunto *c){
    // Definições locais
    int x;
    char conjunto;
    
    // A quantidade de elementos que será adicionado
    printf("Digite a quantidade de elementos que deseja adionar: ");
    scanf("%d", &x);
    
    int vetor[x];
    // Leitura dos elemntos
    printf("Digite o elementos que deseja inserir:\n");
    for(int i=0; i<x; i++){
        printf("(N°%d): ", i+1);
        scanf("%d", &vetor[i]);
    }
    
    // Pula linha
    printf("\n");
    
    printf("Em qual conjunto [A ou B] deseja adicionar os novos elementos: ");
    scanf(" %c", &conjunto);
    printf("\n");
    
    // Se o conjunto for A
    if(conjunto == 'A'){
        if(c->qtdA + x <= MAX){
            for(int i=0; i<x; i++){
                c->A[c->qtdA + i] = vetor[i];
            }

            printf("O novo Conjunto A é:\n");
            for(int i=0; i < c->qtdA + x; i++){
                printf("%d ", c->A[i]);
            }
        }
        // Se ultrapassar o valor máximo de A
        else{
            printf("ERRO. Conjunto ultrapassou o seu limite válido de %d", MAX);
        }
    }
    
    // Se o conjunto for B
    if(conjunto == 'B'){
        if(c->qtdB + x <= MAX){
            for(int i=0; i<x; i++){
                c->B[c->qtdB + i] = vetor[i];
            }

            printf("O novo Conjunto B é:\n");
            for(int i=0; i < c->qtdB + x; i++){
                printf("%d ", c->B[i]);
            }
        }
        // Se ultrapassar o valor máximo de B
        else{
            printf("ERRO. Conjunto ultrapassou o seu limite válido de %d", MAX);
        }
    }
    
    // Pula linha
    printf("\n");
}

// Função para remover um valor em um dos dois Conjuntos [A ou B]
void removeConjunto(tConjunto *c){
    // Declarações locais
    int remocao;               // variável que recebe valor do índice a ser removido do array
    char conjunto;
    
    // Leitura do índice e conjunto a ser alterado
    printf("Digite o Conjunto [A ou B] para remover: ");
    scanf(" %c", & conjunto);
    printf("Digite o índice do elemento a ser removido: ");
    scanf("%d", &remocao);
    printf("\n\n");
    
    // Caso conjunto A
    if(conjunto == 'A'){
        // Verificando a possibilidade de remoção
        if(remocao < 0 || remocao >= c->qtdA){
            printf("Índice inválido para remoção.\n");

            return;
        }
        else{
            // Realizando remoção
            for(int i = remocao; i < c->qtdA - 1; i++){
                c->A[i] = c->A[i + 1];
            }
            
            (c->qtdA)--;
            
            // Conjunto esvaziou
            if(c->qtdA == 0){
                printf("Conjunto A, após a remoção, agora está vazio!\n");
            }
            // Se não está vazio
            else{
                printf("Conjunto A, após a remoção, é:\n");
                    for(int i = 0; i < c->qtdA; i++){
                        printf("%d ", c->A[i]);
                    }
                printf("\n");
            }
        }
    }
    
    // Caso conjunto B
    else if(conjunto == 'B'){
        
        // Verificando a possibilidade de remoção
        if(remocao < 0 || remocao >= c->qtdB){
            printf("Índice inválido para remoção.\n");
            return;
        }
        else{
            // Realizando remoção
            for(int i = remocao; i < c->qtdB - 1; i++){
                c->B[i] = c->B[i + 1];
            }
            
            (c->qtdB)--;
            
            // Conjunto esvaziou
            if(c->qtdB == 0){
                printf("Conjunto B, após a remoção, agora está vazio!\n");
            }
            // Se não está vazio
            else{
                printf("Conjunto B, após a remoção, é:\n");
                for (int i = 0; i < c->qtdB; i++) {
                    printf("%d ", c->B[i]);
                }
                printf("\n");
            }
        }
    }
    
    // Conjunto fora de A ou B
    else{
        printf("Conjunto inexistente!\n");
    }
}

// Função para impressão dos conjuntos A e B, em sua ordem de leitura
void imprimeConjunto(tConjunto *c){
    // Impressão em ordem de leitura do Conjunto A
    printf("Os elementos do Conjunto A são:\n");
    for(int i=0; i < c->qtdA; i++){
        printf("%d ", c->A[i]);
    }
    
    // Pula linha
    printf("\n\n");
    
    // Impressão em ordem de leitura do Conjunto B
    printf("Os elementos do Conjunto B são:\n");
    for(int i=0; i < c->qtdB; i++){
        printf("%d ", c->B[i]);
    }
    
    // Pula linha
    printf("\n");
}

// Função para impressão dos conjuntos A e B, em ordem crescente
void imprimeordenadoConjunto(tConjunto *c){
    // Ordenação do Conjunto A
    for(int i = 0; i < c->qtdA - 1; i++){
        for(int j = 0; j < c->qtdA - i - 1; j++){
            if(c->A[j] > c->A[j + 1]){
                // Troca os elementos
                int temp = c->A[j];
                c->A[j] = c->A[j + 1];
                c->A[j + 1] = temp;
            }
        }
    }
    
    // Impressão ordenada do Conjunto A
    printf("O Conjunto A ordenado é:\n");
    for(int i = 0; i < c->qtdA; i++){
        printf("%d ", c->A[i]);
    }
    printf("\n\n");
    
    // Ordenação do Conjunto B
    for(int i = 0; i < c->qtdB - 1; i++){
        for(int j = 0; j < c->qtdB - i - 1; j++){
            if(c->B[j] > c->B[j + 1]){
                // Troca os elementos
                int temp = c->B[j];
                c->B[j] = c->B[j + 1];
                c->B[j + 1] = temp;
            }
        }
    }
    
    // Impressão ordenada do Conjunto B
    printf("O Conjunto B ordenado é:\n");
    for(int i = 0; i < c->qtdB; i++){
        printf("%d ", c->B[i]);
    }
    printf("\n");
}

// Função para verificar se os Conjuntos estão vazios
void verificavazioConjunto(tConjunto *c){
    // Verficação do Conjunto A
    if(c->qtdA == 0){
        printf("Conjunto A está vazio!\n");
    }
    else{
        printf("O conjunto A não está vazio!\n");
        printf("Conjunto A possui %d\n elementos válidos!", c->qtdA);
    }
    
    // Pula linha
    printf("\n");
    
    // Verficação do Conjunto B
    if(c->qtdB == 0){
        printf("Conjunto B está vazio!\n");
    }
    else{
        printf("O conjunto B não está vazio!\n");
        printf("Conjunto B possui %d\n elementos válidos!", c->qtdB);
    }
    
    // Pula linha
    printf("\n");
}

// Função para impressão dos elementos válidos de cada Conjunto
void qtdelementosConjunto(tConjunto *c){
    // Quantidade de elementos do Conjunto A
    if(c->qtdA == 0){
        printf("Conjunto A não possui elementos válidos!\n");
    }
    else{
        printf("A quantiade de elementos válidos no Conjunto A é: %d\n", c->qtdA);
    }
    
    // Pula linha
    printf("\n");

    // Quantidade de elementos do Conjunto B
    if(c->qtdB == 0){
        printf("Conjunto B não possui elementos válidos!\n");
    }
    else{
        printf("A quantiade de elementos válidos no Conjunto B é: %d\n", c->qtdB);
    }
    
    // Pula linha
    printf("\n");
}

// Função para verificar se um valor específico existe nos Conjuntos 
void verificavalorConjunto(tConjunto *c){
    // Declarações locais
    int chave;
    bool resultA = false;
    bool resultB = false;

    // Leitura do valor a ser procurado
    printf("Digite o valor a ser procurado: ");
    scanf("%d", &chave);
    printf("\n");

    // Verificação no Conjunto A
    for(int i = 0; i < c->qtdA; i++){
        if(c->A[i] == chave){
            resultA = true; 
            break; 
        }
    }

    // Verificação no Conjunto B
    for(int i = 0; i < c->qtdB; i++){
        if(c->B[i] == chave){
            resultB = true; 
            break; 
        }
    }

    // Exibição dos resultados
    if(resultA){
        printf("O valor %d existe no Conjunto A.\n", chave);
    } 
    else{
        printf("O valor %d não existe no Conjunto A.\n", chave);
    }
    
    // Pula linha
    printf("\n");

    if(resultB){
        printf("O valor %d existe no Conjunto B.\n", chave);
    } 
    else{
        printf("O valor %d não existe no Conjunto B.\n", chave);
    }
}

// Função para retornar a união entre os dois Conjuntos 
void uniaoConjunto(tConjunto *c){
    // Declarações locais
    int U[MAX];
    int qtdU = 0; 

    // Adicionar elementos do Conjunto A
    for(int i = 0; i < c->qtdA; i++){
        U[qtdU++] = c->A[i];
    }

    // Adicionar elementos do Conjunto B que não estão na união
    for(int i = 0; i < c->qtdB; i++){
        int valor = c->B[i];
        int repetido = 0;
        
        for(int j = 0; j < qtdU; j++){
            if(U[j] == valor){
                repetido = 1;
                break;
            }
        }

        if(!repetido){
            U[qtdU++] = valor;
        }
    }
    
    printf("A união entre o Conjunto A e B é:\n");
    for(int i = 0; i < qtdU; i++){
        printf("%d ", U[i]);
    }
    printf("\n");
}

// Função para retornar a interseção entre os dois Conjuntos
void intersecaoConjunto(tConjunto *c){
    
    // Verificando se existe conjunto vazio
    if(c->qtdA == 0 || c-> qtdB == 0){
        printf("ERRO. Há conjunto vazio!\n");
    }
    
    // Caso não exista
    else{
        // Impressão de resultado da interseção
        printf("Interseção dos Conjuntos A e B é:\n");
        
        for(int i = 0; i < c->qtdA; i++){
            for(int j = 0; j < c->qtdB; j++){
                if(c->A[i] == c->B[j]){
                    printf("%d ", c->A[i]);
                    break;
                }
            }
        }
    }
}

// Função para retornar a diferença entre 2 Conjuntos (A - B)
void diferencaConjunto(tConjunto *c){
    
    // Verificando se existe conjunto vazio
    if(c->qtdA == 0 || c-> qtdB == 0){
        printf("ERRO. Há conjunto vazio!\n");
    }
    
    // Caso não exista
    else{
        // Ordenação do Conjunto A
        for(int i = 0; i < c->qtdA - 1; i++){
            for(int j = 0; j < c->qtdA - i - 1; j++){
                if(c->A[j] > c->A[j + 1]){
                    // Troca os elementos
                    int temp = c->A[j];
                    c->A[j] = c->A[j + 1];
                    c->A[j + 1] = temp;
                }
            }
        }
    
        // Ordenação do Conjunto B
        for(int i = 0; i < c->qtdB - 1; i++){
            for(int j = 0; j < c->qtdB - i - 1; j++){
                if(c->B[j] > c->B[j + 1]){
                    // Troca os elementos
                    int temp = c->B[j];
                    c->B[j] = c->B[j + 1];
                    c->B[j + 1] = temp;
                }
            }
        }
        
        // Impressão de resultado
        printf("A diferença entre os Conjuntos A e B é:\n");

        for(int i = 0; i < c->qtdA; i++){
            int diferenca = 0; // Flag para verificar se o elemento está em B
            for(int j = 0; j < c->qtdB; j++){
                if(c->A[i] == c->B[j]){
                    diferenca = 1;
                    break;
                }
            }
            
            // Impressão apenas dos diferentes
            if(!diferenca){
                printf("%d ", c->A[i]);
            }
        }
    }
}

// Função para verificar se um Conjunto A está contido em um Conjunto B
void contidoConjunto(tConjunto *c){
    // Definições locais
    int contido = 1;
    
    if(c->qtdA == 0 || c-> qtdB == 0){
        printf("ERRO. Há conjunto vazio!\n");
    }
    else{
        for(int i = 0; i < c->qtdA; i++){
            int elemento = c->A[i];
            int encontrado = 0;  // Flag para verificar se o elemento está contido em c->B

            for(int j = 0; j < c->qtdB; j++){
                if(c->B[j] == elemento){
                    encontrado = 1;
                    break;
                }
            }

            if(!encontrado){
                contido = 0;  // Elemento de A não está em B, portanto A não está contido em B
                break;
            }
        }

        if(contido){
            printf("O Conjunto A está contido no Conjunto B.\n");
        } 
        else{
            printf("O Conjunto A não está contido no Conjunto B.\n");
        }
    }

}

// Função para verificar se um Conjunto A está contido ou é igual a um Conjunto B 
void contidoouigualConjunto(tConjunto *c){
    // Definições locais
    int contido = 1;
    
    if(c->qtdA == 0 || c->qtdB == 0){
        printf("ERRO. Há conjunto vazio!\n");
        return;
    }

    if(c->qtdA != c->qtdB){
        printf("Os conjuntos são diferentes em tamanho, portanto não são iguais.\n");
        return;
    }

    for(int i = 0; i < c->qtdA; i++){
        int elemento = c->A[i];
        int encontrado = 0;  // Flag para verificar se o elemento está contido em c->B

        for(int j = 0; j < c->qtdB; j++){
            if(c->B[j] == elemento){
                encontrado = 1;
                break;
            }
        }

        if(!encontrado){
            contido = 0;  // Elemento de A não está em B, portanto A não está contido em B
            break;
        }
    }

    if(contido){
        printf("O Conjunto A está contido no Conjunto B.\n");
    } 
    else{
        printf("O Conjunto A não está contido no Conjunto B.\n");
    }
}

// Funçaõ para verificar se um Conjunto A contém um Conjunto B
void contemConjunto(tConjunto *c){
    // Definições locais
    int contem = 1;

    if(c->qtdA == 0 || c->qtdB == 0){
        printf("ERRO. Há conjunto vazio!\n");
        return;
    }

    if(c->qtdA < c->qtdB){
        printf("O Conjunto A não pode conter o Conjunto B, pois A é menor.\n");
        return;
    }

    for(int i = 0; i < c->qtdB; i++){
        int elemento = c->B[i];
        int encontrado = 0;  // Flag para verificar se o elemento está contido em c->A

        for(int j = 0; j < c->qtdA; j++){
            if(c->A[j] == elemento){
                encontrado = 1;
                break;
            }
        }

        if(!encontrado){
            contem = 0;  // Elemento de B não está em A, portanto A não contém B
            break;
        }
    }

    if(contem){
        printf("O Conjunto A contém o Conjunto B.\n");
    } 
    else{
        printf("O Conjunto A não contém o Conjunto B.\n");
    }
}

// Função para verificar se um Conjunto A contém ou é igual a um Conjunto B
void contemouigualConjunto(tConjunto *c){
    // Definições locais
    int contem_ou_igual = 1;

    if(c->qtdA == 0 || c->qtdB == 0){
        printf("ERRO. Há conjunto vazio!\n");
        return;
    }

    if(c->qtdA < c->qtdB){
        contem_ou_igual = 0; // Conjunto A não pode conter B, pois A é menor
    } 
    else{
        for(int i = 0; i < c->qtdB; i++){
            int elemento = c->B[i];
            int encontrado = 0;  // Flag para verificar se o elemento está contido em c->A

            for(int j = 0; j < c->qtdA; j++){
                if(c->A[j] == elemento){
                    encontrado = 1;
                    break;
                }
            }

            if(!encontrado){
                contem_ou_igual = 0;  // Elemento de B não está em A, portanto A não contém B
                break;
            }
        }
    }

    if(contem_ou_igual){
        printf("O Conjunto A contém ou é igual ao Conjunto B.\n");
    } 
    else{
        printf("O Conjunto A não contém e não é igual ao Conjunto B.\n");
    }
}