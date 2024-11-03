// Biblioteca
#include<stdio.h>
 
// Estrutura de Calculo
typedef struct{
    double A;
    double B;
    double C;
    double area;
    double pi;
 } tCalculo;

// Função main
int main(){
    tCalculo Calculo;
    Calculo.pi = 3.14159;
    
    scanf("%lf %lf %lf", &Calculo.A, &Calculo.B, &Calculo.C);
    
    // Triângulo
    Calculo.area = Calculo.A * Calculo.C / 2;
    printf("TRIANGULO: %.3lf\n", Calculo.area);
    
    // Circulo
    Calculo.area = Calculo.pi * (Calculo.C * Calculo.C);
    printf("CIRCULO: %.3lf\n", Calculo.area);
    
    //Trapézio
    Calculo.area = (Calculo.A + Calculo.B) * Calculo.C / 2;
    printf("TRAPEZIO: %.3lf\n", Calculo.area);
    
    //Quadrado
    Calculo.area = Calculo.B * Calculo.B;
    printf("QUADRADO: %.3lf\n", Calculo.area);
    
    //Retângulo
    Calculo.area = Calculo.A * Calculo.B;
    printf("RETANGULO: %.3lf\n", Calculo.area);

    return 0;
} // Fim da main