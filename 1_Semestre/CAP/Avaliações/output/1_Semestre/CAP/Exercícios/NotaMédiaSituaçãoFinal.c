// Bibliotecas
#include<stdio.h>

// Função main
int main(){
    // Declarações locais
    int trab[10];
    int somat = 0;
    int provas[3];
    float presenca;

    // Entrada de dados
    printf("Digite a presenca do aluno: ");
    scanf("%f", &presenca);

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

    // Resultado Final
    if(presenca >= 75 && media >=6){
        printf("Nota Final: %.2f\n", media);
        printf("Presenca: %.2f\n", presenca);
        printf("Resultado Final: Aprovado!\n");
    }
    else if(presenca >= 75 && media >=5){
        printf("Nota Final: %.2f\n", media);
        printf("Presenca: %.2f\n", presenca);
        printf("Resultado Final: Recuperação!\n");
    }
    else{
        printf("Nota Final: %.2f\n", media);
        printf("Presenca: %.2f\n", presenca);
        printf("Resultado Final: Reprovado!");
    }

    return 0;
} // Fim damain