// Biblioteca
#include<stdio.h>
 
// Função main
int main(){
    // Definições locais
    int cod1, cod2;  // Código da peça 1 e 2 
    int qtd1, qtd2;  // Quantidade de peças 1 e 2
    double p1, p2;   // Preço da peça 1 e 2
    double pF;       // Preço final
    
    // Entrada de dados
    scanf("%d %d %lf", &cod1, &qtd1, &p1);
    scanf("%d %d %lf", &cod2, &qtd2, &p2);
    
    // Calculo do preço final
    pF = (qtd1 * p1) + (qtd2 * p2);
    
    // Impressão do resultado
    printf("VALOR A PAGAR: R$ %.2lf\n", pF);
    
    return 0;
} // Fim da main