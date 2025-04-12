// Bibliotecas
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// Estrutura de No
struct Node {
    struct Node *next;
    int info;
};

// Estrutura de Pilha
struct Pilha {
    struct Node *topo;
};

// Funções primitvas
// Função para inciar a pilha
void CriaPilha(struct Pilha *p) {
    p->topo = NULL;
}

// Função para ver se a pilha está vazia
bool Vazia(struct Pilha *p) {
    if(p->topo == NULL) {
        return true;
    }
    else {
        return false;
    }
}

// Função para ver se a pilha está cheia
bool Cheia() {
    // Como estamos usando alocação dinâmica, a pilha nunca está cheia a menos que a memória do sistema se esgote
    return false;
}

// Função para pegar o valor do topo da pilha
void PegaTopo(struct Pilha *p, int *x, bool *DeuCerto) {
    if(!Vazia(p)) {
        *x = p->topo->info;
        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}

// Função para inserir um elemento na pilha
void Insere(struct Pilha *p, int x, bool *DeuCerto) {
    if(!Cheia()) {
        struct Node *Paux = (struct Node *)malloc(sizeof(struct Node));

        // Verificar se malloc retornou NULL (erro de alocação)
        if(Paux == NULL) {
            *DeuCerto = false;
            return;
        }
        else {
            Paux->info = x;
            Paux->next = p->topo;
            p->topo = Paux;
            *DeuCerto = true;
        }
    }
    else {
        *DeuCerto = false;
    }
}

// Função para remover elemento da pilha
void Remove(struct Pilha *p, int *x, bool *DeuCerto) {
    if(!Vazia(p)) {
        struct Node *Paux;

        *x = p->topo->info;
        Paux = p->topo;
        p->topo = Paux->next;
        free(Paux);
        *DeuCerto = true;
    }
    else {
        *DeuCerto = false;
    }
}