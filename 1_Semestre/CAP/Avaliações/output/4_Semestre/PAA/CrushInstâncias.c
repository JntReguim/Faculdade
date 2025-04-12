// Jonatã Ap. Reguim - 824754
// Ciência da Computação

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define INFINITO INT_MAX

typedef struct {
    int dest;
    int peso;
} Aresta;

typedef struct {
    Aresta *arestas;
    int tam;
    int total;
} Grafo;

typedef struct {
    int vertice;
    int dist;
} Heap;

typedef struct {
    Heap *nos;
    int *pos;
    int tam;
    int total;
} MinHeap;

void addAresta(Grafo *lista, int dest, int peso) {
    if(lista->tam == lista->total) {
        lista->total *= 2;
        lista->arestas = realloc(lista->arestas, lista->total * sizeof(Aresta));
    }
    lista->arestas[lista->tam].dest = dest;
    lista->arestas[lista->tam].peso = peso;
    lista->tam++;
}

MinHeap *criarMinHeap(int total) {
    MinHeap *heap = malloc(sizeof(MinHeap));
    heap->nos = malloc(total * sizeof(Heap));
    heap->pos = malloc(total * sizeof(int));
    heap->tam = 0;
    heap->total = total;
    return heap;
}

void swap(Heap *a, Heap *b) {
    Heap temp = *a;
    *a = *b;
    *b = temp;
}

void organizarHeap(MinHeap *heap, int indice) {
    int menor = indice;
    int esq = 2 * indice + 1;
    int dir = 2 * indice + 2;

    if(esq < heap->tam && heap->nos[esq].dist < heap->nos[menor].dist)
        menor = esq;

    if(dir < heap->tam && heap->nos[dir].dist < heap->nos[menor].dist)
        menor = dir;

    if(menor != indice) {
        Heap noMenor = heap->nos[menor];
        Heap noIndice = heap->nos[indice];

        heap->pos[noMenor.vertice] = indice;
        heap->pos[noIndice.vertice] = menor;

        swap(&heap->nos[menor], &heap->nos[indice]);

        organizarHeap(heap, menor);
    }
}

Heap removerMenor(MinHeap *heap) {
    Heap raiz = heap->nos[0];
    Heap ultimoNo = heap->nos[heap->tam - 1];

    heap->nos[0] = ultimoNo;

    heap->pos[raiz.vertice] = heap->tam - 1;
    heap->pos[ultimoNo.vertice] = 0;

    heap->tam--;
    organizarHeap(heap, 0);

    return raiz;
}

void reduzirDist(MinHeap *heap, int vertice, int dist) {
    int i = heap->pos[vertice];
    heap->nos[i].dist = dist;

    while(i && heap->nos[i].dist < heap->nos[(i - 1) / 2].dist) {
        heap->pos[heap->nos[i].vertice] = (i - 1) / 2;
        heap->pos[heap->nos[(i - 1) / 2].vertice] = i;
        swap(&heap->nos[i], &heap->nos[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int dentroHeap(MinHeap *heap, int vertice) {
    return heap->pos[vertice] < heap->tam;
}

void dijkstra(Grafo *grafo, int vertices, int origem, int dest) {
    int *dists = malloc(vertices * sizeof(int));
    for(int i = 0; i < vertices; i++)
        dists[i] = INFINITO;
    dists[origem] = 0;

    MinHeap *heap = criarMinHeap(vertices);

    for(int v = 0; v < vertices; v++) {
        heap->nos[v].vertice = v;
        heap->nos[v].dist = dists[v];
        heap->pos[v] = v;
    }

    heap->tam = vertices;
    reduzirDist(heap, origem, dists[origem]);

    while(heap->tam) {
        Heap noMinimo = removerMenor(heap);
        int u = noMinimo.vertice;

        for(int i = 0; i < grafo[u].tam; i++) {
            int v = grafo[u].arestas[i].dest;
            int peso = grafo[u].arestas[i].peso;

            if(dentroHeap(heap, v) && dists[u] != INFINITO && dists[u] + peso < dists[v]) {
                dists[v] = dists[u] + peso;
                reduzirDist(heap, v, dists[v]);
            }
        }
    }

    printf("%d\n", dists[dest]);

    free(dists);
    free(heap->nos);
    free(heap->pos);
    free(heap);
}

int main() {
    int vertices, arestas;
    scanf("%d %d", &vertices, &arestas);

    Grafo *grafo = malloc(vertices * sizeof(Grafo));
    for(int i = 0; i < vertices; i++) {
        grafo[i].arestas = malloc(2 * sizeof(Aresta));
        grafo[i].tam = 0;
        grafo[i].total = 2;
    }

    for(int i = 0; i < arestas; i++) {
        int origem, dest, peso;
        scanf("%d %d %d", &origem, &dest, &peso);
        addAresta(&grafo[origem], dest, peso);
    }

    dijkstra(grafo, vertices, 0, vertices - 1);

    for(int i = 0; i < vertices; i++) {
        free(grafo[i].arestas);
    }
    free(grafo);

    return 0;
}