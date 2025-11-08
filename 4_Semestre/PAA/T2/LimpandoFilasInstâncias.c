#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 10000000

int main(){
    int N;
    scanf("%d", &N);
    
    int *fila = (int*)malloc(N * sizeof(int));
    int *visitado = (int*)calloc(MAX_VALUE + 1, sizeof(int));
    
    for(int i = 0; i < N; i++){
        scanf("%d", &fila[i]);
    }
    
    printf("%d", fila[0]);
    visitado[fila[0]] = 1;
    
    for(int i = 1; i < N; i++){
        if(!visitado[fila[i]]){
            printf(" %d", fila[i]);
            visitado[fila[i]] = 1;
        }
    }
    printf("\n");

    free(fila);
    free(visitado);
    
    return 0;
}