// Bibliotecas
#include<stdio.h>

// Variáveis globais
#define lin 3
#define col 3

// Função main
int main(){
    // Declarações locais
    int matriz1[lin][col];
    int matriz2[lin][col];
    int somaMatriz[lin][col];

    // Preenchimento da matriz1
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("Digite os valores da matriz1, linha %d, e coluna %d.\n", i + 1, j + 1);
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Preenchimento da matriz2
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("Digite os valores da matriz2, linha %d, e coluna %d.\n", i + 1, j + 1);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Soma das matrizes
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            somaMatriz[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    // Impressão de resuttado
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", somaMatriz[i][j]);
        }
        printf("\n");
    }

    return 0;
} // Fim da main