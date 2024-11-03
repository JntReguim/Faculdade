// Bibliotecas
#include<stdio.h>
#include<stdbool.h>

// VAriáveis globais
#define lin 3
#define col 3

// Função main
int main(){
    // Declarações locais            
    int matriz [lin][col];  
    int chave;              // Armazenar valor de busca
    int pesquisa;
    
    // Lendo a matriz
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            printf("Digite os valores para matriz, linha %d e coluna %d.\n", i+1, j+1);
            scanf("%d", &matriz [i][j]);
        }
    }
    
    // Buscando número desejado
    printf("Digite um numero a ser buscado na matriz: ");
    scanf("%d", &chave);
    
    // Verificar se o número existe na matriz
    pesquisa = false;
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            if(chave == matriz [i][j]){
                pesquisa = true;
                break;
            }
        }
        if(pesquisa){
            break;
        }
    }
    
    // Impressão de resultado
    if(pesquisa){
        printf("\n O valor %d exite na matriz!\n", chave);
    }
    else{
        printf("\n O valor %d nao exite na matriz!\n", chave);
    }

    return 0;
} // Fim da main