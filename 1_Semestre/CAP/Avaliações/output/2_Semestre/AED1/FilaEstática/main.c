// Arquivos de cabeçalho
#include "Fila.h"

// Funções não primitivas
// Função para verificar se um elemento existe na fila
bool ExisteNaFila(struct Fila *f, int x) {
    int i = f->first; // Começa no índice do primeiro elemento
    int count = 0;    // Contador para controlar a quantidade de elementos impressos

    while(count < f->Nelem) {
        if(x == f->elem[i]) {
            return true;
        }

        i = (i + 1) % MAX; // Avança circularmente no array
        count++;
    }

    return false;
}

// Função que verifica se duas funções são iguais
bool Iguias(struct Fila *f1, struct Fila *f2) {
    if(Vazia(f1) && Vazia(f2)) {
        return true;
    }
    else if(Vazia(f1) || Vazia(f2)) {
        return false;
    }
    else {
        if(f1->Nelem == f2->Nelem) {
            int i = f1->first;
            int j = f2->first;
            int count = 0;

            while(count < f1->Nelem) { // f1->Nelem == f2->Nelem
                if(f1->elem[i] == f2->elem[j]) {
                    j = (j + 1) % MAX;
                    i = (i + 1) % MAX;
                    count++;
                }
                else {
                    return false;
                }
            }

            return true;
        }
        else {
            return false;
        }
    }
}

// Função para imprimir fila
void Imprime(struct Fila *f) {
    int i = f->first;
    int count = 0;

    printf("Elementos da fila: ");

    while(count < f->Nelem) {
        printf("%d ", f->elem[i]);
        i = (i + 1) % MAX;
        count++;
    }

    printf("\n");
}

// Função main
int main() {
    // Declarações locais
    struct Fila f1, f2;
    int x;
    bool ok;

    // Incia Filas
    CriaFila(&f1);
    CriaFila(&f2);

    // Testando funções
    Insere(&f1, 11, &ok);
    Insere(&f1, 22, &ok);
    Insere(&f1, 33, &ok);
    Insere(&f1, 44, &ok);
    Insere(&f1, 55, &ok);
    Insere(&f1, 66, &ok); // Não insere, fila cheia!

    Insere(&f2, 22, &ok);
    Insere(&f2, 33, &ok);
    Insere(&f2, 44, &ok);
    Insere(&f2, 55, &ok);

    bool existe = ExisteNaFila(&f1, 66);
    printf("Existe 66 na Fila1?: %c\n", existe ? 's' : 'n');

    Imprime(&f1);
    Imprime(&f2);

    // Remove elemento da fila1 (x = 55)
    Remove(&f1, &x, &ok);

    printf("Fila1 apos remocao...\n");
    Imprime(&f1);

    bool iguais = Iguias(&f1, &f2);
    printf("As filas sao iguais?: %c\n", iguais ? 's' : 'n');

    return 0;
} // Fim da main