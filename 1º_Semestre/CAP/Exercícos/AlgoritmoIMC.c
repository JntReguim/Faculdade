// Arquivos de cabeçalho
#include <stdio.h>

// Função main
int main(){
    // Declarações locais
    float peso;
    float altura;
    float imc;

    // Coletando informações
    printf("Digite seu peso:\n");
    scanf("%f", &peso);
    printf("Digite sua Altura em metros(m)! Ex: 1.75\n");
    scanf("%f", &altura);

    // Cálculo do IMC (Índice de Massa Corporal)
    imc = peso / (altura * altura);

    // Impressão de resultado
    printf("Seu IMC: %.2f", imc);

    return 0;
} // Fim da main