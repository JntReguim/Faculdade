/*
Autor: Jonatã Aparecido Reguim.
RA: 824754

Objetivo:
Um número racional é uma fração, a qual é representada na forma de 
"numerador/denominador", sendo que o valor do denominador deve ser diferente 
de zero. Além disso, ambos o numerador e o denominador são números inteiros.
A definição completa sobre número racional pode ser encontrada na URL 
http://pt.wikipedia.org/wiki/Número_racional.

Escreva sub-rotinas (funções ou procedimentos) para:
- Ler um número racional r.
- Escrever um número racional r.
- Somar dois números racionais r1 e r2 (r1 + r2).
- Subtrair dois números racionais r1 e r2 (r1 - r2).
- Multiplicar dois números racionais r1 e r2 (r1 * r2).
- Dividir dois números racionais r1 e r2 (r1 / r2).

Restrições: 
Os números racionais devem ser simplificados de forma que fiquem em sua forma
mais básica. Por exemplo, 20/100 deve ser simplificado para 1/5. 
Isso deve ser realizado como resultado da leitura de um número racional, 
ou seja, após o número racional ser lido do teclado, ele já deve ser 
simplificado dentro da própria sub-rotina de leitura. O número racional também
deve ser simplificado nas operações de soma, subtração, multiplicação e divisão
de números racionais. Desta forma, o resultado de cada uma dessas operações
deve ser um número racional simplificado.
*/

// Bibliotecas
#include<stdio.h>
#include<stdlib.h>

// Estrutura para num Raciaonal
typedef struct {
    int n;      // numerador
    int d;      // denominador, deve ser diferente de zero (divisão por zero)
    int sinal;  // correção de sinal
} tRacional;

// Protótipos das funções
void leiaRacional(tRacional *);
void escrevaRacional(tRacional);

tRacional somaRacional(tRacional, tRacional);
tRacional subtraiRacional(tRacional, tRacional);
tRacional multiplicaRacional(tRacional, tRacional);
tRacional divideRacional(tRacional, tRacional);
tRacional simplificaRacional(tRacional);

void lerRacional2(tRacional *num1, tRacional *num2);
void escreveRacional2(tRacional *num1, tRacional *num2);
int calcularMDC(int a, int b);
void simplificaRacional2(tRacional *num1, tRacional *num2);
void somaRacional2(tRacional *num1, tRacional *num2, tRacional *Resultado);
void subtrRacional2(tRacional *num1, tRacional *num2, tRacional *Resultado);
void multiRacional2(tRacional *num1, tRacional *num2, tRacional *Resultado);
void dividirRacional2(tRacional *num1, tRacional *num2, tRacional *Resultado);

int MDC(int, int);
int MMC(int, int);

// Função main
int main(){
   // Declaração local
   tRacional racional1, racional2, resultado;
   tRacional Racional1, Racional2, Resultado;
   
   // Leitura de dados
   printf("Leitura do 1o numero racional\n");
   leiaRacional(&racional1);
   
   // racional1 = leiaRacional();
   printf("\n");
   printf("Leitura do 2o numero racional\n");
   leiaRacional(&racional2);
   
   // racional2 = leiaRacional();
   printf("\n\n");

   // Soma de números racionais
   printf("Soma:\n");
   resultado = somaRacional(racional1, racional2);
   escrevaRacional(resultado);
   printf("\n");
   
   // Subtração de números racionais
   printf("Subtracao:\n");
   resultado = subtraiRacional(racional1, racional2);
   escrevaRacional(resultado);
   printf("\n");

   // Multiplicação de números racionais
   printf("Multiplicacao:\n");
   resultado = multiplicaRacional(racional1, racional2);
   escrevaRacional(resultado);
   printf("\n");
   
   // Divisão de números racionais
   printf("Divisao:\n");
   resultado = divideRacional(racional1, racional2);
   escrevaRacional(resultado);
   printf("\n");
   
   
   // Lendo para ponteiro
   printf("Digite os valores:");
   lerRacional2(&Racional1, &Racional2);
   printf("\n");
   
   // Escrevendo racionais
   escreveRacional2(&Racional1, &Racional2);
   printf("\n");
   
   // Racionais simplificados
   printf("Simplicação dos racionais recebidos: ");
   simplificaRacional2(&Racional1, &Racional2);
   printf("\n");

   // Soma de números racionais
   somaRacional2(&Racional1, &Racional2, &Resultado);
   printf("\n");
   
   // Subtração do racionais
   printf("Subtração entre os racionais é: ");
   subtrRacional2(&Racional1, &Racional2, &Resultado);
   printf("\n");

   // Multiplicação de números racionais
   printf("Multiplicacao:\n");
   multiRacional2(&Racional1, &Racional2, &Resultado);
   printf("\n");
   
   // Divisão de números racionais
   dividirRacional2(&Racional1, &Racional2, &Resultado);
   printf("\n");

   return 0;
} // Fim da main


