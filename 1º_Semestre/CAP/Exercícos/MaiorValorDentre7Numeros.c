// Arquivos de cabeçalho
#include <stdio.h>

// Declarações globais
#define MAX_N 7

// Função main
int main(){
    // Declarações locais
    int num[MAX_N];
    int maior;

    // Entrada de dados
    printf("Digite os %d numeros:\n", MAX_N);
    for(int i=0; i < MAX_N; i++){
        scanf("%d", &num[i]);
    }
    maior = num[0];                    // Inicando um valor na variável maior

    // Comparando números
    for(int i=0; i < MAX_N; i++){
        if(num[i] > maior){
            maior = num[i];
        }
    }

    // Impressão de resultado
    printf("O maior numero: %d", maior);

    return 0;
} // Fim da main