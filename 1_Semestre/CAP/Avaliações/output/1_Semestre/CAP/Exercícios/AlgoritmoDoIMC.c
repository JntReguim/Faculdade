// Bibliotecas
#include<stdio.h>

// Função main
int main(){
    // Declarações locais
    float peso;
    float altura;

    // Entrada de dados
    printf("Digite seu peso: ");
    scanf("%f", &peso);
    printf("Digite sua altura: ");
    scanf("%f", &altura);

    // Calcula IMC
    float imc = peso / (altura * altura);

    // Imprime IMC e sua respectiva classificação
    printf("Seu IMC: %.2f\n", imc);

    if(imc < 16.9){
        printf("Classificacao: Muito abaixo do peso!");
    }
    else if(imc < 18.4){
        printf("Classificacao: Abaixo do peso!");
    }
    else if(imc < 24.9){
        printf("Classificacao: Peso normal!");
    }
    else if(imc < 29.9){
        printf("Classificacao: Acima do peso!");
    }
    else if(imc < 34.9){
        printf("Classificacao: Obsidade Grau I!");
    }
    else if(imc < 40){
        printf("Classificacao: Obsidade Grau II!");
    }
    else{
        printf("Classificacao: Obsidade Grau III!");
    }

    return 0;
} // Fim damain