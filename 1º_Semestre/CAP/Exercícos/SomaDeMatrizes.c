// Arquivos de cabeçalho
#include <stdio.h>

// Declarações globais
#define lin 3
#define col 3

int main(){
    // Declarações locais
    int matriz1[lin][col];
    int matriz2[lin][col];
    int somaMatriz[lin][col];

    // Entrada de dados
    printf("Digite os valores para Matriz1\n");
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            printf("linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("Digite os valores para Matriz2\n");
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            printf("linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Soma matrizes 1 e 2
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            somaMatriz[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    // Impressão de resultado
    printf("Soma das matrizes 1 e 2:\n");
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            printf("%d ", somaMatriz[i][j]);
        }
        printf("\n");       // Quebra linha depois de imprimir uma linha completa
    }
    
    return 0;
} // Fim da main