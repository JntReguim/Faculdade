// Bibliotecas
#include<stdio.h>

// Função main
int main(){
    // Declarações locais
    int trab[10];
    int somat = 0;
    int provas[3];

    // Loop que coleta notas das provas
    for(int i=0; i < 3; i++){
        printf("Digite a nota da p%d: ", i+1);
        scanf("%d", &provas[i]);
    }

    // Loop que coleta notas dos trabalhos
    for(int i=0; i < 10; i++){
        printf("Digite a nota da t%d: ", i+1);
        scanf("%d", &trab[i]);
        somat += trab[i];
    }

    // Calcula média dos trabalhos, e em seguida, da média final
    float tmedia = somat / 10;
    float media = (provas[0] * 0.25) + (provas[1] * 0.25) + (provas[2] * 0.30) + (tmedia * 0.20);

    // Imprime nota final e resultado
    printf("Nota Final: %.2f\n", media);

    return 0;
} // Fim damain