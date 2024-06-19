// Arquivos de cabeçalho
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Declarações globais
#define MAX_N 100

// Registro
typedef struct{
    int elem[MAX_N];
    int qtd;
} tConjunto;

// Protótipos
void iniciaConjunto(tConjunto *c);
void insereElemento(tConjunto *c);
void insereVariosElementos(tConjunto *c);
void removeElemento(tConjunto *c);
void imprimeConjunto(tConjunto c);
void imprimeOrdenadoConjunto(tConjunto c);
bool vazioConjunto(tConjunto c);
void qtdConjunto(tConjunto c);
bool existeConjunto(tConjunto c, int chave);
void uniaoConjunto(tConjunto c1, tConjunto c2, tConjunto *result);
void interseccaoConjunto(tConjunto c1, tConjunto c2, tConjunto *result);
void diferencaConjunto(tConjunto c1, tConjunto c2, tConjunto *result);
void contidoConjunto(tConjunto c1, tConjunto c2);
void contidoIgualConjunto(tConjunto c1, tConjunto c2);
void contemConjunto(tConjunto c1, tConjunto c2);
void contemIgualConjunto(tConjunto c1, tConjunto c2);

// Função main
int main(){
    // Declarações globais
    tConjunto c1, c2, result;
    int op, x;
    char c;

    // Variável de laço
    do{
        // Menu de opções
        printf("1. Inicar Conjunto\n");
        printf("2. Inserir 1 elemento no Conjunto\n");
        printf("3. Inserir varios elementos no Conjunto\n");
        printf("4. Remover elemento do Conjunto\n");
        printf("5. Imprimir Conjunto\n");
        printf("6. Imprimir Conjunto de forma ordenada - Crescente\n");
        printf("7. Verificar se o conjunto está vazio\n");
        printf("8. Ver a quantidade de elementos presente no conjunto\n");
        printf("9. Verificar se um elemento ja pertece ao conjunto\n");
        printf("10. Retornar a Uniao dos conjuntos\n");
        printf("11. Retornar a Interseccao dos conjuntos\n");
        printf("12. Retornar a Diferenca entre os conjuntos\n");
        printf("13. Verificar se o Conjunto A esta contido no Conjunto B\n");
        printf("14. Verificar se o Conjunto A esta contido ou eh igual ao Conjunto B\n");
        printf("15. Verificar se o Conjunto A contem o Conjunto B\n");
        printf("16. Verificar se o Conjunto A contem ou eh igual ao Conjunto B\n");
        printf("17. Sair\n");
   
        // Entrada da opção desejada
        scanf("%d", &op);

        // Identificar e mostrar a escolha feita
        switch(op){
            case 1:
                printf("Conjunto A:\n");
                iniciaConjunto(&c1);
                printf("Conjunto B:\n");
                iniciaConjunto(&c2);
                break;

            case 2:
                printf("Digite em qual conjunto deseja inserer o elemento!\n");
                printf("'A' ou 'B'?\n");
                scanf(" %c", &c);
                if(c == 'A'){
                    insereElemento(&c1);
                }
                else if(c == 'B'){
                    insereElemento(&c2);
                } else{
                    printf("Conjunto invalido!\n");
                }
                break;

            case 3:
                printf("Digite em qual conjunto deseja inserer varios elementos!\n");
                printf("'A' ou 'B'?\n");
                scanf(" %c", &c);
                if(c == 'A'){
                    insereElemento(&c1);
                }
                else if(c == 'B'){
                    insereElemento(&c2);
                } else{
                    printf("Conjunto invalido!\n");
                }
                break;

            case 4:
                printf("Digite em qual conjunto deseja retirar um elemento!\n");
                printf("'A' ou 'B'?\n");
                scanf(" %c", &c);
                if(c == 'A'){
                    removeElemento(&c1);
                }
                else if(c == 'B'){
                    removeElemento(&c2);
                } else{
                    printf("Conjunto invalido!\n");
                }
                break;

            case 5:
                printf("Conjunto A:\n");
                imprimeConjunto(c1);
                printf("Conjunto B:\n");
                imprimeConjunto(c2);
                break;

            case 6:
                printf("Conjunto A:\n");
                imprimeOrdenadoConjunto(c1);
                printf("Conjunto B:\n");
                imprimeOrdenadoConjunto(c2);
                break;

            case 7:
                printf("Conjunto A:\n");
                vazioConjunto(c1);
                printf("Conjunto B:\n");
                vazioConjunto(c2);
                break;

            case 8:
                printf("Conjunto A:\n");
                qtdConjunto(c1);
                printf("Conjunto B:\n");
                qtdConjunto(c2);
                break;

            case 9:
                printf("Digite o numero a ser buscado: ");
                scanf("%d", &x);

                bool existe = existeConjunto(c1, x);
                printf("O elemento %s no conjunto A!\n", existe ? "existe" : "nao existe");
                existe = existeConjunto(c2, x);
                printf("O elemento %s no conjunto B!\n", existe ? "existe" : "nao existe");
                break;

            case 10:    
                uniaoConjunto(c1, c2, &result);
                printf("Uniao dos conjuntos:\n");
                imprimeConjunto(result);
                break;

            case 11:
                interseccaoConjunto(c1, c2, &result);
                printf("Interseccao dos conjuntos:\n");
                imprimeConjunto(result);
                break;

            case 12:

                break;

            case 13:

                break;

            case 14:

                break;

            case 15:

                break;

            case 16:

                break;

            case 17:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao Invalida!\n");
            }

    } while(op != 17);

    return 0;
} // Fim da main

