/*
Nome completo: Jonatã Aparecido Reguim
RA: 824754

Objetivo: Manipule um cubo de dados com as dimensões produto, filial e tempo que 
armazena o total de vendas. Ou seja, o arranjo multidimensional armazena o total 
de vendas que acontece em cada combinação de produto, filial e tempo (dia no ano). 
Primeiramente, faça a leitura de todos os dados de entrada por meio de uma varredura 
completa do cubo de dados. Em seguida, faça uma busca e mostre o total de vendas para 
um determinado produto em uma determinada filial e um certo tempo. Na busca, o usuário 
entrará com o nome do produto, o nome da filial e a data (dia, mês e ano). Deve-se procurar
os índices das dimensões produto, filial e tempo em estruturas auxiliares (arranjos) para 
poder acessar o total de vendas no cubo de dados. Os dados das estruturas auxiliares que irão
armazenar os dados de produto, filial e tempo devem ser inicializados na declaração. Por fim, 
mostrar todas as vendas do arranjo multidimensional por meio de uma varredura completa.
*/

// Bibliotecas
#include<stdio.h>
#include<string.h>

// Definições globais
#define nP 2
#define nF 2 
#define nD 2 

// Função main
int main(){
    // Definições locais
    int x, y, z;
    int vendas[nP][nF][nD];
    char P1[20];
    char F1[20];
    char D1[20];
    char P[nP][20];
    char F[nF][20];
    char D[nD][20];
    
    // Entrada de dados
    printf("Preencha a matriz com o total de vendas:\n\n");
    
    for(int i=0; i<nP; i++){
        for(int j=0; j<nF; j++){
            for(int k=0; k<nD; k++){
                printf("Produto %d, Filial %d, Data %d \n", i, j, k);
                scanf("%d", &vendas[i][j][k]);
            }
        }
    }
    
    // Pula linha
    printf("\n");
    
    // Definindo as posições de produtos (P), filiais (F), datas (D) 
    strcpy(P[0], "Coca-cola");
    strcpy(P[1], "Pepsi");
    strcpy(F[0], "Centro");
    strcpy(F[1], "Entrada");
    strcpy(D[0], "12/05/2023");
    strcpy(D[1], "13/05/2023");
    
    // Entrada de pesquisa
    printf("Digite o nome do produto, a filial, e o dia, para saber o total de vendas:\n");
    scanf("%s %s %s", P1, F1, D1);
    
    // Encontrando valores
    for(int i=0; i<nP; i++){
        if(strcmp(P1, P[i]) == 0){
            x = i;
        }
    }
    for(int j=0; j<nF; j++){
        if(strcmp(F1, F[j]) == 0){
            y = j;
        }
    }
    for(int k=0; k<nD; k++){
        if(strcmp(D1, D[k]) == 0){
            z = k;
        }
    }
    
    // Pula linha
    printf("\n");
    
    // Impressão do total de vendas com base nos valores de entrada de pesquisa
    printf("Total de vendas é:%d\n\n", vendas[x][y][z]);
    
    // Impressão da matriz e a impressão do total de vendas de cada combinação
    printf("O total de vendas completo é:\n\n");
    for(int i=0; i<nP; i++){
        for(int j=0; j<nF; j++){
            for(int k=0; k<nD; k++){
                printf("Total de vendas %d,  produto: %s  filial: %s  dia: %s\n", vendas[i][j][k], P[i], F[j], D[k]);
            }
        }
    }
    
    return 0;
} // Fim da main