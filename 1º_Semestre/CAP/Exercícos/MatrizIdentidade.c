// Arquivos de cabeçalho
#include <stdio.h>
#include <stdbool.h>

// Declarações globais
#define lin 3
#define col 3

int main(){
    // Declarações locais
    int matriz[lin][col];
    bool ok;

    // Entrada de dados
    printf("Preencha a matriz:\n");
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            printf("linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Verificando se matriz é indentidade
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            if(i == j){
                if(matriz[i][j] == 1){
                    ok = true;
                } else{
                    ok = false;
                    break;
                }
            } else{
                if(matriz[i][j] == 0){
                    ok = true;
                } else{
                    ok = false;
                    break;
                }
            }
        }
    }

    // Impressão de resultado
    printf("A matriz %s indentidade", ok ? "eh" : "nao eh");

    return 0;
} // Fim da main