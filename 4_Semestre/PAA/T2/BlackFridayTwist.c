#include <stdio.h>
#include <stdlib.h>

void merge(long long int array[], int low, int high, int mid);
void mergeSort(long long int array[], int low, int high);

int main(){
    int N;
    scanf("%d", &N);
    
    long long int precos[N];
    for(int i = 0; i < N; i++){
        scanf("%lld", &precos[i]);
    }
    
    mergeSort(precos, 0, N - 1);
    
    long long int desconto = 0;

    for(int i = 1; i < (N * 2/3); i += 2){
        desconto += precos[i];
    }
    
    printf("%lld\n", desconto);
    
    return 0;
}

void merge(long long int array[], int low, int high, int mid){
    int i, j, k;
    int size = high - low + 1;

    long long int *c = (long long int*)malloc(size * sizeof(long long int));

    i = low;
    k = 0;
    j = mid + 1;

    while(i <= mid && j <= high){
        if(array[i] >= array[j]){ 
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

    for(i = 0; i < k; i++){
        array[low + i] = c[i];
    }
    
    free(c);
}

void mergeSort(long long int array[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;

        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);

        merge(array, low, high, mid);
    }
}