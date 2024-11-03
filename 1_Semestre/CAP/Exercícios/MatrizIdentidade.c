// Bibliotecas
#include<stdio.h>
#include<stdbool.h>

// Variáveis globais
#define Total_linhas 3
#define Total_colunas 3

// Função main
int main(){
    // Declarações locais
    double m1[Total_linhas][Total_colunas];
    int Identidade;
    
    // Ler matriz
    for(int i=0; i<Total_linhas; i++){
        for(int j=0; j<Total_colunas; j++){
            printf("Entre com o elemento %d %d da matriz: ", i+1, j+1);
            scanf("%lf", &m1[i][j]);
        }
    }
    
    // Verificar se é identidade
    Identidade = true;
    
    for(int i=0; i<Total_linhas; i++){
        for(int j=0; j<Total_colunas; j++){
            if(i==j){
                if(m1[i][j] != 1){
                    Identidade = false;
                    break;
                }
            }
            else{
                if(m1[i][j]!=0){
                    Identidade = false;
                    break;
                }
            }
        }
        
        if(!Identidade){
            break;
        }
    }
    
    // Impressão de resultado
    if(Identidade){
        printf("A matriz eh uma matriz identidade.\n");
    }
    else{
        printf("A matriz nao eh uma matriz identidade.\n");
    }
   
    return 0;
} // Fim da main