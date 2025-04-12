// Bibliotecas
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Estrutura de No
struct Node {
    struct Node *next;
    int info;
};

// Estrutura de Lista
struct Lista {
    struct Node *first;
    struct Node *atual;
};

// Função para inciar a Lista
void CriaLista(struct Lista *l) {
    l->first = NULL;
    l->atual = NULL;
}

// Função para ver se a lista está vazia
bool Vazia(struct Lista *l) {
    if(l->first == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Função para verificar se a lista está cheia
bool Cheia() {
    // Como estamos usando alocação dinâmica, a pilha nunca está cheia a menos que a memória do sistema se esgote
    return false;
}

// Função para pegar primeiro elemento da lista
void PegaFirst(struct Lista *l, int *x, bool *DeuCerto) {
    if(!Vazia(l)) {
        l->atual = l->first;
        *x = l->atual->info;
        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}

// Função para pegar próximo elemento, em relação ao ponteiro tual
void PegaProx(struct Lista *l, int *x, bool *DeuCerto) {
    if(!Vazia(l) && l->atual->next != l->first) {
        l->atual = l->atual->next;
        *x = l->atual->info;
        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}

// Função para encontrar um valor "x" na lista
bool ExisteNaLista(struct Lista *l, int x) {
    if(!Vazia(l)) {
        l->atual = l->first;

        do {
            if(x == l->atual->info) {
                return true;
            }
            l->atual = l->atual->next;
        } while(l->atual != l->first);
    }

    return false;
}

// Função para inserir elemento na lista
void Insere(struct Lista *l, int x, bool *DeuCerto) {
    if(!Cheia()) {
        if(!ExisteNaLista(l, x)) {
            struct Node *Laux = (struct Node *)malloc(sizeof(struct Node));
            Laux->info = x;

            if(Vazia(l)) {
                l->first = Laux;
                Laux->next = l->first; // Lista Circular
            }
            else {
                if(l->first->next == l->first) {
                    l->first->next = Laux;
                    Laux->next = l->first;
                }
                else {
                    l->atual = l->first;

                    while(l->atual->next != l->first) {
                        l->atual = l->atual->next;
                    }

                    l->atual->next = Laux;
                    Laux->next = l->first;
                }
            }
            *DeuCerto = true;
        }
        else {
            *DeuCerto = false;
        }
    }
    else {
        *DeuCerto = false;
    }
}

// Função para remover elemento da lista
void Remove(struct Lista *l, int *x, bool *DeuCerto) {
    if(!Vazia(l)) {
        int dado = *x;

        if(ExisteNaLista(l, dado)) {
            struct Node *anterior = NULL;
            l->atual = l->first;

            if(l->atual->next == l->first) {
                l->first = NULL;
                *x = l->atual->info;
                free(l->atual);
            }
            else {
                while(l->atual->info != *x) {
                    anterior = l->atual;
                    l->atual = l->atual->next;
                }

                *x = l->atual->info;
                free(l->atual);
                anterior->next = l->first;
            }
            *DeuCerto = true;
        }
        else {
            *DeuCerto = false;
        }
    }
    else {
        *DeuCerto = false;
    }
}