// Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Declarações globais
#define TAM_NOME 100
#define TAM_FIM 3

// Função main
int main(){
	//Declarações locais
	char nome[TAM_NOME];  
	char nome2[TAM_NOME]; 
	char fim[TAM_FIM];      // Critério de parada
	int numVogais;
	
	// Inicializações 
	strcpy(fim, "FIM");

	// Entrada de dados
	printf("Digite um nome para contar as vogais: ");
	scanf("%s", nome); // nome = &nome[0]
	
	// Cópia da string para facilitar comparação e escrita do nome original
	strcpy(nome2, nome);
	    
	// Transformação da segunda string em apenas letras maiúsculas para facilitar a comparação transformação para a forma canônica
    for(int i=0; i<strlen(nome2); i++){
	  nome2[i] = toupper(nome2[i]);
    }

	do{
	    // Contagem de quantas vogais há na string inserida
	    numVogais=0;
	    for(int i=0; i<strlen(nome2); i++){
	        if(nome2[i]=='A'|| nome2[i]=='E'|| nome2[i]=='I'|| nome2[i]=='O'|| nome2[i]=='U'){
	            numVogais++;
            }
        }

		
        //Saída de dados
	    if(numVogais==1){
	        printf("%s tem %d vogal\n", nome, numVogais);
        }
	    else{
		    printf("%s tem %d vogais\n", nome, numVogais);
        }
		
	    // Leitura do próximo nome
	    printf("Digite um nome para contar as vogais\n");
	    printf("ou digite palmeiras para parar: ");
	    scanf("%s", nome);
	  
	    // Cópia da string para facilitar comparação e escrita do nome original
	    strcpy(nome2, nome);
	    
	    // Transformação da segunda string em apenas letras maiúsculas para facilitar a comparação transformação para a forma canônica
        for(int i=0; i<strlen(nome2); i++){
		    nome2[i]=toupper(nome2[i]);
        }

	} while(strcmp(nome2, fim));

	return 0;
} // Fim da main