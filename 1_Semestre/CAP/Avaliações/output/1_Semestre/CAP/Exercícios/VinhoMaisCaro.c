// Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Variável global
#define MAX_NOME 50

// Estrutura do Vinho
typedef struct{
    char nome[MAX_NOME];
    float preco;
    char tipo;
} Vinho;

// Função main
int main(){
    // Declarações locais
    Vinho vinhoMaisCaro;
    Vinho vinhoAtual;
    char nomeFim[] = "FIM";
    int primeiroVinho = 1;
    
    printf("Digite o nome, o preco (R$) e o tipo do vinho (T para tinto, B para branco e R para rose):\n");
    
    // Variante
    while(1){
        printf("Nome: ");
        scanf("%s", vinhoAtual.nome);
        
        if(strcmp(vinhoAtual.nome, nomeFim) == 0){
            break;
        }

        printf("Preco (R$): ");
        scanf("%f", &vinhoAtual.preco);
        
        printf("Tipo (T para tinto, B para branco e R para rose): ");
        scanf(" %c", &vinhoAtual.tipo);
        
        if(primeiroVinho || vinhoAtual.preco > vinhoMaisCaro.preco){
            strcpy(vinhoMaisCaro.nome, vinhoAtual.nome);
            vinhoMaisCaro.preco = vinhoAtual.preco;
            vinhoMaisCaro.tipo = vinhoAtual.tipo;
            primeiroVinho = 0;
        }
    }
    
    // Impressão de resultado
    printf("\nDados do vinho mais caro:\n");
    printf("Nome: %s\n", vinhoMaisCaro.nome);
    printf("Preco (R$): %.2f\n", vinhoMaisCaro.preco);
    printf("Tipo: %c\n", vinhoMaisCaro.tipo);
    
    return 0;
} // Fim da main