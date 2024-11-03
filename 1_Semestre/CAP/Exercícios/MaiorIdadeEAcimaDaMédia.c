// Bibliotecas
#include<stdio.h>
#include<stdlib.h>

// Função main
int main(){
    // Declarações locais
    int MAX_ALUNOS = 50; // Número máximo de alunos
    int nDeAlunos;
    int somaIdades = 0;
    float media;
    
    do{
        printf("Digite o numero de alunos (n): ");
        scanf("%d", &nDeAlunos);
        
        if(nDeAlunos < 1 || nDeAlunos > MAX_ALUNOS){
            printf("Numero de alunos invalido!\n");
            printf("O numero de alunos deve estar entre 1 e %d.", MAX_ALUNOS);
            printf("Tente novamente.\n");
        }

    } while(nDeAlunos < 1 || nDeAlunos > MAX_ALUNOS);
    
    int idades[nDeAlunos];
    
    printf("Digite as idades dos alunos:\n");
    for(int i = 0; i < nDeAlunos; i++){
        scanf("%d", &idades[i]);
        somaIdades += idades[i];
    }
    
    media = (float)somaIdades / nDeAlunos;
    
    printf("A media das idades eh: %.2f\n", media);
    printf("Alunos com idade acima da media:\n");

    for(int i = 0; i < nDeAlunos; i++){
        if(idades[i] > media){
            printf("Aluno %d: %d anos\n", i+1, idades[i]);
        }
    }
    
    return 0;
} // Fim da mian