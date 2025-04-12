// Biblioteca
#include<stdio.h>
 
// Função main
int main(){
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int E = 0;
    int F = 0;
    int X;
    
    scanf(" %d", &X);
    printf("%d\n", X);
    
    A = X / 100;
    X = X % 100;
    printf("%d nota(s) de R$ 100,00\n", A);
    
    B = X / 50;
    X = X % 50;
    printf("%d nota(s) de R$ 50,00\n", B);
    
    C = X / 20;
    X = X % 20;
    printf("%d nota(s) de R$ 20,00\n", C);
    
    D = X / 10;
    X = X % 10;
    printf("%d nota(s) de R$ 10,00\n", D);
    
    E = X / 5;
    X = X % 5;
    printf("%d nota(s) de R$ 5,00\n", E);
    
    F = X / 2;
    X = X % 2;
    printf("%d nota(s) de R$ 2,00\n", F);
    
    printf("%d nota(s) de R$ 1,00\n", X);
    
    return 0;
} // Fim da main