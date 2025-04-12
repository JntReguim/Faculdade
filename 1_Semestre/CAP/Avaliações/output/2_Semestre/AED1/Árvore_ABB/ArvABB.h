// Bibliotecas
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Estrura de No
struct Node {
    int info;
    struct Node *esq;
    struct Node *dir;
};

// Funções primitivas
// Função que inica uma ArvABB
void CriaArvABB(struct Node **raiz) {
    *raiz = NULL;
}

// Função para verificar se ArvABB está vazia
bool Vazia(struct Node *raiz) {
    if(raiz == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Função para verificar se um elemento "x" está na ArvABB
bool EstaNaArvABB(struct Node *raiz, int x) {
    // Caso 1: Verifica se árvore está Vazia
    if(Vazia(raiz)) {
        return false;
    }
    // Caso 2: Verifica se "x" está no topo
    else if(x == raiz->info) {
        return true;
    }
    // Caso 3: busca "x" a Esq
    else if(x < raiz->info) {
        return (EstaNaArvABB(raiz->esq, x));
    }
    // Caso 4: busca "x" a Dir
    else {
        return (EstaNaArvABB(raiz->dir, x));
    }
}

// Função para inserir elemento na ArvABB
void Insere(struct Node **raiz, int x, bool *DeuCerto) {
    // Caso 1: Árvore Vazia, insere no topo
    if(Vazia(*raiz)) {
        struct Node *aux = (struct Node *)malloc(sizeof(struct Node));
        aux->info = x;
        aux->esq = NULL;
        aux->dir = NULL;

        *raiz = aux;
        aux = NULL;
        *DeuCerto = true;
    }
    else {
        // Caso 2: x já existe na árvore?
        if(EstaNaArvABB(*raiz, x)) {
            *DeuCerto = false;
        }
        else {
            // Caso 3: X vai ser adicionado a Esq
            if(x < (*raiz)->info) {
                Insere(&(*raiz)->esq, x, DeuCerto);
            }
            // Caso 4: X vai ser adicionado a Dir
            else {
                Insere(&(*raiz)->dir, x, DeuCerto);
            }
        }
    }
}

// Função para remover elemento da ArvABB
void Remove(struct Node **raiz, int x, bool *DeuCerto) {
    struct Node *aux;

    // Caso 1: Árvore Vaiza
    if(Vazia(*raiz)) {
        *DeuCerto = false;
    }
    else {
        // Caso 3: remove x da subarvore Esq
        if(x < (*raiz)->info) {
            Remove(&(*raiz)->esq, x, DeuCerto);
        }
        else {
            // Caso 4: remove X da subarvore Dir
            if(x > (*raiz)->info) {
                Remove(&(*raiz)->dir, x, DeuCerto);
            }
            // Caso 2: três variantes a2(0 filhos), b2(1 filho), c2(2 filhos)
            else {
                aux = *raiz;

                // Caso a2 (0 filhos)
                if((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
                    free(aux);
                    *raiz = NULL;
                }
                else {
                    // Caso c2 (2 filhos)
                    if((*raiz)->esq != NULL && (*raiz)->dir != NULL) {
                        aux = (*raiz)->esq;

                        while(aux->dir != NULL) {
                            aux = aux->dir;
                        }
                        (*raiz)->info = aux->info;
                        Remove(&(*raiz)->esq, aux->info, DeuCerto);
                    }
                    else {
                        // Caso b2 (1 filho)
                        if((*raiz)->esq == NULL) {
                            *raiz = (*raiz)->dir;
                        }
                        else {
                            *raiz = (*raiz)->esq;
                        }
                    }
                }

                *DeuCerto = true;
                free(aux);
            }
        }
    }
}

// Função para finalizar a ArvABB
void Destroi(struct Node **raiz) {
    if(Vazia(*raiz)) {
        return;
    }
    else {
        Destroi(&(*raiz)->esq);
        Destroi(&(*raiz)->dir);
        free(*raiz);
    }
}

// Funções para imprimir elemntos da ArvABB

// Impressão em "In-Ordem": (Ordem Crescente)
// Imprime as subarvores da Esq, depois a raiz, depois as subarvore da Dir
void Imprime(struct Node *raiz) {
    if(!Vazia(raiz)) {
        Imprime(raiz->esq);
        printf("%d ", raiz->info);
        Imprime(raiz->dir);
    }
}

/*
// Impressão em "Pós-Ordem": (Ordem Decrescente)
// Imprime as subarvores da Dir, depois a raiz, depois as subarvore da Esq
void Imprime(struct Node *raiz) {
    if(!Vazia(raiz)) {
        Imprime(raiz->dir);
        printf("%d ", raiz->info);
        Imprime(raiz->esq);
    }
}

// Impressão em "Pré-Ordem"
// Imprime a raiz, depois as subarvores da Esq, depois as subarvore da Dir
void Imprime(struct Node *raiz) {
    if(!Vazia(raiz)) {
        printf("%d ", raiz->info);
        Imprime(raiz->esq);
        Imprime(raiz->dir);
    }
}
*/