// Biblioteca
#include<stdio.h>
 
// Função main
int main(){
    // Declarações locais
    int a, b, c, d;
    int somaCD = 0;
    int somaAB = 0;
    
    // Entrada de dados
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // Calculo inicial
    somaAB = a + b;
    somaCD = c + d;
    
    // Verificando condições
    if(b > c && d > a && somaCD > somaAB && c > 0 && d > 0 && a % 2 == 0){
        printf("Valores aceitos\n");
    }
    else{
        printf("Valores nao aceitos\n");
    }
    
    return 0;
} // Fim da main