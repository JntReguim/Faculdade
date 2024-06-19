// Arquivos de cabeçalho
#include <stdio.h>

// Declarações globais
#define lin 3
#define col 3

int main(){
    // Declarações locais
    int matriz[lin][col];
    int maior;

    // Entrada de dados
    printf("Preencha a matriz:\n");
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            printf("linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Encontrando o maior valor
    maior = matriz[0][0];
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
    }

    // Impressão de resultado
    printf("O maior elemento da matriz eh %d", maior);

    return 0;
} // Fim da main