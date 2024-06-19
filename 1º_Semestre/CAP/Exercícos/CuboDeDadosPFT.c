// Arquivos de cabeçalho
#include <stdio.h>

// Deglarações globais
#define TP 2            // Produto
#define TF 2            // Filial
#define TD 2            // Tempo

// Função main
int main(){
    // Deglarações locais
    int np, nf, nd;             // Pesquisa do usuário
    int matriz[TP][TF][TD];

    // Entrada de dados
    printf("Digite os valores de venda(s) na matriz nesta sequencia: Produto, Filial, Data.\n");
    for(int i=0; i < TP; i++){
        for(int j=0; j < TF; j++){
            for(int k=0; k < TD; k++){
                printf("Produto %d, Filial %d, Data %d: ", i+1, j+1, k+1);
                scanf("%d", &matriz[i][j][k]);
            }
        }
    }

    // Entrada de informações de busca
    printf("\nDigite Informacoes de busca:\n");
    printf("Digite o Produto: ");
    scanf("%d", &np);
    printf("Digite a Filial: "); 
    scanf("%d", &nf);
    printf("Digite a Data: ");
    scanf("%d", &nd);
    printf("\n");

    // Impressão do número de vendas específico escolhido pelo usuário
    if ((np > 0 && np <= TP) && (nf > 0 && nf <= TF) && (nd > 0 && nd <= TD)) {
        printf("Numero de vendas do Produto %d, Filial %d, Data %d.\n", np, nf, nd);
        printf("Venda(s): %d\n\n", matriz[np-1][nf-1][nd-1]);
    } else {
        printf("Os valores digitados estao fora do escopo da matriz.\n\n");
    }

    // Impressão da matriz completa
    printf("Imprimindo venda(s) de todas os Produtos, Filiais e Datas!\n");
    for(int i=0; i < TP; i++){
        for(int j=0; j < TF; j++){
            for(int k=0; k < TD; k++){
                printf("Produto %d, Filial %d, Data %d: ", i+1, j+1, k+1);
                printf("%d\n", matriz[i][j][k]);
            }
        }
    }

    return 0;
} // Fim dmain