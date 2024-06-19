/*
    Um enum, ou tipo enumerado, é um tipo de dados em C que permite ao programador definir um conjunto de constantes nomeadas. O objetivo principal 
    de um enum é aumentar a legibilidade do código e torná-lo mais fácil de manter. Quando você define um enum, o compilador de C atribui automaticamente 
    valores inteiros a cada nome, começando com 0 e incrementando por 1 para cada nome subsequente, a menos que você especifique valores diferentes manualmente.
    
    Por exemplo:
    enum DiasDaSemana { DOMINGO, SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO };

    Neste caso, DOMINGO será 0, SEGUNDA será 1, e assim por diante.

    Por outro lado, um int é um tipo de dados básico em C que representa números inteiros. Você pode usar int para armazenar valores numéricos que não têm um significado 
    especial associado a eles além de seu valor numérico.
    A principal diferença entre enum e int é que enum é usado para representar um conjunto fixo de valores relacionados que são logicamente conectados, enquanto int é usado 
    para armazenar números inteiros sem qualquer conexão lógica inerente.
    Usar enum em vez de int pode ajudar a evitar erros, como passar um valor inválido para uma função, porque você está limitando os valores a um conjunto definido de constantes 
    nomeadas. Além disso, o código se torna mais legível, pois é mais fácil lembrar e escrever DOMINGO do que lembrar que 0 representa domingo.
*/

// Arquvios de cabeçalho
#include <stdio.h>

// Definindo os tipos enumerados para produtos, filiais e dias
enum Produto { PRODUTO1, PRODUTO2, PRODUTO3, NUM_PRODUTOS };
enum Filial { FILIAL1, FILIAL2, FILIAL3, NUM_FILIAIS };
enum Dia { DIA1, DIA2, DIA3, NUM_DIAS };

// Função main
int main(){
    // Declarações locais
    int np, nf, nd;
    int matriz[NUM_PRODUTOS][NUM_FILIAIS][NUM_DIAS];

    // Entrada de dadados
    printf("Digite os valores de venda(s) na matriz nesta sequencia: Produto, Filial, Data.\n");
    for(int i=0; i < NUM_PRODUTOS; i++){
        for(int j=0; j < NUM_FILIAIS; j++){
            for(int k=0; k < NUM_DIAS; k++){
                printf("Produto %d, Filial %d, Data %d: ", i+1, j+1, k+1);
                scanf("%d", &matriz[i][j][k]);
            }
        }
    }

    // Entrada de informações de busca
    printf("\nDigite Informacoes de busca:\n");
    printf("Digite o Produto: ");
    scanf("%d", &np);
    printf("Digite a Filial: "); 
    scanf("%d", &nf);
    printf("Digite a Data: ");
    scanf("%d", &nd);
    printf("\n");

    // Impressão do número de vendas específico escolhido pelo usuário
    if ((np > 0 && np <= NUM_PRODUTOS) && (nf > 0 && nf <= NUM_FILIAIS) && (nd > 0 && nd <= NUM_FILIAIS)) {
        printf("Numero de vendas do Produto %d, Filial %d, Data %d.\n", np, nf, nd);
        printf("Venda(s): %d\n\n", matriz[np-1][nf-1][nd-1]);
    } else {
        printf("Os valores digitados estao fora do escopo da matriz.\n\n");
    }

    // Impressão da matriz completa
    printf("Imprimindo venda(s) de todas os Produtos, Filiais e Datas!\n");
    for(int i=0; i < NUM_PRODUTOS; i++){
        for(int j=0; j < NUM_FILIAIS; j++){
            for(int k=0; k < NUM_FILIAIS; k++){
                printf("Produto %d, Filial %d, Data %d: ", i+1, j+1, k+1);
                printf("%d\n", matriz[i][j][k]);
            }
        }
    }

    return 0;
} // Fim da main