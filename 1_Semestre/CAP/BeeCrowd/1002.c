// Biblioteca
#include<stdio.h>

// Variável global
#define PI 3.14159
 
// Função main
int main(){
    double raio, area;

    scanf("%lf", &raio);

    area = PI * raio * raio;

    printf("A=%.4lf\n", area);

    return 0;
} // Fim da main