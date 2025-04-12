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
// Função que inica uma ArvHeap
void CriaArvHeap(struct Node **raiz) {
    *raiz = NULL;
}

// Função para verificar se ArvHeap está vazia
bool Vazia(struct Node *raiz) {
    if(raiz == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Função para verificar se um elemento "x" está na ArvHeap
bool EstaNaArvHeap(struct Node *raiz, int x) {
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
        return (EstaNaArvHeap(raiz->esq, x));
    }
    // Caso 4: busca "x" a Dir
    else {
        return (EstaNaArvHeap(raiz->dir, x));
    }
}

// Função para inserir elemento na ArvHeap
void Insere(struct Node **raiz, int x, bool *DeuCerto) {
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
    }
}

// Função para remover elemento da ArvHeap
void Remove(struct Node **raiz, int x, bool *DeuCerto) {
}

// Função para finalizar a ArvHeap
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