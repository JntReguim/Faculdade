// Arquivos de cabeçalho
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Protótipos
int contar_vogais(char *nome);

// Função main
int main(){
    // Declarações locais
    char nome[50];

    // Variável de laço
    printf("Digite os nomes dos alunos (digite 'Palmeiras' para parar):\n");
    while (1) {
        scanf(" %s", nome);
        if (strcasecmp(nome, "Palmeiras") == 0){                              // Quando letras a diferença ent maiúsculas e minúsculas não importa usar strcasecomp em vez de strcmp 
            break;
        }
        printf("O nome '%s' tem %d vogais.\n", nome, contar_vogais(nome));
    }

    return 0;
} // Fim da main

// Sub-rotinas
int contar_vogais(char *nome){
    int cont = 0;
    while (*nome) {
        char letra = tolower(*nome);                                                            // 'tolower' Força letras maiúsculas virarem minúsculas
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
            cont++;
        }
        nome++;
    }
    return cont;
}