// arquivos de cabeçalho
#include <stdio.h>

// Declarações globais
#define MAX_T 10

// Função main
int main(){
    // Declarções locais
    float p1, p2, p3;       // Notas da 3 avaliações
    float trab[MAX_T];      // Vetor com notas dos trabalhos
    float tmedia = 0;       // Média dos trabalhos
    float media = 0;        // Média final

    // Entrada de dados
    printf("Digite a notas das provas p1, p2, p3, nesta ordem!\n");
    scanf("%f %f %f", &p1, &p2, &p3);
    printf("Digite as notas dos trabalhos de t1 a t10, nesta ordem!\n");
    for(int i=0; i < MAX_T; i++){
        scanf("%f", &trab[i]);
    }

    // Calculando média do aluno
    for(int i=0; i < MAX_T; i++){
        tmedia += trab[i];
    }
    tmedia = tmedia / MAX_T;

    media = (p1 * 0.25) + (p2 * 0.25) + (p3 * 0.30) + (tmedia * 0.20);

    // Impressão de resultado
    printf("MediaFinal: %.2f", media);

    return 0;
} // Fim da main