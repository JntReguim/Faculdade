#include <stdio.h>
#include <stdlib.h>

int calculaSoma(int moedas[], int n);
int *criaArray0(int tamanho);
void atualizaDP(int dp[], int moeda, int metade);
int encontraMaiorSoma(int dp[], int metade);
int calculaMenorDif(int moedas[], int n);

int main() {
    int n;

    while(1) {
        scanf("%d", &n);
        
        if(n == 0) {
            break;
        }

        int *moedas = (int *)malloc(n * sizeof(int));

        for(int i = 0; i < n; i++) {
            scanf("%d", &moedas[i]);
        }

        int resultado = calculaMenorDif(moedas, n);
        printf("%d\n", resultado);

        free(moedas);
    }

    return 0;
}

int calculaSoma(int moedas[], int n) {
    int soma = 0;

    for(int i = 0; i < n; i++) {
        soma += moedas[i];
    }

    return soma;
}

int *criaArray0(int tamanho) {
    int *array = (int *)malloc((tamanho + 1) * sizeof(int));

    for(int i = 0; i <= tamanho; i++) {
        array[i] = 0;
    }

    return array;
}

void atualizaDP(int dp[], int moeda, int metade) {
    for(int j = metade; j >= moeda; j--) {
        if(dp[j - moeda] == 1) {
            dp[j] = 1;
        }
    }
}

int encontraMaiorSoma(int dp[], int metade) {
    for(int j = metade; j >= 0; j--) {
        if(dp[j] == 1) {
            return j;
        }
    }

    return 0;
}

int calculaMenorDif(int moedas[], int n) {
    int somaTotal = calculaSoma(moedas, n);
    int metade = somaTotal / 2;

    int *dp = criaArray0(metade);
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        atualizaDP(dp, moedas[i], metade);
    }

    int maiorSoma = encontraMaiorSoma(dp, metade);

    free(dp);

    return somaTotal - 2 * maiorSoma;
}