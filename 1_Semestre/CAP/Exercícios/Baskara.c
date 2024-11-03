// Bibliotecas
#include<stdio.h>
#include<math.h>

// Função main
int main(){
    // Declarações locais
    double a, b, c;
    double delta;
    double x1, x2;
    
    // Entrada de dados de a, b e c
    printf("Digite o valor de a: ");
    scanf("%lf", &a);
    
    printf("Digite o valor de b: ");
    scanf("%lf", &b);
    
    printf("Digite o valor de c: ");
    scanf("%lf", &c);
    
    // Calculando valor de delta
    delta = (b * b) - (4 * a * c);
    
    // Se delta maior que 0 (duas raízes reais)
    if(delta > 0){
        // Calculando as duas raízes reais
        x1 = (-b + sqrt(delta) ) / (2 * a);
        
        x2 = (-b - sqrt(delta) ) / (2 * a);
        
        // Imprimindo valor das duas raízes reais
        printf("A função tem duas raízes reais!\n");
        printf("O valor de x1 é %.2lf e x2 é %.2lf\n", x1, x2);
    }
    
    // Se delta igual a 0 (uma raíz real)
    else if(delta == 0){
        // Calculando valor de raiz única
        x1 = (-b + sqrt(delta) ) / (2 * a);
        
        // Imnprimindo resultado
        printf("A função tem apenas uma raíz real!\n");
        printf("O valor raíz é %.2lf\n", x1);
    }
    
    // Em caso delta menor que 0
    else{
        // Impressão de resultado
        printf("A função não possui raíz reais!\n");
    }
    
    return 0; 
} // Fim da main