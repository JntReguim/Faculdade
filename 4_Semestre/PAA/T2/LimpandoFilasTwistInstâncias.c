#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000000

int main(){
    int N;
    scanf("%d", &N);

    int *array = (int *)malloc(N * sizeof(int));
    int *ult_ocor = (int *)calloc(MAX, sizeof(int));
    bool *impresso = (bool *)calloc(MAX, sizeof(bool));

    for(int i = 0; i < N; i++){
        scanf("%d", &array[i]);
        ult_ocor[array[i]] = i;
    }

    bool first = true;
    for(int i = 0; i < N; i++){
        if(!impresso[array[i]] && ult_ocor[array[i]] == i){
            if(!first){
                printf(" ");
            }
            printf("%d", array[i]);

            impresso[array[i]] = true;
            first = false;
        }
    }
    printf("\n");

    free(array);
    free(ult_ocor);
    free(impresso);

    return 0;
}