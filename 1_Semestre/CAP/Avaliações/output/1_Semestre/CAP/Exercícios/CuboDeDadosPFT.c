// Bibliotecas
#include<stdio.h>

// Variáveis globais
#define TP 2 //total de produtos
#define TF 2 //total de filiais
#define TD 2 //total de dias

// Função main
int main(){
    // Declarações locais
    int vendas[TP][TF][TD];
    int nP = TP; // Número de produtos
    int nF = TF; // Número de filiais
    int nD = TD; // Número de dias
    int xP, xF, xD; // Valores de pesquisa do usuário

    for(int i = 0; i < nP; i++){
        for(int j = 0; j < nF; j++){
            for(int k = 0; k < nD; k++){
                printf("Digite os valores para preenchimento da matriz, na ordem produto %d filial %d dia %d:\n", i, j, k);
                scanf("%d", &vendas[i][j][k]);
            }
        }
    }
    
    printf("Digite, nesta ordem, produto/filial/dia, lembrando que a contagem inicia em 0:\n");
    scanf("%d %d %d", &xP, &xF, &xD);
    
    if(xP < nP && xF < nF && xD < nD){
        printf("O valor pedido é: %d\n", vendas[xP][xF][xD]);
    } 
    else{
        printf("Os valores digitados estão fora dos limites da matriz.\n");
    }
    
    return 0;
} // Fim da main