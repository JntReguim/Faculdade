// arquivos de cabeçalho
#include <stdio.h>

// Declarações globais
#define MAX_T 10

// Função main
int main(){
    // Declarções locais
    float p1, p2, p3;       // Notas da 3 avaliações
    float trab[MAX_T];      // Vetor com notas dos trabalhos
    int freq;             // Frequência do aluno
    float tmedia = 0;       // Média dos trabalhos
    float media = 0;        // Média final

    // Entrada de dados
    printf("Digite a notas das provas p1, p2, p3, nesta ordem!\n");
    scanf("%f %f %f", &p1, &p2, &p3);
    printf("Digite as notas dos trabalhos de t1 a t10, nesta ordem!\n");
    for(int i=0; i < MAX_T; i++){
        scanf("%f", &trab[i]);
    }
    printf("Digite a frequencia do aluno:\n");
    scanf("%d", &freq);

    // Calculando média do aluno
    for(int i=0; i < MAX_T; i++){
        tmedia += trab[i];
    }
    tmedia = tmedia / MAX_T;

    media = (p1 * 0.25) + (p2 * 0.25) + (p3 * 0.30) + (tmedia * 0.20);

   // Verificando situação final
   if(media >= 6 && freq >= 75){
    printf("Aluno aprovado!\n");
    printf("NotaFinal: %.2f\n", media);
    printf("Frequencia: %d\n", freq);
   }
   else if(media >= 5 && freq >= 75){
    printf("Aluno Recuperacao!\n");
    printf("NotaFinal: %.2f\n", media);
    printf("Frequencia: %d\n", freq);
   }
   else{
    printf("Aluno Reprovado!\n");
    printf("NotaFinal: %.2f\n", media);
    printf("Frequencia: %d\n", freq);
   }

    return 0;
} // Fim da main