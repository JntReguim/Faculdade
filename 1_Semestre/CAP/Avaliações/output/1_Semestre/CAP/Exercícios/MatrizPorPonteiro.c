// Bibliotecas
#include<stdio.h>
#include<stdlib.h>

// Declarações globais
#define MAX_p 100   // Valor máximo de produtos
#define MAX_f 100   // Números de filias
#define MAX_d 100   // Números de dias computados 

// Estrutura de Matriz
typedef struct{
    int a;
    int b;
    int c;
    int A[MAX_p][MAX_f][MAX_d];
} tMatriz;

// Protótipos
void preencheMatriz(tMatriz *matriz);
void imprimeMatriz(tMatriz *matriz);

// Função main
int main(){
    // Declarações locais
    tMatriz Matriz;
    
    // Chamando sub rotinas
    preencheMatriz(&Matriz);
    imprimeMatriz(&Matriz);

    return 0;
} // Fim da main

void preencheMatriz(tMatriz *matriz){
    // Entrada de dados
    // Entrada de produtos
    printf("Digite o número de produtos existentes: ");
    scanf("%d", &matriz->a);
    
    // Verificação
    if(matriz->a > MAX_p){
        printf("Valor inválido de produtos!\n");
        exit(1);
    }
    
    // Entrada de filiais 
    printf("Digite o número de filiais existentes: ");
    scanf("%d", &matriz->b);
    
    // Verificação
    if(matriz->b > MAX_f){
        printf("Valor inválido de filias!\n");
        exit(1);
    }
    
    // Entrada de dias
    printf("Digite o número de dias a serem análisados: ");
    scanf("%d", &matriz->c);
    
    // Verificação 
    if(matriz->c > MAX_d){
        printf("Valor inválido de dias!\n");
        exit(1);
    }
    
    // Preenchimento da matriz
    for(int i=0; i < matriz->a; i++){
        for(int j=0; j < matriz->b; j++){
            for(int k=0; k < matriz->c; k++){
                printf("Digite o número de vendas do produto %d, na filial %d, no dia %d\n", i+1, j+1, k+1);
                scanf("%d", &matriz->A[i][j][k]);
            }
        }
    }
    
    // Pula linha
    printf("\n");
}

void imprimeMatriz(tMatriz *matriz){
    // Impressão de matriz
    for(int i=0; i < matriz->a; i++){
        for(int j=0; j < matriz->b; j++){
            for(int k=0; k < matriz->c; k++){
                printf("Vendas = %d do produto %d, na filial %d, no dia %d\n", matriz->A[i][j][k], i+1, j+1, k+1);
            }
        }
    }
    
}