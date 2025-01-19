// Jonatã Ap. Reguim - 824754
// Ciência da Computação

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

    int desc = 0;

    for(int i = 2; i < total; i += 3) {
        desc += vetor[i];
    }

    printf("%d\n", desc);

    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(long long int *)b - *(long long int *)a);
}

int main() {
    int tam;
    scanf("%d", &tam);

    long long int *vetor = (long long int)malloc(tam * sizeof(long long int));
    for(int i = 0; i < tam; i++) {
        scanf("%lld", &vetor[i]);
    }

    qsort(vetor, tam, sizeof(long long int), compare);

    long long int desc = 0;
    for(int i = 2; i < tam; i += 3) {
        desc += vetor[i];
    }

    printf("%lld\n", desc);

    free(vetor);

    return 0;
}
*/