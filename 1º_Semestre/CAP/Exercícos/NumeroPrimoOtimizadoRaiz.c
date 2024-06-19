// Arquivos de cabeçalho
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// função main
int main(){
    // Declarações locais
    int num;
    bool primo;

    // Entrada de dados
    printf("Digite um numero e direi se ele eh primo!\n");
    scanf("%d", &num);

    // Verificando se o número é primo de forma otimizada
    // É feita divisão do num por seus antecessores menores ou iguas a raiz quadrada do num
    primo = true;
    if(num < 2){
        primo = false;
    }
    else{
        for(int i=2; i <= sqrt(num); i++){
            if(num % i == 0){
                primo = false;
                break;
            }
        }
    }

    // Impressão de resultado
    printf("O numero %s primo", primo ? "eh" : "nao eh");

    return 0;
} // Fim da Main