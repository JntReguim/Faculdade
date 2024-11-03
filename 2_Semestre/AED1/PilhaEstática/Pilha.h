// Bibliotecas
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// Variável global
#define MAX 5

// Estrutura de Pilha
struct Pilha {
    int topo;
    int elem[MAX];
};

// Funções Primitivas
// Função para inciar pilha
void CriaPilha(struct Pilha *p) {
    p->topo = -1;
}

// Função para verificar se a pilha está vazia
bool Vazia(struct Pilha *p) {
    if(p->topo == -1) {
        return true;
    }
    else {
        return false;
    }
}

// Função para verificar se a pilha está cheia
bool Cheia(struct Pilha *p) {
    if(p->topo == MAX - 1) {
        return true;
    }
    else {
        return false;
    }
}

// Função para ver valor do topo da pilha
void PegaTopo(struct Pilha *p, int *x, bool *DeuCerto) {
    if(!Vazia(p)) {
        *x = p->elem[p->topo];
    }
    else {
        *DeuCerto = false;
    }
}

// Função para inserir elemento na pilha
void Insere(struct Pilha *p, int x, bool *DeuCerto) {
    if(!Cheia(p)) {
        p->topo++;
        p->elem[p->topo] = x;
        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}

// Função para remover elemento da pilha
void Remove(struct Pilha *p, int *x, bool *DeuCerto) {
    if(!Vazia(p)) {
        *x = p->elem[p->topo];
        p->topo--;
        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}