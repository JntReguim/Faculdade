// Arquivos de cabeçalho
#include <stdio.h>

// Declarações globais
#define lin 3
#define col 3

int main(){
    // Declarações locais
    int matriz[lin][col];
    int matrizT[lin][col];

    // Entrada de dados
    printf("Preencha a matriz:\n");
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            printf("linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Fazendo matriz transposta
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            matrizT[i][j] = matriz[j][i]; 
        }
    }

    // Impressão de resultado
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            printf("%d ", matrizT[i][j]);
        }
        printf("\n");
    }
    
    return 0;
} // Fim da main