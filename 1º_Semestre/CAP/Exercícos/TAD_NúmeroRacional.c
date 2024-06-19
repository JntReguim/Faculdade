// Arquivos de cabeçalho
#include <stdio.h>

// Registro
typedef struct{
    int n;          // Numerador
    int d;          // Denominador
} tRacional;

// Protótipos
void leRacional(tRacional *r);
void imprimeRacional(tRacional r);
int mdc(int a, int b);
void simplificaRacional(tRacional *r1);
void somaRacionais(tRacional r1, tRacional r2, tRacional *result);
void subRacionais(tRacional r1, tRacional r2, tRacional *result);
void multRacionais(tRacional r1, tRacional r2, tRacional *result);
void divRacionais(tRacional r1, tRacional r2, tRacional *result);

// Função main
int main(){
    // Declarações locais
    tRacional r1, r2, result;

    // Utilizando sub rotinas
    // Entrada de dados
    leRacional(&r1);
    imprimeRacional(r1);
    leRacional(&r2);
    imprimeRacional(r2);

    // Simplifica racionais
    simplificaRacional(&r1);
    simplificaRacional(&r2);

    // Operações com números racionais
    somaRacionais(r1, r2, &result);
    subRacionais(r1, r2, &result);
    multRacionais(r1, r2, &result);
    divRacionais(r1, r2, &result);

    return 0;
} // Fim da main

// Sub rotinas
// Entrade de dados
void leRacional(tRacional *r){
    printf("Digite o valor do numerador: ");
    scanf("%d", &r->n);
    printf("Digite o valor do denominador: ");
    scanf("%d", &r->d);
}

// Impressão do número racional
void imprimeRacional(tRacional r){
    printf("Valor do numerador: %d\n", r.n);
    printf("Valor do denominador: %d\n", r.d);
}

// Função para calcular o MDC de dois números usando o algoritmo de Euclides
int mdc(int a, int b){
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Simplifica o número racional, caso nescessário. (x é o MDC)
void simplificaRacional(tRacional *r){
    int x = mdc(r->n, r->d);
    r->n /= x;
    r->d /= x;
    printf("A simplificacao de (num1): %d/%d\n", r->n, r->d);
}

// Soma números racionas
void somaRacionais(tRacional r1, tRacional r2, tRacional *result){
    result->n = (r1.n * r2.d) + (r2.n * r1.d);
    result->d = (r1.d * r2.d);
    printf("A soma de (num1 e num2): %d/%d\n", result->n, result->d);
}

// Subtração entre dois números racionais
void subRacionais(tRacional r1, tRacional r2, tRacional *result){
    result->n = (r1.n * r2.d) - (r2.n * r1.d);
    result->d = (r1.d * r2.d);
    printf("A subtracao de (num1 e num2): %d/%d\n", result->n, result->d);
}

// Multiplica dois números racionais
void multRacionais(tRacional r1, tRacional r2, tRacional *result){
    result->n = (r1.n * r2.n);
    result->d = (r1.d * r2.d);
    printf("A multiplicacao de (num1 e num2): %d/%d\n", result->n, result->d);
}

// Divide dois números racionais
void divRacionais(tRacional r1, tRacional r2, tRacional *result){
    if (r2.n == 0){
        printf("Erro: Não é possível dividir por zero.\n");
        return;
    }

    result->n = (r1.n * r2.d) ;
    result->d = (r1.d * r2.n);
    printf("A divisao de (num1 e num2): %d/%d\n", result->n, result->d);
}