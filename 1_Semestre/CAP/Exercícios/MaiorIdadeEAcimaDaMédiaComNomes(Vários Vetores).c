// Bibliotecas
#include<stdio.h>

// Declarações globais
#define nAln 5      //Número de alunos como intenger
#define nAlnD 5.0   //Número de alunos como double
#define tamNm 30    // Número de letras dos nomes

// Função main
int main(){
	// Declarações locais
	int idade[nAln], maior, RA[nAln], acimMedia;
	char sexo[nAln], nome[nAln][tamNm];
	double media;

	// Entrada de dados
	for(int i=0; i<nAln; i++){
		printf("Digite a idade, RA, sexo e nome do aluno %d: ", (i+1));
		scanf("%d%d", &idade[i], &RA[i]);
		getchar();
		scanf("%c", &sexo[i]);
		//getchar();
		gets(nome[i]);
	}

	// Cálculo da maior idade
	maior = -1;
	for(int i=0; i<nAln; i++){
		if(idade[i]>maior){
			maior = idade[i];
        }
	}

	// Cálculo da média das idades
	media = 0;
	for(int i=0; i<nAln; i++){
		media+=idade[i]/nAlnD;
	}

	//Cálculo de quantos alunas estão acima da média
    acimMedia=0;
	for(int i=0; i<nAln; i++){
		if(idade[i] > media){
			acimMedia++;
        }
	}

	// Impressão de resultado
	printf("\nA maior idade eh: %d\n\n", maior);
	printf("Nome, RA e sexo dos alunos com maior idade:\n");

	for(int i=0; i<nAln; i++){
		if(idade[i] == maior){
			printf("%s %d %c\n", nome[i], RA[i], sexo[i]);
        }
	}
	printf("\n");
	
	printf("Media = %lf\n", media);
	printf("Ha %d alunos acima da idade media\n\n", acimMedia);
	printf("Nome, RA e sexo dos alunos com idade acima da media:\n");

	for(int i=0; i<nAln; i++){
		if(idade[i] > media){
			printf("%s %d %c\n", nome[i], RA[i], sexo[i]);
        }
	}
	
	return 0;
} // Fim da main