#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int low, int high, int mid);
void mergeSort(int array[], int low, int high);

int main(){
    int N;
    scanf("%d", &N);
    
    int precos[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &precos[i]);
    }
    
    mergeSort(precos, 0, N - 1);
    
    int desconto = 0;

    for(int i = 2; i < N; i += 3){
        desconto += precos[i];
    }
    
    printf("%d\n", desconto);
    
    return 0;
}

void merge(int array[], int low, int high, int mid){
    int i, j, k;
    int c[high + 1];

    i = low;
    k = low;
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

    for(i = low; i < k; i++){
        array[i] = c[i];
    }
}

void mergeSort(int array[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;

        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);

        merge(array, low, high, mid);
    }
}