// Função para ler um número racional
void leiaRacional(tRacional *r){
   // Leitura do numerador
   printf("Digite o numerador: ");
   scanf("%d", &r->n);
   
   // Leitura do denominador
   printf("Digite o denominador: ");
   scanf("%d", &r->d);
   
   // Simplificação
   *r = simplificaRacional(*r);
}

// Função para escrever na tela do monitor um número racional
void escrevaRacional(tRacional r){
   // Escrita do número racional
   printf("Número racional = %d/%d\n", r.n, r.d);
}

// Função para somar dois números racionais r1 e r2 (r1 + r2)
tRacional somaRacional(tRacional r1, tRacional r2){
   // Declaração local
   tRacional soma; // racional com o valor da soma de r1 e r2.
   
   // Cálculo da soma
   soma.d = MMC(r1.d, r2.d);
   soma.n = (soma.d/r1.d*r1.n) + (soma.d/r2.d*r2.n);
   soma = simplificaRacional(soma);
   
   // Valor de retorno
   return soma;
}

// Função para subtrair dois números racionais r1 e r2 (r1 - r2)
tRacional subtraiRacional(tRacional r1, tRacional r2){
   // Declaração local
   tRacional subtracao; // racional com o valor da subtração de r1 e r2.
   
   // Cálculo da subtração
   subtracao.d = MMC(r1.d, r2.d);
   subtracao.n = (subtracao.d/r1.d*r1.n) - (subtracao.d/r2.d*r2.n);
   subtracao = simplificaRacional(subtracao);

   // Valor de retorno
   return subtracao;
}

// Função para multiplicar dois números racionais r1 e r2 (r1 * r2)
tRacional multiplicaRacional(tRacional r1, tRacional r2){
   // Declaração local
   tRacional multiplica; // racional com o valor da multiplicação de r1 e r2.
   
   // Cálculo da soma
   multiplica.n = r1.n * r2.n;
   multiplica.d = r1.d * r2.d;
   multiplica = simplificaRacional(multiplica);
   
   // Valor de retorno
   return multiplica;
}

// Função para dividir dois números racionais r1 e r2 (r1 / r2)
tRacional divideRacional(tRacional r1, tRacional r2){
   // Declaração local
   tRacional divide; // racional com o valor da divisão de r1 e r2.
   
   // Cálculo da soma
   divide.n = r1.n * r2.d;
   divide.d = r1.d * r2.n;
   divide = simplificaRacional(divide);

   // Valor de retorno
   return divide;
}

// Função para simplificar um número racional, de forma que fique em sua forma mais básica
tRacional simplificaRacional(tRacional r){
    // Declaração local
    int mdc; // máximo divisor comum entre numerador e denominador
   
    // Simplificação do número racional
    mdc = MDC(r.n, r.d);
    r.n = r.n / mdc;
    r.d = r.d / mdc;
   
    // Tratamento do sinal
    // Sempre no numerador
    if(r.n < 0 && r.d < 0){
        r.n = abs(r.n);
        r.d = abs(r.d);
    }
    else if (r.d < 0){
        r.n = r.n * -1;
        r.d = r.d * -1;
    }
   
   // Valor de retorno
   return r;
}

