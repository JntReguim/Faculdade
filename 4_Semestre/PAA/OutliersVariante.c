// Bibliotecas
#include <stdio.h>
#include <stdlib.h>

void swap(double *a, double *b) {
    double aux = *a;
    *a = *b;
    *b = aux;
}

void quicksort(double *arr, int esq, int dir) {
    if(esq >= dir) {
        return;
    }

    double pivo = arr[dir];
    int i = esq;
    for(int j = esq; j < dir; j++) {
        if(arr[j] < pivo) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[dir]);

    quicksort(arr, esq, i - 1);
    quicksort(arr, i + 1, dir);
}

int main() {
    int N, S, k;
    scanf("%d %d %d", &N, &S, &k);

    double distTotal = 0.0;

    for(int i = 0; i < S; i++) {
        double *D = (double *)malloc((N - 1) * sizeof(double));
        for(int j = 0; j < N; j++) {
            double dist;
            scanf("%lf", &dist);
            if(j != i) {
                D[j < i ? j : j - 1] = dist;
            }
        }

        quicksort(D, 0, N - 2);
        distTotal += D[k];

        free(D);
    }

    double distMedia = distTotal / S;
    printf("%.2f\n", distMedia);

    return 0;
}