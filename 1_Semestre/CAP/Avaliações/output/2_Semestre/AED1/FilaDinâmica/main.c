// Arquivos de cabeçalho
#include "Fila.h"

// Funções não primitivas
// Função para verificar se um elemento existe na fila
bool ExisteNaFila(struct Fila *f, int x) {
    struct Node *atual = f->first;

    if(!Vazia(f)) {
        do {
            if(atual->info == x) {
                return true;
            }
            atual = atual->next;

        } while(atual != f->first);
    }

    return false;
}

// Função que verifica se duas funções são iguais
bool Iguais(struct Fila *f1, struct Fila *f2) {
    if(Vazia(f1) && Vazia(f2)) {
        return true;
    }
    else if(Vazia(f1) || Vazia(f2)) {
        return false;
    }
    else {
        // Ponteiros para percorrer as duas filas
        struct Node *F1atual = f1->first;
        struct Node *F2atual = f2->first;

        // Percorrer ambas as filas simultaneamente
        while(F1atual != f1->first && F2atual != f2->first) {
            // Se os elementos forem diferentes, as filas não são iguais
            if(F1atual->info != F2atual->info) {
                return false;
            }
            // Avançar para o próximo nó em ambas as filas
            F1atual = F1atual->next;
            F2atual = F2atual->next;
        }
        // Se ambas as filas terminaram ao mesmo tempo, elas são iguais
        return (F1atual == f1->first && F2atual == f2->first);
    }
}

// Função para imprimir fila
void Imprime(struct Fila *f) {
    if(Vazia(f)) {
        return;
    }

    struct Node *atual = f->first;

    do {
        printf("%d ", atual->info);
        atual = atual->next;

    } while(atual != f->first);

    printf("\n");
}

// Função main
int main() {
    // Declarações globais
    struct Fila f1, f2;
    int x;
    bool ok;

    // Incializa Filas
    CriaFila(&f1);
    CriaFila(&f2);

    // Testando funções
    Insere(&f1, 10, &ok);
    Insere(&f1, 20, &ok);
    Insere(&f1, 30, &ok);
    Insere(&f1, 40, &ok);
    Insere(&f1, 50, &ok);

    Insere(&f2, 20, &ok);
    Insere(&f2, 30, &ok);
    Insere(&f2, 40, &ok);
    Insere(&f2, 50, &ok);

    Imprime(&f1);
    Imprime(&f2);

    bool existe = ExisteNaFila(&f1, 50);
    printf("O valor 50 existe na Fila1? %c\n", existe ? 's' : 'n');

    Remove(&f1, &x, &ok);
    printf("Removendo o valor %d da Fila1...\n", x);

    Imprime(&f1);

    bool iguais = Iguais(&f1, &f2);
    printf("As filas F1 e F2, sao iguais? %c\n", iguais ? 's' : 'n');

    return 0;
} // Fim da main