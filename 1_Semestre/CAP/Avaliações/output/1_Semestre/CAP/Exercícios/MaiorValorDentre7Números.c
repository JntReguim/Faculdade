// Bibliotecas
#include<stdio.h>

// Função main
int main(){
    // Declarações locais
    int num[7];
    int maior;

    // Entrada de dados
    for(int i=0; i < 7; i++){
        printf("Digite o num%d: ", i+1);
        scanf("%d", &num[i]);
    }

    maior = num[0];
    // Define maior
    for(int i=0; i < 7; i++){
        if(maior < num[i]){
            maior = num[i];
        }
    }

    // Impressão de resultado
    printf("Maior numero: %d\n", maior);

    return 0;
} // Fim damain