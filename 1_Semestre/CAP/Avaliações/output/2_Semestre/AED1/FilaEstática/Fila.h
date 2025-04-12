// Bibliotecas
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// Variável global
#define MAX 5

// Estrutura de Fila
struct Fila {
    int elem[MAX];
    int Nelem; // Nescessário para realizar a fila "Circular"
    int first; // Primeiro elem da fila
    int final; // Último elem da fila + 1 (próximo espaço livre da fila)
};

// Funções primitivas
// Função para inciar uma fila
void CriaFila(struct Fila *f) {
    f->Nelem = 0;
    f->first = 0;
    f->final = 0;
}

// Função para verificar se a fila está vazia
bool Vazia(struct Fila *f) {
    if(f->Nelem == 0) {
        return true;
    }
    else {
        return false;
    }
}

// Função para verificar se a fila está cheia
bool Cheia(struct Fila *f) {
    if(f->Nelem == MAX) {
        return true;
    }
    else {
        return false;
    }
}

// Função para pegar primeiro elemento da fila
void PegaFirst(struct Fila *f, int *x, bool *DeuCerto) {
    if(!Vazia(f)) {
        *x = f->elem[f->first];
        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}

// Função para pegar último elemento da fila
void PegaLast(struct Fila *f, int *x, bool *DeuCerto) {
    if(!Vazia(f)) {
        // Tatra caso do primeiro elemento do vetor circular
        if(f->final == 0) {
            *x = f->elem[MAX - 1];
        }
        else {
            *x = f->elem[f->final - 1];
        }
        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}

// Função para inserir elemento na fila
void Insere(struct Fila *f, int x, bool *DeuCerto) {
    if(!Cheia(f)) {
        f->elem[f->final] = x;
        f->final = (f->final + 1) % MAX; // Atualiza o próximo espaço livre circularmente
        f->Nelem++;
        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}

// Função para remover elemento da fila
void Remove(struct Fila *f, int *x, bool *DeuCerto) {
    if(!Vazia(f)) {
        *x = f->elem[f->first];
        f->first = (f->first + 1) % MAX; // Atualiza o índice do primeiro elemento circularmente
        f->Nelem--;
        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}