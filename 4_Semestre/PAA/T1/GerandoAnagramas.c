#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeSort(char array[], int low, int high);
void merge(char array[], int low, int high, int mid);
void trocar(char *a, char *b);
int permutar(char *anagrama, int p);

int main(){
    char array[16];
    scanf("%s", array);

    char original[16];
    strcpy(original, array);
    
    int p = strlen(array);
    
    mergeSort(array, 0, p - 1);
    
    do{
        if(strcmp(array, original) != 0){
            printf("%s\n", array);
        }

    } while(permutar(array, p));
    
    return 0;
}

void mergeSort(char array[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;

        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);

        merge(array, low, high, mid);
    }
}

void merge(char array[], int low, int high, int mid){
    int i, j, k;
    char c[high + 1];

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
}

void trocar(char *a, char *b){
    char temp = *a;

    *a = *b;
    *b = temp;
}

int permutar(char *anagrama, int p) {
    int i = p - 2;
    while(i >= 0 && anagrama[i] >= anagrama[i + 1]){
        i--;
    }
    
    if(i < 0){
        return 0;
    }
    
    int j = p - 1;
    while(anagrama[j] <= anagrama[i]){
        j--;
    }
    
    trocar(&anagrama[i], &anagrama[j]);
    
    int esq = i + 1;
    int dir = p - 1;
    while(esq < dir){
        trocar(&anagrama[esq], &anagrama[dir]);

        esq++;
        dir--;
    }
    
    return 1;
}