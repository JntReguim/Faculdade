// Biblioteca
#include<stdio.h>
 
// Função main
int main(){
    // Definições locais
    int num;      // Número do funcionário
    int h;        // Horas trabalhadas
    double hS;    // Ganho por hora trabalhada
    double sal;   // Salário
    
    // Entrada de dados
    scanf("%d %d %lf", &num, &h, &hS);
    
    // Calculando o salário
    sal = hS * h;
    
    // Impressão do restuldado
    printf("NUMBER = %d\n", num);
    printf("SALARY = U$ %.2lf\n", sal);

    return 0;
} // Fim da main