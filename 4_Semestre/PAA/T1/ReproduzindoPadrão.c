#include <stdio.h>

void imprime(int n){
    if(n == 0){
        return;
    }

    imprime(n-1);

    for(int i=0; i < n; i++){
        printf("-");
    }
    printf("\n");

    imprime(n-1);
}

int main(){
    int n;

    scanf("%d", &n);

    imprime(n);

    return 0;
}