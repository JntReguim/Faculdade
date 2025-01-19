// Jonatã Ap. Reguim - 824754
// Ciência da Computação

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000000

int main(void) {
    int total;
    scanf("%d", &total);

    int *vetor = (int *)malloc(total * sizeof(int));
    bool *visitados = (bool *)calloc(MAX, sizeof(bool));

    if(!vetor || !visitados) {
        return 1;
    }

    for(int i = 0; i < total; i++) {
        scanf("%d", &vetor[i]);
    }

    bool first = true;
    for(int i = 0; i < total; i++) {
        if(!visitados[vetor[i]]) {
            if(!first) {
                printf(" ");
            }
            printf("%d", vetor[i]);
            visitados[vetor[i]] = true;
            first = false;
        }
    }

    printf("\n");

    free(vetor);
    free(visitados);

    return 0;
}