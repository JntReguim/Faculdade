// Arquivos de cabeçalho
#include <stdio.h>
#include <stdbool.h>

// Declarações globais
#define MAX_A 5

// Função main
int main(){
    // Declarações locais
    int alunos[MAX_A];
    int busca;
    bool existe = 0;

    // Entrada de dados
    for(int i=0; i < MAX_A; i++){
        printf("Digite a idade do aluno %d: ", i+1);
        scanf("%d", &alunos[i]);
    }

    // Entrada do valor de busca
    printf("Digite a idade que deseja buscar: ");
    scanf("%d", &busca);

    // Busca com base na chave de busca passada pelo usuário
    for(int i=0; i < MAX_A; i++){
        if(alunos[i] == busca){
            existe = 1;
            break;
        }
    }

    if(existe){
        printf("Existe pelo menos um aluno com esta idade!\n");
    } else{
        printf("Não existe nehum aluno com esta idade!\n");
    }

    return 0;
} // Fim da main