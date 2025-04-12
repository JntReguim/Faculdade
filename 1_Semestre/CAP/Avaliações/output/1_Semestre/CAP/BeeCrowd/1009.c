// Biblioteca
#include<stdio.h>
 
// Função main
int main(){
    // Definições locais
    char nome[30];   // Nome do vendedor
    double sal;      // Salário fixo
    double vendas;   // Total de vendas em R$
    double salF;     // Salário final (Salário fixo + 15% sobre a vendas do mês)
    int i;
    
    // Entrada de dados
    scanf("%s", &nome[i]);
    scanf("%lf %lf", &sal, &vendas);
    
    // Calculo do salário final
    salF = sal + (vendas * 0.15);
    
    // Impressão do resultado
    printf("TOTAL = R$ %.2lf\n", salF);
    
    return 0;
} // Fim da main