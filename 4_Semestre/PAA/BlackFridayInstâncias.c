// Jonatã Ap. Reguim - 824754
// Ciência da Computação

/*
Vitor Taichi Taira
Ciência da Computação
823838
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main(void) {
    int total;
    scanf("%d", &total);
    int vetor[1000];

    for(int i = 0; i < total; i++) {
        scanf("%d", &vetor[i]);
    }

    qsort(vetor, total, sizeof(int), compare);

    int desconto = 0;

    for(int i = 2; i < total; i += 3) {
        desconto += vetor[i];
    }

    printf("%d\n", desconto);

    return 0;
}