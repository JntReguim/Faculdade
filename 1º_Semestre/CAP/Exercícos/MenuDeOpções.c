// Arquivos de cabeçalho
#include <stdio.h>

// Função main
int main(){
    // Declarações locais
    int op;

    // Menu de opções
    printf("Escolha uma das opcoes abaixo:\n");
    printf("1. Inserir dados de um aluno\n");
    printf("2. Remover dados de um aluno\n");
    printf("3. Alterar dados de um aluno\n");
    printf("4. Buscar um aluno usando o RA\n");
    printf("5. Mostrar dados de todos os alunos\n");
    printf("6.Sair\n");

    // Entrada da opção desejada
    scanf("%d", &op);

    // Identificar e mostrar a escolha feita
    switch(op){
        case 1:
            printf("Inserindo um aluno...\n");
            break;

        case 2:
            printf("Removendo um aluno...\n");
            break;

        case 3:
            printf("Alterando dados de um aluno...\n");
            break;

        case 4:
            printf("Buscando dados de um aluno...\n");
            break;

        case 5:
            printf("Mostrando os dados de um aluno...\n");
            break;

        case 6:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao Invalida!\n");
    }

    return 0;
} // Fim da main