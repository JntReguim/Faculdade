// Arquivos de cabeçalho
#include <stdio.h>

// Função main
int main(){
    // Declarações locias
    int numAlunos = 50;
    int idades[numAlunos];
    int maior;
    int media;
    int count = 0;
    int somaIdade = 0;

    do{
        // Entrada do n de alunos
        printf("Digite a quantidade de alunos:\n");
        scanf("%d", &numAlunos);

        // Verifcando quantidade de entrada
        if(numAlunos < 1 || numAlunos > 50){
            printf("ERRO!\n");
            printf("Valores validos estao entre 1 e 50!\n");
        }
        else{
            break;
        }

    } while(1);

    // Entrada de dados
    printf("Digite as %d idades:\n", numAlunos);
    for(int i=0; i < numAlunos; i++){
        scanf("%d", &idades[i]);
        somaIdade += idades[i];
    }

    // Encontra maior idade
    maior = idades[0];
    for(int i=0; i < numAlunos; i++){
        if(idades[i] > maior){
            maior = idades[i];
        }
    }

    // Calcula média das idades
    media = somaIdade / numAlunos;

    // Calcula quantos alunos tem a idade maior que a média
    for(int i=0; i < numAlunos; i++){
        if(idades[i] >= media){
            count++;
        }
    }

    // Impressão de resultado
    printf("Maior idade: %d\n", maior);
    printf("Alunos com idade acima da media: %d\n", count);

    return 0;
} // Fim da main