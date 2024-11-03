// Bibliotecas
#include<stdio.h>
#include<stdbool.h>

// Função main
int main(){
    // Declarações locais
    int n;
    bool primo = true;

    // Entrada de dados
    printf("Digite um numero, e direi se se ele nao eh primo.\n");
    scanf("%d", &n);
    
    // Não existe primo < 2
    if(n<2){
        primo=false;
    }
    
    // Verifica se é primo
    for(int i=2; i<=n/2; i++){
        if(n%i == 0){
            primo = false;
            break;
        }
    }

    // Impressão de resultado
    if(primo){
        printf("O numero %d eh primo",n);
    }
    else{
        printf("O numero %d nao eh primo",n);
    }

    return 0;
} // Fim da main