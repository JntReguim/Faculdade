// Biblioteca
#include<stdio.h>
 
// Função main
int main(){
    // Definições locais
    int X = 60;     // Valor em Km/h do veículo X 
    int Y = 90;     // Valor em Km/h do veículo y
    int Km;         // Distância entre Y e X
    int min;        // Tempo, em minutos, para Y ser = X + Km;
        
    // Entrada de dados
    scanf("%d", &Km);
    
    // Calculo para descobrir o tempo para Y ser X + Km;
    min = Km * 2;  // Vezes 2, pois data as velocidades constante, a cada dois minutos Y aumenta 1Km em relação a X
    
    // Impressão do resultado
    printf("%d minutos\n", min);
    
    return 0;
} // Fim da main