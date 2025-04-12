/*
Nome completo: Jonatã Aparecido Reguim
RA: 824754

Objetivo: Considere o código C em anexo que implementa um programa que lida com 
arquivos do tipo texto. Modifique o programa de forma que primeiramente grave 
as 7 sentenças abaixo, ou seja, grave cada sentença em uma linha do arquivo texto
a partir do início do arquivo. Em seguida, o programa deve ler as 7 sentenças 
gravadas no arquivo texto e mostrar as sentenças na tela do computador. Não esqueça
que antes de ler as sentenças no arquivo texto deve-se retornar a posição corrente 
do arquivo para o byte zero do arquivo usando a função fseek().

Sentenças:
- Sentença 1 - "Palmeiras tem Mundial"
- Sentença 2 - "Palmeiras foi o primeiro time Campeão Mundial"
- Sentença 3 - "Corinthians é freguês do Palmeiras"
- Sentença 4 - "FREGUÊS bom é freguês FIEL"
- Sentença 5 - "Palmeiras é freguês do São Paulo"
- Sentença 6 - "São Paulo ganhou do Corinthians na Copa do Brasil"
- Sentença 7 - "Red Bull está melhor colocado que São Paulo, Corinthians e Santos no Campeonato Brasileiro"
*/

// Biblioteca
#include <stdio.h>

// Função principal
int main(){
    // Declarações locais
    FILE *pFile;
    char buffer[100];

    // Criação do arquivo texto
    // Atenção ao uso do "t"
    pFile = fopen("myfile.txt" , "w+t");
   
    // Verificação de abertura, "O arquivo existe?"
    if(pFile == NULL){
        perror ("Error opening file");
        return 0;
    }
   
    // escrita de linhas no arquivo
    fprintf(pFile, "Palmeiras tem Mundial\n");
    fprintf(pFile, "Palmeiras foi o primeiro time Campeão Mundial\n");
    fprintf(pFile, "Corinthians é freguês do Palmeiras\n");
    fprintf(pFile, "FREGUÊS bom é freguês FIEL\n");
    fprintf(pFile, "Palmeiras é freguês do São Paulo\n");
    fprintf(pFile, "São Paulo ganhou do Corinthians na Copa do Brasil\n");
    fprintf(pFile, "Red Bull está melhor colocado que São Paulo, Corinthians e Santos no Campeonato Brasileiro\n");
   
    // Retorno ao início do arquivo
    fseek(pFile , 0 , SEEK_SET);

    // Leitura dos dados enquanto tiver linhas
    while(!feof(pFile)){
        if(fgets(buffer , 100 , pFile) == NULL){
            break;
        }
        fputs (buffer , stdout);
    }    
   
    // Fechamento do arquivo
    fclose (pFile);
   
    return 0;
} // Fim da main