// Função para calcular o máximo divisor comum entre 2 números inteiros
int MDC(int n1, int n2){
   // Declaração local
   int r; // resto
   
   // Cálculo do MDC
   while(n2 != 0){
        r = n1 % n2;
        n1 = n2;
        n2 = r;
    }
    
   // Valor de retorno
   return n1;
}

// Função para calcular o mínimo múltiplo comum entre 2 números inteiros
int MMC(int n1, int n2){
   // Cálculo do MMC
   // Valor de retorno
   return n1 * (n2 / MDC(n1, n2));
}

// ---------------------------------------------------------------------------------------------------------------------------------- //

// Função para ler os dados de dois números racionais qualquer
void lerRacional2(tRacional *num1, tRacional *num2){
    printf("Digite o numerador de (num1): ");
    scanf("%d", &num1->n);
    printf("Digite o denominador de (num1): ");
    scanf("%d", &num1->d);

    printf("Digite o numerador de (num2): ");
    scanf("%d", &num2->n);
    printf("Digite o denominador de (num2): ");
    scanf("%d", &num2->d);
}

// Função para imprimir os dois números racionais recebidos
void escreveRacional2(tRacional *num1, tRacional *num2){
    printf("O racional (num1) é: %d/%d\n", num1->n, num1->d);
    printf("O racional (num2) é: %d/%d\n", num2->n, num2->d);
}

// Função para Calcular o MDC de uma operação entre números racionais
int calcularMDC(int a, int b){
    int resto;
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

// Função para simplificar os dois números racionais recebidos
void simplificaRacional2(tRacional *num1, tRacional *num2){
    int mdc = calcularMDC(num1->n, num1->d);
    num1->n /= mdc;
    num1->d /= mdc;
    printf("A simplificação de (num1) é: %d/%d\n", num1->n, num1->d);

    mdc = calcularMDC(num2->n, num2->d);
    num2->n /= mdc;
    num2->d /= mdc;
    printf("A simplificação de (num2) é: %d/%d\n", num2->n, num2->d);
}

// Função para soma entre os dois números racionais recebidos
void somaRacional2(tRacional *num1, tRacional *num2, tRacional *Resultado){
    Resultado->n = (num1->n * num2->d) + (num2->n * num1->d);
    Resultado->d = num1->d * num2->d;
    printf("A soma de (num1 e num2) é: %d/%d\n", Resultado->n, Resultado->d);
}

// Função para subtração entre os dois números racionais recebidos
void subtrRacional2(tRacional *num1, tRacional *num2, tRacional *Resultado){
    Resultado->n = (num1->n * num2->d) - (num2->n * num1->d);
    Resultado->d = num1->d * num2->d;
    printf("A subtração de (num1 e num2) é: %d/%d\n", Resultado->n, Resultado->d);
}

// Função para multiplicação entre os dois números racionais recebidos
void multiRacional2(tRacional *num1, tRacional *num2, tRacional *Resultado){
    Resultado->n = (num1->n * num2->n);
    Resultado->d = (num1->d * num2->d);
    printf("A multiplicação de (num1 e num2) é: %d/%d\n", Resultado->n, Resultado->d);
}

// Função para dividisão entre os dois números racionais recebidos
void dividirRacional2(tRacional *num1, tRacional *num2, tRacional *Resultado){
    if(num2->n == 0){
        printf("Erro: Não é possível dividir por zero.\n");
        return;
    }
    
    Resultado->n = (num1->n * num2->d);
    Resultado->d = (num1->d * num2->n);
    printf("A divisão de (num1 e num2) é: %d/%d\n", Resultado->n, Resultado->d);
}