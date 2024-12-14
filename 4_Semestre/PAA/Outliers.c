// Bibliotecas
#include <stdio.h>
#include <stdlib.h>

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
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
    double L;

    scanf("%d %d %d %lf", &N, &S, &k, &L);

    double **D = (double **)malloc(S * sizeof(double *));
    for(int i = 0; i < S; i++) {
        D[i] = (double *)malloc(N * sizeof(double));
    }

    for(int i = 0; i < S; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%lf", &D[i][j]);
        }
    }

    int outl = 0;

    for(int i = 0; i < S; i++) {
        double *dist = (double *)malloc((N - 1) * sizeof(double));
        int index = 0;
        for(int j = 0; j < N; j++) {
            if(j != i) {
                dist[index++] = D[i][j];
            }
        }

        quicksort(dist, 0, N - 2);

        if(dist[k] > L) {
            outl++;
        }

        free(dist);
    }

    printf("%d\n", outl);

    for(int i = 0; i < S; i++) {
        free(D[i]);
    }
    free(D);

    return 0;
}