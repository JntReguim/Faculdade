// Biblioteca
#include<stdio.h>

// loop
int mdcIterativo(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

// Recursivo
int mdcRecursivo(int a, int b){
    if(b == 0){
        return a;
    }

    return mdcRecursivo(b, a % b);
}

// Função main
int main(){
    // Definições locais
    int num1, num2;
    
    // Entrada de dados
    printf("Digite dois numeros inteiros:\n");
    scanf("%d %d", &num1, &num2);
    
    // Atribuindo mdc em resultado
    int resultado = mdcIterativo(num1, num2);
    
    // Imprimindo resultado
    printf("O MDC de %d e %d eh: %d\n", num1, num2, resultado);

    return 0;
} // Fim da main