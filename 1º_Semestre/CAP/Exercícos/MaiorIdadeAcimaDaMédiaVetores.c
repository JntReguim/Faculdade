// Arquivos de cabeçalho
#include <stdio.h>

// Registro
typedef struct{
    int RA;
    int idade;
    char sexo;
} tAluno;

// Função main
int main(){
    // Declarações locais
    int numAlunos = 100;
    tAluno Aluno[numAlunos];
    int somaIdade = 0;
    int maior = 0;
    int media;

    do{
        // Coletando número de alunos
        printf("Digite o numero de alunos!\n");
        scanf("%d", &numAlunos);

        // Verifica se o número de alunos é válida
        if(numAlunos < 1 || numAlunos > 100){
            printf("ERRO!\n");
            printf("Valores validos entre 1 e 100!\n");
        }else{
            break;  // Finaliza laço
        }

    } while(1);

    // Entrada de dados
    for(int i=0; i < numAlunos; i++){
        printf("Digite o RA: ");
        scanf("%d", &Aluno[i].RA);

        printf("Digite a idade: ");
        scanf("%d", &Aluno[i].idade);
        somaIdade += Aluno[i].idade;

        printf("Digite o sexo (F/M): ");
        scanf(" %c", &Aluno[i].sexo);

        // Encontrando maior idade entre os alunos
        if(Aluno[i].idade > maior){
            maior = Aluno[i].idade;
        }
    }

    // Imprimindo alunos com maior idade
    for(int i=0; i < numAlunos; i++){
        if(Aluno[i].idade == maior){
            printf("Aluno(s) com maior idade:\n");
            printf("RA: %d\n", Aluno[i].RA);
            printf("Idade: %d\n", Aluno[i].idade);
            printf("Sexo: %c\n", Aluno[i].sexo);
        }
    }

    // Calculando a média das idades
    media = somaIdade / numAlunos;
    
    // Imprimindo alunos com idade acima da média
    for(int i=0; i < numAlunos; i++){
        if(Aluno[i].idade >= media){
            printf("Alunos com idade acima da media:\n");
            printf("RA: %d\n", Aluno[i].RA);
            printf("Idade: %d\n", Aluno[i].idade);
            printf("Sexo: %c\n", Aluno[i].sexo);
        }
    }

    return 0;
} // Fim da main