// Bibliotecas
#include<stdio.h>
#include<string.h>

// Variáveis globais
#define NUM_ALUNOS 5

// Estrura do Aluno
typedef struct{
    char nome[20];
    char sexo;
    int idade;
    int RA;
} Aluno;

// Definições locais
int main(){
    Aluno alunos[NUM_ALUNOS];
    int maior = 0;
    int soma = 0;

    // Entrada de dados
    for(int i = 0; i < NUM_ALUNOS; i++){
        printf("Digite o nome do aluno:");
        fgets(alunos[i].nome, 20, stdin);
        strtok(alunos[i].nome, "\n"); 

        printf("Digite o sexo do aluno:");
        scanf(" %c", &alunos[i].sexo);

        printf("Digite a idade do aluno:");
        scanf("%d", &alunos[i].idade);

        printf("Digite o RA do aluno:");
        scanf("%d", &alunos[i].RA);

        // Limpeza do buffer
        getchar();
    }
    
    // Encontrando aluno com maior idade
    for(int i = 0; i < NUM_ALUNOS; i++){
        if(alunos[i].idade > maior){
            maior = alunos[i].idade;
        }
    }
    
    // Imprimindo os alunos com maior idade
    printf("Aluno(s) com a maior idade:\n");
    for(int i = 0; i < NUM_ALUNOS; i++){
        if(alunos[i].idade == maior){
            printf("Nome: %s\nSexo: %c\nIdade: %d\nRA: %d\n\n", alunos[i].nome, alunos[i].sexo, alunos[i].idade, alunos[i].RA);
        }
    }
    
    // Calculando a média
    for(int i = 0; i < NUM_ALUNOS; i++){
        soma += alunos[i].idade;
    }

    double average = (double) soma / NUM_ALUNOS;
    
    // Imprimindo idade que são maiores que a média 
    printf("Aluno(s) com a idade maior que a media dentre eles:\n");
    for(int i = 0; i < NUM_ALUNOS; i++){
        if(alunos[i].idade > average){
            printf("Nome: %s\nSexo: %c\nIdade: %d\nRA: %d\n\n", alunos[i].nome, alunos[i].sexo, alunos[i].idade, alunos[i].RA);
        }
    }

    return 0;
} // Fim da main