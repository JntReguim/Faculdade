// Arquivos de cabeçalho
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarações globais
#define MAX_N 100

// Registro
typedef struct{
    char nome[MAX_N];
    float preco;
    char tipo;
} Vinho;

// Função main
int main(){
    // Declarações locais
    Vinho MaisCaro;
    Vinho Atual;
    char fim[] = "FIM";
    int VinhoInicial = 1;

    // Entrada de dados
    printf("Digite o nome, o preco (R$) e o tipo do vinho (T para tinto, B para branco e R para rose):\n");

    // Variável de laço
    while(1){
        printf("Digite o nome:\n");
        scanf("%s", Atual.nome);

        // Verificando possível quebra de laço
        if(strcmp(Atual.nome, fim) == 0){
            break;      // Finaliza laço
        }

        printf("Digite o preco:\n");
        scanf("%f", &Atual.preco);
        printf("Digite o tipo:\n");
        scanf(" %c", &Atual.tipo);

        if(VinhoInicial || Atual.preco > MaisCaro.preco){
            // Pasando dados do VinhoAtual para VinhoMaisCaro
            strcpy(MaisCaro.nome, Atual.nome);
            MaisCaro.preco = Atual.preco;
            MaisCaro.tipo = Atual.tipo;

            // Finalizando primeira entrada de dados
            VinhoInicial = 0;
        }
    }

    // Impressão de resultado
    printf("Informacoes do Vinho mais caro:\n");
    printf("Nome: %s\n", MaisCaro.nome);
    printf("Preco: %.2f\n", MaisCaro.preco);
    printf("Tipo: %c\n", MaisCaro.tipo);

    return 0;
} // Fim da main