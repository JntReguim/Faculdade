#include <stdio.h>
#include <stdlib.h>

void mergeSort(double array[], int low, int high);
void merge(double array[], int low, int high, int mid);

int main(){
    int N, S, k;

    scanf("%d %d %d", &N, &S, &k);
    
    double soma = 0;

    for(int i=0; i < S; i++){

        double *dist = (double *)malloc(N * sizeof(double));

        for(int j=0; j < N; j++){
            scanf("%lf", &dist[j]);
        }

        mergeSort(dist, 0, N - 1);

        soma += dist[k + 1];

        free(dist);
    }

    double media = soma / S;
    
    printf("%.2lf\n", media);

    return 0;
}

void mergeSort(double array[], int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;

        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);

        merge(array, low, high, mid);
    }
}

void merge(double array[], int low, int high, int mid){
    int i, j, k;
    
    double *c = (double *)malloc((high + 1) * sizeof(double));

    i = low;
    k = low;
    j = mid + 1;

    while(i <= mid && j <= high){
        if(array[i] < array[j]){
            c[k] = array[i];

            k++;
            i++;
        } 
        else{
            c[k] = array[j];

            k++;
            j++;
        }
    }

    while(i <= mid){
        c[k] = array[i];

        k++;
        i++;
    }

    while(j <= high){
        c[k] = array[j];

        k++;
        j++;
    }

    for(i = low; i < k; i++){
        array[i] = c[i];
    }

    free(c);
}