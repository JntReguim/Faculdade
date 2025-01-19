/*
Vitor Taichi Taira
Ciência da Computação
823838
*/

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

    bool primeiro = true;
    for(int i = 0; i < total; i++) {
        if(!visitados[vetor[i]]) {
            if(!primeiro) {
                printf(" ");
            }
            printf("%d", vetor[i]);
            visitados[vetor[i]] = true;
            primeiro = false;
        }
    }

    printf("\n");

    free(vetor);
    free(visitados);

    return 0;
}