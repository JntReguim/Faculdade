// Arquivos de cabeçalho
#include "ArvABB.h" // Adiciona TAD

// Funções não primitivas
// Função que verifica se a Árvore é uma ArvABB
bool EhABB(struct Node *raiz) {
    if(Vazia(raiz)) {
        return true;
    }
    else {
        if(raiz->esq != NULL && raiz->dir == NULL) {
            if(raiz->info < raiz->esq->info) {
                return false;
            }
        }
        else if(raiz->esq == NULL && raiz->dir != NULL) {
            if(raiz->info > raiz->dir->info) {
                return false;
            }
        }
        else if(raiz->esq != NULL && raiz->dir != NULL) {
            if(raiz->info < raiz->esq->info && raiz->info > raiz->dir->info) {
                return false;
            }
        }

        return (EhABB(raiz->esq) && EhABB(raiz->dir));
    }
}

// Função que verifica se duas ArvABB são iguais
bool Iguais(struct Node *raiz1, struct Node *raiz2) {
    if(Vazia(raiz1) && Vazia(raiz2)) {
        return true;
    }
    else {
        if((raiz1 != NULL && raiz2 == NULL) || (raiz1 == NULL && raiz2 != NULL)) {
            return false;
        }
        else {
            if((raiz1->info == raiz2->info) && (Iguais(raiz1->esq, raiz2->esq)) && (Iguais(raiz1->dir, raiz2->dir))) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

// Função que retorna a Soma dos Nodes da ArvABB
int Soma(struct Node *raiz) {
    if(Vazia(raiz)) {
        return 0;
    }
    else {
        int valor = raiz->info;
        valor += Soma(raiz->esq) + Soma(raiz->dir);
        return valor;
    }
}

// Função main
int main() {
    // Declarações locais
    struct Node *Arv1;
    struct Node *Arv2;
    bool ok;

    // Inicia ArvsABB
    CriaArvABB(&Arv1);
    CriaArvABB(&Arv2);

    // Testando funções
    Insere(&Arv1, 10, &ok);
    Insere(&Arv1, 20, &ok);
    Insere(&Arv1, 30, &ok);
    Insere(&Arv1, 40, &ok);
    Insere(&Arv1, 50, &ok);

    Insere(&Arv2, 11, &ok);
    Insere(&Arv2, 22, &ok);
    Insere(&Arv2, 33, &ok);
    Insere(&Arv2, 44, &ok);
    Insere(&Arv2, 55, &ok);

    Imprime(Arv1);
    printf("\n");
    Imprime(Arv2);
    printf("\n");

    bool ehABB1 = EhABB(Arv1);
    bool ehABB2 = EhABB(Arv2);
    printf("A Arv1 eh ABB? %c\n", ehABB1 ? 's' : 'n');
    printf("A Arv2 eh ABB? %c\n", ehABB2 ? 's' : 'n');

    int soma1 = Soma(Arv1);
    int soma2 = Soma(Arv2);
    printf("A soma dos valores da Arv1 eh: %d\n", soma1);
    printf("A soma dos valores da Arv2 eh: %d\n", soma2);

    Remove(&Arv1, 50, &ok);
    Remove(&Arv2, 55, &ok);

    Imprime(Arv1);
    printf("\n");
    Imprime(Arv2);
    printf("\n");

    bool iguais = Iguais(Arv1, Arv2);
    printf("As ArvABBs 1 e 2, sao iguais?: %c\n", iguais ? 's' : 'n');

    Destroi(&Arv1);
    Destroi(&Arv2);

    return 0;
} // Fim da main