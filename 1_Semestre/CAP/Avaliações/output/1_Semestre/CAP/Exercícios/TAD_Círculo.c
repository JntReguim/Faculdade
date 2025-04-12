// Bibliotecas
#include<stdio.h>
#include<math.h>

// Variável global
#define PI 3.14

// Estrutura do Ponto
typedef struct {
    double x;     // coordenada do eixo x
    double y;     // coordenada do eixo y
} tPonto;         // ponto no espaço Euclidiano bidimensional

// Estrutura do Círculo
typedef struct{
    tPonto centro;
    double raio;
} tCirculo;

// Protótipos
void leiaCirculo(tCirculo *);
void escrevaCirculo(tCirculo);
double areaCirculo(tCirculo c);
double perimetroCirculo(tCirculo c);
double distanciaCentroCirculos(tCirculo c1, tCirculo c2);
double distanciaMinimaCirculos(tCirculo c1, tCirculo c2);
void deslocaCirculo(tCirculo *c, double deltaX, double deltaY);

// Função main
int main(){
    // Declarações locais
    tCirculo circulo1;
    tCirculo circulo2;
  
    // Leitura de dados
    printf("Circulo 1\n");
    leiaCirculo(&circulo1);
    escrevaCirculo(circulo1);
  
    printf("Circulo 2\n");
    leiaCirculo(&circulo2);
    escrevaCirculo(circulo2);
  
    // Operações com círculo
    double area1 = areaCirculo(circulo1);
    printf("Area do circulo 1 = %.2lf\n", area1);
  
    double area2 = areaCirculo(circulo2);
    printf("Area do circulo 2 = %.2lf\n", area2);
  
    double perimetro1 = perimetroCirculo(circulo1);
    printf("Perimetro do circulo 1 = %.2lf\n", perimetro1);

    double perimetro2 = perimetroCirculo(circulo2);
    printf("Perimetro do circulo 2 = %.2lf\n", perimetro2);

    double distanciaRaios = distanciaCentroCirculos(circulo1, circulo2);
    printf("Distancia dos raios entre circulo1 e circulo2 = %.2lf\n", distanciaRaios);
  
    double distanciaMinima = distanciaMinimaCirculos(circulo1, circulo2);
    printf("Distancia mínima entre circulo1 e circulo2 = %.2lf\n", distanciaMinima);

    // Desloca o circulo1 por um valor de deslocamento
    double deltaX = 5.0;
    double deltaY = -2.0;
    deslocaCirculo(&circulo1, deltaX, deltaY);
    printf("Circulo 1 deslocado para (%.2lf, %.2lf)\n", circulo1.centro.x, circulo1.centro.y);
  
    return 0;
} // Fim da main

// Função para entrada de dados
void leiaCirculo(tCirculo *circulo){
  printf("Digite as coordenadas do circulo:\n");
  printf("Digite o valor da coordenada x: ");
  scanf("%lf", &circulo->centro.x);
  printf("Digite o valor da coordenada y: ");
  scanf("%lf", &circulo->centro.y);
  printf("Digite o valor do raio do circulo: ");
  scanf("%lf", &circulo->raio);
}

// Função para impressão de resultado
void escrevaCirculo(tCirculo c){
    printf("Dados do circulo:\n");
    printf("Coordenada x = %.2lf\n", c.centro.x);
    printf("Coordenada y = %.2lf\n", c.centro.y);
    printf("Raio = %.2lf\n", c.raio);
}

// Função para calcular a área
double areaCirculo(tCirculo c){
    return PI * c.raio * c.raio;
}

// Função para calcular o perimetro
double perimetroCirculo(tCirculo c){
    return 2.0 * PI * c.raio;
}

// Função para calcular distância entre os centros dos círculos
double distanciaCentroCirculos(tCirculo c1, tCirculo c2){
    double deltaX = c1.centro.x - c2.centro.x;
    double deltaY = c1.centro.y - c2.centro.y;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

// Função para calcular distância mínima entre os circulos
double distanciaMinimaCirculos(tCirculo c1, tCirculo c2){
    double distCentros = distanciaCentroCirculos(c1, c2);
    double somaRaios = c1.raio + c2.raio;
    
    // Se a distância entre os centros for maior ou igual à soma dos raios, os círculos não se intersectam
    if(distCentros >= somaRaios)
        return distCentros - somaRaios;
    
    // Caso contrário, eles se intersectam e a distância mínima é zero
    return 0.0;
}

// Função para deslocar o círculo
void deslocaCirculo(tCirculo *c, double deltaX, double deltaY){
    c->centro.x += deltaX;
    c->centro.y += deltaY;
}