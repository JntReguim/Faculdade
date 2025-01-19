// Jonatã Ap. Reguim - 824754
// Ciência da Computação

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    int total;
    scanf("%d", &total);

    int *precos = (int *)malloc(total * sizeof(int));
    for(int i = 0; i < total; i++) {
        scanf("%d", &precos[i]);
    }

    qsort(precos, total, sizeof(int), compare);

    long long desconto = 0;
    for(int i = 1; i < (total * 2 / 3); i += 2) {
        desconto += precos[i];
    }

    printf("%lld\n", desconto);

    free(precos);
    return 0;
}