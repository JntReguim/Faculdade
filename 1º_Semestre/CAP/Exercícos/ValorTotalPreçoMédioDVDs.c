// Arquivos de cabeçalho
#include <stdio.h>

// Função main
int main(){
    // Declarações locais
    int qtd;                    // Quatidade de cada tipo de DVD
    float preco;                // Preço de cada tipo de DVD
    int numDVD = 0;             // Número de DVD em estoque
    float valorT = 0;           // Valor total em estoque
    float valorM = 0;           // Valor médio da unidade de um DVD

    // Variáveld e laço
    while(1){
        // Entrada de dados
        printf("Digite a quatidade de DVDs, ou digite '0' para sair!\n");
        scanf("%d", &qtd);

        // Verficando possível quebra de laço
        if(qtd == 0){
            break;
        }

        printf("Digite o preco do DVD:\n");
        scanf("%f", &preco);

        // Incrementando variáveis
        numDVD += qtd;
        valorT += (preco * qtd); 
    }

    // Calculando valor médio de cada unidade de DVD
    valorM = valorT / numDVD;

    // Impressão de resultado
    if(numDVD > 0){
        printf("Valor Total em Estoque: %.2f\n", valorT);
        printf("Valor medio do DVD: %.2f\n", valorM);
    }
    else{
        printf("Não há DVDs na lista!\n");
    }

    return 0;
} // Função main