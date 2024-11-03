// Biblioteca
#include<stdio.h>
 
// Função main
int main(){
    int X;
    int Ano;
    int Mes;
    
    scanf("%d", &X);
    
    Ano = X / 365;
    X = X % 365;
    printf("%d ano(s)\n", Ano);
    
    Mes = X / 30;
    X = X % 30;
    printf("%d mes(es)\n", Mes);
    
    printf("%d dia(s)\n", X);
    
    return 0;
} // Fim da main