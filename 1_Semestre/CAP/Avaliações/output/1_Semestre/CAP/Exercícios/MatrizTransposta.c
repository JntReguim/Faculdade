// Bibliotecas
#include<stdio.h>

// Variáveis globais
#define lin 2
#define col 3

// Função main
int main(){
    // Declarações locais
    int matriz[lin][col];
    int mTransposta[col][lin];

    // Preenchimento da matriz
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("Digite os valores da matriz, linha %d e coluna %d: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Transposição da matriz
    for(int i = 0; i < col; i++){
        for(int j = 0; j < lin; j++){
            mTransposta[i][j] = matriz[j][i];
        }
    }

    // Exibição da matriz transposta
    printf("Matriz transposta:\n");
    for(int i = 0; i < col; i++){
        for(int j = 0; j < lin; j++){
            printf("%d ", mTransposta[i][j]);
        }
        printf("\n");
    }

    return 0;
} // Fim da main