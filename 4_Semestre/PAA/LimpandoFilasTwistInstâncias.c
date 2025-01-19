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
    int *ultima_ocorrencia = (int *)calloc(MAX, sizeof(int));
    bool *imprimido = (bool *)calloc(MAX, sizeof(bool));

    if(!vetor || !ultima_ocorrencia || !imprimido) {
        return 1;
    }

    for(int i = 0; i < total; i++) {
        scanf("%d", &vetor[i]);
        ultima_ocorrencia[vetor[i]] = i;
    }

    bool primeiro = true;
    for(int i = 0; i < total; i++) {
        if(!imprimido[vetor[i]] && ultima_ocorrencia[vetor[i]] == i) {
            if(!primeiro) {
                printf(" ");
            }
            printf("%d", vetor[i]);
            imprimido[vetor[i]] = true;
            primeiro = false;
        }
    }

    printf("\n");

    free(vetor);
    free(ultima_ocorrencia);
    free(imprimido);

    return 0;
}