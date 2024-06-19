// Arquivos de cabeçalho
#include <stdio.h>
#include <stdbool.h>

// Declarações globais
#define lin 3
#define col 3

int main(){
    // Declarações locais
    int matriz[lin][col];
    int chave;
    bool ok;

    // Entrada de dados
    printf("Preencha a matriz:\n");
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            printf("linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Entrada de chave de busca
    printf("Digite o elemento a ser buscado na matriz: ");
    scanf("%d", &chave);

    // Busca elemento na matriz
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            if(matriz[i][j] == chave){
                ok = true;
                break;
            } else{
                ok = false;
            }
        }
        if(ok == true){
            break;
        }
    }

    // Impressão de resultado
    printf("O elemento %s na matriz!\n", ok ? "existe" : "nao existe");
    
    return 0;
} // Fim da main