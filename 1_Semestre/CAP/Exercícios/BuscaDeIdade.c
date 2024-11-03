// Bibliotecas
#include<stdio.h>

// Variável global
#define MAX_ALUNOS 100

// Função main
int main(){
    // Definições locais
    int idades[MAX_ALUNOS];
    int numAlunos, idadeBusca, encontrou = 0;

    do{
        printf("Informe o numero de alunos (limite de 100): ");
        scanf("%d", &numAlunos);

        if(numAlunos > MAX_ALUNOS){
            printf("O numero de alunos informado excede o limite de 100.\n");
        }

    } while (numAlunos > MAX_ALUNOS);

    printf("Informe as idades dos alunos:\n");
    for(int i = 0; i < numAlunos; i++){
        printf("Idade do aluno %d: ", i + 1);
        scanf("%d", &idades[i]);
    }

    printf("Informe a idade a ser buscada: ");
    scanf("%d", &idadeBusca);

    // Busca pela idade no vetor
    for(int i = 0; i < numAlunos; i++){
        if(idades[i] == idadeBusca){
            encontrou = 1;
            break;                      // Se encontrar a idade, finaliza o programa.
        }
    }

    // impressão de resultado
    if(encontrou){
        printf("A turma possui um, ou mais, aluno(s) com %d anos.\n", idadeBusca);
    } 
    else{
        printf("A turma nao possui um aluno com %d anos.\n", idadeBusca);
    }

    return 0;
} // Fim da main