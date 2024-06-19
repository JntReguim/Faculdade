// Arquivos de cabeçalho
#include <stdio.h>
#include <math.h>

// Declarações globais
#define pi 3.14

// Registros
typedef struct{
    double  x;
    double  y;
} tPonto;

typedef struct{
    tPonto centro;
    double raio;
} tCirculo;

// Protótipos
void leCirculo(tCirculo *c);
void imprimeCirculo(tCirculo c);
double areaCirculo(tCirculo c);
double perimetroCirculo(tCirculo c);
double distanciaCentroCirculos(tCirculo c1, tCirculo c2);
double distanciaMinimaCirculos(tCirculo c1, tCirculo c2);
void deslocaCirculo(tCirculo *c, double x, double y);

// Função main
int main(){
    // Declarações locais
    tCirculo c1;
    tCirculo c2;

    // Utilizando sub rotinas
    // Entrada de dados
    leCirculo(&c1);
    imprimeCirculo(c1);
    leCirculo(&c2);
    imprimeCirculo(c2);

    // Calculo da área
    double area = areaCirculo(c1);
    printf("Area Criculo1: %.2lf\n", area);
    area = areaCirculo(c2);
    printf("Area Criculo2: %.2lf\n", area);

    // Calculando perímetro
    double perimetro = areaCirculo(c1);
    printf("Area Criculo1: %.2lf\n", perimetro);
    perimetro = areaCirculo(c2);
    printf("Area Criculo2: %.2lf\n", perimetro);

    // Calcula distância entre os dois círculos
    double dist = distanciaCentroCirculos(c1, c2);
    printf("Distancia entre os circulos: %.2lf\n", dist);

    // Calcula menor distância entre os círculos
    dist = distanciaMinimaCirculos(c1, c2);
    printf("Menor distancia entre os circulos: %.2lf\n\n", dist);

    // Desloca círculo
    double x, y;

    while(1){
        printf("Digite valores para deslocar o circulo1 (Digite '0' para sair)!\n");
        printf("Digite o valor de x: ");
        scanf("%lf", &x); 

        if(x == 0){
            break;
        } 

        printf("Digite o valor de y: ");
        scanf("%lf", &y);

        deslocaCirculo(&c1, x, y);
        imprimeCirculo(c1); 
    }

    while(1){
        printf("Digite valores para deslocar o circulo2 (Digite '0' para sair)!\n");
        printf("Digite o valor de x: ");
        scanf("%lf", &x); 

        if(x == 0){
            break;
        } 

        printf("Digite o valor de y: ");
        scanf("%lf", &y);

        deslocaCirculo(&c2, x, y);
        imprimeCirculo(c2); 
    }

    return 0;
} // Fim da main

// Sub Rotinas
// Entrada de dados
void leCirculo(tCirculo *c){
    printf("Digite o valor do ponto x: ");
    scanf("%lf", &c->centro.x);
    printf("Digite o valor do ponto y: ");
    scanf("%lf", &c->centro.y);
    printf("Digite o valor do raio: ");
    scanf("%lf", &c->raio);
}

// Imprime informações do círculo
void imprimeCirculo(tCirculo c){
    printf("Ponto x: %2.lf\n", c.centro.x);
    printf("Ponto y: %2.lf\n", c.centro.y);
    printf("Raio: %.2lf\n", c.raio);
}

// Calcula área do círculo
double areaCirculo(tCirculo c){
    return (pow(c.raio, 2) * pi); 
}

// Calcula perímetro do círculo
double perimetroCirculo(tCirculo c){
    return (c.raio * pi * 2);
}

// Calcula a distância entre os dois centros (Distância entre dois pontos)
double distanciaCentroCirculos(tCirculo c1, tCirculo c2){
    double deltaX = (c1.centro.x - c2.centro.x);
    double deltaY = (c1.centro.y - c2.centro.y);
    return (sqrt(pow(deltaX, 2) + pow(deltaY, 2)));
}

// Calcula a distância mínima entre dois pontos
double distanciaMinimaCirculos(tCirculo c1, tCirculo c2){
    double distCentros = distanciaCentroCirculos(c1, c2);
    double somaRaios = c1.raio + c2.raio;
    
    // Se a distância entre os centros for maior ou igual à soma dos raios, os círculos não se intersectam
    if(distCentros >= somaRaios)
        return distCentros - somaRaios;
    
    // Caso contrário, eles se intersectam e a distância mínima é zero
    return 0.0;
}

// Desloca o centro do círculo
void deslocaCirculo(tCirculo *c, double x, double y){
    c->centro.x += x;
    c->centro.y += y;
}