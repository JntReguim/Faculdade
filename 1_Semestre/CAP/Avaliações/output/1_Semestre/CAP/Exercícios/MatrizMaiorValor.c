// Biblioteca
#include<stdio.h>

// Variáveias globais
#define LINHAS 3
#define COLUNAS 3

// Função main
int main(){
    // Declarações locais
    int matriz[LINHAS][COLUNAS];
    int maior = 0;

    // Preenchimento da matriz
    printf("Digite os elementos da matriz:\n");
    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    // Cálculo do maior valor
    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
    }

    // Impressão de resultado
    printf("O maior valor na matriz é: %d\n", maior);

    return 0;
} // Fim da main