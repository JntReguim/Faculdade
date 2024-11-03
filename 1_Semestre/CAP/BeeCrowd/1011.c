// Biblioteca
#include<stdio.h>

// Estrutura da Esfera
typedef struct{
    double volume;
    double pi;
    double raio;
} tEsfera;
 
// Função main
int main(){
    tEsfera Esfera;
    Esfera.pi = 3.14159;
    scanf("%lf", &Esfera.raio);
    Esfera.volume = Esfera.pi * (Esfera.raio * Esfera.raio * Esfera.raio) * 4 / 3;
    printf("VOLUME = %.3lf\n", Esfera.volume);
    
    return 0;
} // Fim da main