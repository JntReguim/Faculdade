// Bibliotecas
#include<stdio.h>

// Função main
int main(){
  // Declarações locais
  int op;

  // Menu de opcoes
  printf("Escolha uma das opcoes abaixo:\n");
  printf("1. Inserir dados de um aluno\n");
  printf("2. Remover dados de um aluno\n");
  printf("3. Alterar dados de um aluno\n");
  printf("4. Buscar um aluno usando o RA\n");
  printf("5. Mostrar dados de todos os alunos\n");
  printf("6.Sair\n");

  // Leitura da opção
  scanf("%d", &op);

  // Identificar e mostrar a escolha feita
  switch(op){
    case 1:
      printf("Inserindo um aluno.");
      break;

    case 2:
      printf("Removendo um aluno");
      break;

    case 3:
      printf("Alterando dados de um aluno");
      break;

    case 4:
      printf("Buscando dados de um aluno");
      break;

    case 5:
      printf("Mostrando os dados de um aluno");
      break;

    case 6:
      printf("Saindo...");
      break;

    default:
      printf("Opcao Invalida.");
    }
    
  return 0;
} // Fim da main