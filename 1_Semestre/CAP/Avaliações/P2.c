// Nome: Jonatã Aparecido Reguim
// RA: 824754

// Biblioteca
#include<stdio.h>

// Definições globais
#define n 1000

// BeeCrowd 1180
int main(){
	int x[n], i;
	int menor, indicemenor, num;
	
	// Lendo o número que representará o tamanho do vetor 
	scanf("%d", &num);
	
	// Entrada de dados para preenchimento do vetor
	for(i=0; i<num; i++){
		scanf("%d", &x[i]);
	}
	
	// Menor sendo igual ao primeiro valor do vetor (indíce 0)
	menor = x[0];
	
	// loop para encontrar o menor valor, e seu respectivo indíce
	for(i=0; i<num; i++){
		if(x[i]< menor){
			menor = x[i];
			indicemenor = i;
		}
	}
	
	// Imprimindo resultado
	printf("Menor valor: %d\n", menor);
	printf("Posicao: %d\n", indicemenor);
	
	// Fim do código
	return 0;
}

/*
// BeeCrowd 1094
int main(){
    int N, i;
    int C = 0, R = 0, S = 0, total = 0;
    char tipo;
    float percentC, percentR, percentS;
    
    // Entrada de dados 1 - Número de casos 
    scanf("%d", &N);
    
    // Entrada de dados 2 - Quantia e tipo de cobaia
    for (i = 1; i <= N; i++) {
        int quantidade;
        scanf(" %d %c", &quantidade, &tipo);
        
        total += quantidade;  // Calculando o total de cobaias
        
        // Calculando a soma de cada uma das três cobaias
        if (tipo == 'C') {
            C += quantidade;
        } else if (tipo == 'R') {
            R += quantidade;
        } else if (tipo == 'S') {
            S += quantidade;
        }
    }
    
    // Calculando a porcentagem de uso de cada uma das três cobaias utilizadas
    percentC = (C / (float)total) * 100.0;  
    percentR = (R / (float)total) * 100.0;
    percentS = (S / (float)total) * 100.0;
    
    // Imprimindo resultados
    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", C);
    printf("Total de ratos: %d\n", R);
    printf("Total de sapos: %d\n", S);
    printf("Percentual de coelhos: %.2f %%\n", percentC);
    printf("Percentual de ratos: %.2f %%\n", percentR);
    printf("Percentual de sapos: %.2f %%\n", percentS);
    
    // Fim do programa
    return 0;
}
*/