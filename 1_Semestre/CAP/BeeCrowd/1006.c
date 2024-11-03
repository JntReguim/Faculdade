// Biblioteca
#include<stdio.h>
 
// Função main
int main(){
    // Definições locais
    double a, b, c;
    double media;
    
    // Entrada de dados
    scanf("%lf %lf %lf", &a, &b, &c);
    
    // Calculando a média
    media = (a*0.20) + (b*0.30) + (c*0.50);
    
    // Impressão do restuldado
    printf("MEDIA = %.1lf\n", media);
    
    return 0;
} // Fim da main