#include <stdio.h>
#include <stdlib.h>

void atualizaDP(int *dp, int *novoDP, int d, int elemento);
int contaSubconjuntos(int n, int d);

int main() {
    int n, d;

    while(1) {
        scanf("%d", &n);

        if(n == 0) {
            break;
        }

        scanf("%d", &d);

        printf("%d\n", contaSubconjuntos(n, d));
    }

    return 0;
}

void atualizaDP(int *dp, int *novoDP, int d, int elemento) {
    int restoI = elemento % d;

    for(int j = 0; j < d; j++) {
        novoDP[j] += dp[j];
        int novoResto = (j + restoI) % d;
        novoDP[novoResto] += dp[j];
    }
}

int contaSubconjuntos(int n, int d) {
    int *dp = (int *)malloc(d * sizeof(int));
    int *novoDP;

    for(int i = 0; i < d; i++) {
        dp[i] = 0;
    }

    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        novoDP = (int *)malloc(d * sizeof(int));

        for(int j = 0; j < d; j++) {
            novoDP[j] = 0;
        }

        atualizaDP(dp, novoDP, d, i);

        free(dp);
        
        dp = novoDP;
    }

    int resultado = dp[0];
    free(dp);

    return resultado;
}