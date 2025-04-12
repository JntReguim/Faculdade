// Bibliotecas
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Estrutura de No
struct Node {
    struct Node *next;
    int info;
};

// Estrutura de Fila
struct Fila {
    struct Node *first;
    struct Node *last;
};

// Funções primitivas
// Função para iniciar a fila
void CriaFila(struct Fila *f) {
    f->first = NULL;
    f->last = NULL;
}

// Função para verificar se a fila está vazia
bool Vazia(struct Fila *f) {
    if(f->first == NULL && f->last == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Função para ver se a fila está cheia
bool Cheia() {
    // Como estamos usando alocação dinâmica, a fila nunca está cheia a menos que a memória do sistema se esgote
    return false;
}

// Função para pegar o primeiro elemento da fila
void PegaFirst(struct Fila *f, int *x, bool *DeuCerto) {
    if(!Vazia(f)) {
        *x = f->first->info;
        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}

// Função para pegar o último elemento da fila
void PegaLast(struct Fila *f, int *x, bool *DeuCerto) {
    if(!Vazia(f)) {
        *x = f->last->info;
        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}

// Função para inserir elemento elemento da fila
void Insere(struct Fila *f, int x, bool *DeuCerto) {
    if(!Cheia()) {
        struct Node *Faux = (struct Node *)malloc(sizeof(struct Node));
        Faux->info = x;

        // Verificar se malloc retornou NULL (erro de alocação)
        if(Faux == NULL) {
            *DeuCerto = false;
            return;
        }

        if(Vazia(f)) {
            f->first = Faux;
            f->last = Faux;
            f->last->next = f->first; // Fila circular
        }
        else {
            f->last->next = Faux;
            f->last = Faux;
            f->last->next = f->first;
        }

        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}

// Função para remover elemento da fila
void Remove(struct Fila *f, int *x, bool *DeuCerto) {
    if(!Vazia(f)) {
        struct Node *Faux;

        *x = f->first->info;
        if(f->first == f->last) {
            Faux = f->first;
            f->first = NULL;
            f->last = NULL;
        }
        else {
            Faux = f->first;
            f->first = Faux->next;
            f->last->next = f->first; // Fila circular
        }

        free(Faux);
        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}