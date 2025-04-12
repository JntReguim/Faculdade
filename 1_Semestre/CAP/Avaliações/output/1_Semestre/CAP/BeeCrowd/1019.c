// Biblioteca
#include<stdio.h>
 
// Função main
int main(){
    int N; // N em segundos, sendo a entrada
    int H=0; // H = horas
    int M=0; // M = minutos
    int S=0; // S = segundos
    scanf("%d", &N);
  
    // conversão
    H = N / 3600;
    N = N % 3600;
    M = N / 60;
    N = N % 60;
    
    
    // imprimir horas:minutos:segundos
    printf("%d:%d:%d\n", H, M, N);
    
    return 0;
} // Fim da main