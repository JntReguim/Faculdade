// Bibliotecas
#include<stdio.h>

// Estrutura Aluno
struct Aluno{
    int ra;
    char sexo; // masc ou fem
    int idade;
};

// Função main
int main(){
    // Declarações locais
    int numAlunos;

    // Recebe num de alunos
    printf("Informe o numero de alunos: ");
    scanf("%d", &numAlunos);

    struct Aluno alunos[numAlunos];
    int maiorIdade = 0, contMaiorIdade = 0, somaIdades = 0;
    float mediaIdades;

    // Entrada de dados
    printf("Informe os dados dos alunos:\n");

    for(int i = 0; i < numAlunos; i++){
        printf("Aluno %d:\n", i + 1);
        printf("RA: ");
        scanf("%d", &alunos[i].ra);
        printf("Sexo (M/F): ");
        scanf(" %c", &alunos[i].sexo);
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        printf("\n");

        // Verifica maior idade
        if(alunos[i].idade > maiorIdade){
            maiorIdade = alunos[i].idade;
        }

        // Soma das idades
        somaIdades += alunos[i].idade;
    }

    // Cálculo da média de idades
    mediaIdades = (float)somaIdades / numAlunos;

    // Saída de dados
    printf("\nMaior idade: %d\n", maiorIdade);
    printf("Alunos com maior idade:\n");

    for(int i = 0; i < numAlunos; i++){
        if(alunos[i].idade == maiorIdade){
            printf("RA: %d, Sexo: %c\n", alunos[i].ra, alunos[i].sexo);
        }

        // Contagem de alunos com idade maior que a média
        if(alunos[i].idade > mediaIdades){
            contMaiorIdade++;
        }
    }
    
    //Impressão de resultado
    printf("\nQuantidade de alunos com idade maior que a media: %d\n", contMaiorIdade);
    printf("Alunos com idade maior que a media:\n");

    for(int i = 0; i < numAlunos; i++){
        if(alunos[i].idade > mediaIdades){
            printf("RA: %d, Sexo: %c\n", alunos[i].ra, alunos[i].sexo);
        }
    }

    return 0;
} // Fim da main