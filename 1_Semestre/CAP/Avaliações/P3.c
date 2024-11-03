// Nome: Jonatã Aparecido Reguim
// RA: 824754

// Bibliotecas
#include<stdio.h>

// Estrutura do Tabuleiro
typedef struct{
    unsigned int N;
    unsigned int total;
    unsigned int brancas;
    unsigned int pretas;
} tTabuleiro;

// Protótipo
void calculaCasas(tTabuleiro *tab);

// BeeCrowd 3342
int main(){
    // Declaração local
    tTabuleiro tab;

    // Chamando a subrotina para calcular as casas
    calculaCasas(&tab);

    // Impressão do resultado
    printf("%u casas brancas e %u casas pretas\n", tab.brancas, tab.pretas);
    
    return 0;
}

// Função para calcular a quantidade de casas pretas e brancas em um tabuleiro de xadrez
void calculaCasas(tTabuleiro *tab) {
    // Entrada de dados: Lê o tamanho do tabuleiro
    scanf("%u", &tab->N);

    // Calculando o total de casas no tabuleiro
    tab->total = tab->N * tab->N;

    // Calculando a quantidade de casas pretas e brancas
    tab->pretas = tab->total / 2;
    tab->brancas = tab->total - tab->pretas;
}

/*
// BeeCrowd 3299
// Protótipo
void maSorte(long long int N, int *sorte);

int main(){
    // Declarações locais
    long long int N;
    int sorte = 0;
    
    // Entrada de dados
    scanf("%llu", &N);
    
    // Chama sub rotina
    maSorte(N, &sorte);
    
    // Impressão de resultado
    if (sorte == 1){
        printf("%llu es de Mala Suerte\n", N);
    }
    else{
        printf("%llu NO es de Mala Suerte\n", N);
    }

    return 0;
}

// Função para encontrar ou não um "13" na sequência de números
void maSorte(long long int N, int *sorte){
    // Loop de divisão para encontrar, ou não, número 13.
    while(N > 0){
        int r = N % 10;
        if(r == 3 && (N/10) % 10 == 1){
            *sorte = 1;
            break;
        }
        N /= 10;
    }
}
*/