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
    int *ult_ocor = (int *)calloc(MAX, sizeof(int));
    bool *imprimido = (bool *)calloc(MAX, sizeof(bool));

    if(!vetor || !ult_ocor || !imprimido) {
        return 1;
    }

    for(int i = 0; i < total; i++) {
        scanf("%d", &vetor[i]);
        ult_ocor[vetor[i]] = i;
    }

    bool first = true;
    for(int i = 0; i < total; i++) {
        if(!imprimido[vetor[i]] && ult_ocor[vetor[i]] == i) {
            if(!first) {
                printf(" ");
            }
            printf("%d", vetor[i]);
            imprimido[vetor[i]] = true;
            first = false;
        }
    }

    printf("\n");

    free(vetor);
    free(ult_ocor);
    free(imprimido);

    return 0;
}

/*
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000000

int main(void) {
    int total;
    scanf("%d", &total);

    int *vetor = (int *)malloc(total * sizeof(int));
    int *ult_ocor = (int *)calloc(MAX, sizeof(int));
    bool *imprimido = (bool *)calloc(MAX, sizeof(bool));

    if(!vetor || !ult_ocor || !imprimido) {
        return 1;
    }

    for(int i = 0; i < total; i++) {
        scanf("%d", &vetor[i]);
        ult_ocor[vetor[i]] = i;
    }

    bool first = true;
    for(int i = 0; i < total; i++) {
        if(!imprimido[vetor[i]] && ult_ocor[vetor[i]] == i) {
            if(!first) {
                printf(" ");
            }
            printf("%d", vetor[i]);
            imprimido[vetor[i]] = true;
            first = false;
        }
    }

    printf("\n");

    free(vetor);
    free(ult_ocor);
    free(imprimido);

    return 0;
}
*/