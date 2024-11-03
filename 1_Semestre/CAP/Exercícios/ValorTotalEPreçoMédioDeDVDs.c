// Bibliotecas
#include<stdio.h>

// Função main
int main(){
    // Declarações locais
    float preco, quantidade;
    float valorTotal = 0;
    int numDvds = 0;

    printf("Calculo de estoque de DVDs\n");

    //Variável de laço
    while(1){
        printf("Digite o preco do DVD (0 para finalizar):");
        scanf("%f", &preco);

        if(preco == 0){
            break;
        }

        printf("Digite a quantidade de DVDs:");
        scanf("%f", &quantidade);

        valorTotal += preco * quantidade;
        numDvds += quantidade;
    }

    printf("Resultados\n");
    printf("Valor total em estoque: R$ %.2f\n", valorTotal);
    
    if(numDvds > 0){
        float precoMedio = valorTotal / numDvds;
        printf("Preco medio da unidade de DVD: R$ %.2f\n", precoMedio);
    } 
    else{
        printf("Nao ha DVDs em estoque.\n");
    }

    return 0;
} // Fim da main