/*
Nome completo: Jonatã Aparecido Reguim
RA: 824754

Objetivo: Faça um programa na linguagem C que resolva o seguinte problema. Calcule 
e mostre na tela do computador o menor e o maior valor dentre 5 números inteiros.
*/

// Bibliotecas
#include<stdio.h>

// Função principal
int main(){
    // Definições locais
    int x[5];
    int maior;
    int menor;
    
    // Entrada de dados
    printf("Digite 5 números e apresentarei o maior e menor dentre eles!\n");
    for(int i=0; i<5; i++){
       scanf("%d", &x[i]);
    }
    
    // Encontrando o maior valor
    maior = x[0];              // Maior inicia com o valor inicial x[0] 
    for(int i=0; i<5; i++){
        if(maior < x[i]){      // Caso menor seja maior que x[i]
            maior = x[i];      // Maior recebe x[i]
        }
    }
    
    // Impressão do maior valor
    printf("O maior número é: %d\n", maior);
    
    // Encontrando o menor valor
    menor = x[0];              // Menor inicia com o valor inicial x[0]
    
    for(int i=0; i<5; i++){
        if(menor > x[i]){      // Caso menor seja maior que x[i]
            menor = x[i];      // Menor recebe x[i]
        }
    }
    
    // Impressão do menor valor
    printf("O menor número é: %d\n", menor);
    
    return 0;
} // Fim da main