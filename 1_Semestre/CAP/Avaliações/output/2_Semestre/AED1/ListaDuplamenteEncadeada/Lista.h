// Bibliotecas
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Estrutura de No
struct Node {
    struct Node *dir;
    struct Node *esq;
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
}

// Função para pegar próximo elemento, em relação ao ponteiro tual
void PegaProx(struct Lista *l, int *x, bool *DeuCerto) {
}

// Função para encontrar um valor "x" na lista
bool ExisteNaLista(struct Lista *l, int x) {
}

// Função para inserir elemento na lista
void Insere(struct Lista *l, int x, bool *DeuCerto) {
}

// Função para remover elemento da lista
void Remove(struct Lista *l, int *x, bool *DeuCerto) {
}