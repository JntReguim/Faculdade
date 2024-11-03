// Biblioteca
#include<stdio.h>

// Funçõa principal
int main(){
    // Definições locais
    int n, i;
    int N[100];
    
    // Entrada de dados
    printf("Digite o número de sequências que deseja imprimir: ");
    scanf("%d", &n);
    
    // Atribuindo o valor de fib inicial
    N[0] = 0;
    N[1] = 1;
    
    // Impressão da sequência
    for(i = 2; i < n; i++){
        N[i] = N[i-1] + N[i-2];
        printf("0");
    }
    
    for(i = 1; i < n; i++){
        printf(" %d", N[i]);
    }
    
    // Pula linha
    printf("\n");
        
    return 0;
} //Fim da main

// Função recursiva 
int fib(int i){
    if(i <= 0){
        return 0;
    } 
    else if(i == 1){
        return 1;
    }
    else{
        return fib(i - 1) + fib(i - 2);
    }
}

// Função ain
int main(){
    // Definições locais
    int x;
    
    // Entrada de dados
    printf("Digite o valor de x para calcular o termo da sequência de Fibonacci: ");
    scanf("%d", &x);
    
    // Verificando a validade do dado de entrada
    if(x < 0){
        printf("x deve ser maior ou igual a 0.\n");
    } 
    
    // Impressão da sequência
    else{
        int resultado = fibonacci(x);
        printf("O %d termo da sequência de Fibonacci é: %d\n", x, resultado);
    }

    return 0;
} //Fim da main