// Sub rotinas
// Inicia conjuntos
void iniciaConjunto(tConjunto *c){
    printf("Digite o numero de elementos do conjunto: ");
    scanf("%d", &c->qtd);
    printf("Insira os elementos:\n");
    for(int i=0; i < c->qtd; i++){
        scanf("%d", &c->elem[i]);
    }
}

// Insere 1 elemento no conjunto desejado
void insereElemento(tConjunto *c){
    int x;

    printf("Digite o numero a ser inserido: ");
    scanf("%d", &x);
    bool existe = existeConjunto(*c, x);

    if(!existe){
        c->qtd++;
        c->elem[c->qtd] = x;
    } else{
        printf("O elemento ja existe no conjunto!\n");
    }
}

// Insere vários elementos no conjunto desejado
void insereVariosElementos(tConjunto *c){
    int x;
    bool existe;

    while(1){
        printf("Digite o numero a ser inserido, ou digite '0' para sair!\n");
        scanf("%d", &x);

        existe = existeConjunto(*c, x);
        if(!existe){
            c->qtd++;
            c->elem[c->qtd] = x;
        } else{
            printf("O elemento ja existe no conjunto!\n");
        }
    }
} 

// Remove 1 elemento do conjunto desejado
void removeElemento(tConjunto *c){
    int x;

    printf("Digite o numero a ser removido: ");
    scanf("%d", &x);
    bool existe = existeConjunto(*c, x);
    
    if(existe){
        // Encontra a posição do elemento a ser removido
        for(int i = 0; i < c->qtd; i++){
            if(c->elem[i] == x){
                // Move todos os elementos após 'i' uma posição para trás
                for(int j = i; j < c->qtd - 1; j++){
                    c->elem[j] = c->elem[j + 1];
                }
                // Decrementa a quantidade de elementos no conjunto
                c->qtd--;
                printf("Numero removido com sucesso!\n");
                break;
            }
        }
    } else{
        printf("Numero não existe no conjunto!\n");
    }
}

// Impressão do conjunto de forma original (Original -> na ordem de entrada dos dados)
void imprimeConjunto(tConjunto c){
    printf("Numeros presentes no conjunto:\n");
    for(int i=0; i < c.qtd; i++){
        printf("%d ", c.elem[i]);
    }
    printf("\n");
}

// Impressão do conjunto de forma crescente (Crescente -> do menor valor ao maior)
void imprimeOrdenadoConjunto(tConjunto c){
    // Ordenação por seleção
    for(int i = 0; i < c.qtd - 1; i++){
        int min_idx = i;
        for(int j = i + 1; j < c.qtd; j++){
            if(c.elem[j] < c.elem[min_idx]){
                min_idx = j;
            }
        }
        // Troca os elementos
        int temp = c.elem[min_idx];
        c.elem[min_idx] = c.elem[i];
        c.elem[i] = temp;
    }

    // Impressão dos elementos ordenados
    printf("Numeros presentes no conjunto em ordem crescente:\n");
    for(int i = 0; i < c.qtd; i++){
        printf("%d ", c.elem[i]);
    }
}

// Verifica se o conjunto está vazio
bool vazioConjunto(tConjunto c){
    if(c.qtd == 0){
        return true;
    } else{
        return false;
    }
}

// Verifica a quantidade de elementos presente no conjunto
void qtdConjunto(tConjunto c){
    printf("Numero de elementos: %d", c.qtd);
}

// Verifica se um valor já existe no conjunto
bool existeConjunto(tConjunto c, int chave){
    bool ok;

    for(int i=0; i < c.qtd; i++){
        if(c.elem[i] == chave){
            ok = true;
            break;
        } else{
            ok = false;
        }
    }

    return ok;
}

// União entre os dois conjunto A e B
void uniaoConjunto(tConjunto c1, tConjunto c2, tConjunto *result){
    int p = -1, x;
    bool existe;

    // Incia conjunto união
    result->qtd = c1.qtd;
    for(int i=0; i < c1.qtd; i++){
        result->elem[i] = c1.elem[i];
    }

    // Indentifica valor que existe em c2 mas não em result
    while(p != c2.qtd){
        for(int i=0; i < c2.qtd; i++){
            // É colocado como falso para evitar que apenas 1 número seja inserido
            existe = false;
            for(int j=0; j < result->qtd; j++){
                if(c2.elem[i] != result->elem[j]){
                    existe = true;
                    x = c2.elem[i];
                    break;
                }
            }
        }

        if(existe){
            result->elem[result->qtd] = x;
            result->qtd++;
        }
        p++;
    }
}

// Intersecção entre os dois conjunto A e B
void interseccaoConjunto(tConjunto c1, tConjunto c2, tConjunto *result){
    for(int i=0; i < c1.qtd; i++){
        for(int j=0; j < c2.qtd; j++){
            if(c1.elem[i] == c2.elem[j]){
                result->qtd++;
                result->elem[result->qtd] = c2.elem[j];
            }
        }
    }
}

/*
// Diferença entre os dois conjuntos A e B
void diferencaConjunto(tConjunto c1, tConjunto c2, tConjunto *result){

}

// Contido = ⊂, o elemento que está dentro de um determinado conjunto.
// Verifica se o Conjunto A está contido em no Conjunto B
void contidoConjunto(tConjunto c1, tConjunto c2){

}

// Verifica se o Conjunto A está contido ou é igual ao Conjunto B
void contidoIgualConjunto(tConjunto c1, tConjunto c2){

}

// Contém = ⊃, o conjunto que contém determinado elemento.
// Verifica se um Conjunto A contém um Conjunto B
void contemConjunto(tConjunto c1, tConjunto c2){

}

// Verifica se o Conjunto A contém ou é igual ao Conjunto B
void contemIgualConjunto(tConjunto c1, tConjunto c2){

}*/