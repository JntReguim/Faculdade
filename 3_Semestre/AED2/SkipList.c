// Bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da SkipList e de seus nós
typedef struct SkipList SkipList;

// Estrutura que representa um nó da Skip List
struct NO {
  int chave; // Chave armazenada no nó
  struct NO *
      *prox; // Vetor de ponteiros para os próximos nós em diferentes níveis
};

// Estrutura que representa a Skip List
struct SkipList {
  int NivelMAX; // Nível máximo permitido na Skip List
  float P;   // Probabilidade utilizada para determinar o nível de um novo nó
  int nivel; // Nível atual da Skip List
  struct NO *inicio; // Ponteiro para o nó inicial (cabeça) da Skip List
};

// Função para determinar o nível de um novo nó
int sorteiaNivel(SkipList *sk) {
  int nivel = 0;

  // Aumenta o nível enquanto o número aleatório for menor que P*100 e o nível
  // não exceder o nível máximo
  while ((rand() % 100) < (sk->P * 100) && nivel < sk->NivelMAX) {
    nivel++;
  }

  return nivel;
}

// Função para criar um novo nó
struct NO *novoNo(int chave, int nivel) {
  struct NO *novo = malloc(sizeof(struct NO)); // Aloca memória para o novo nó

  if (novo == NULL) { // Verifica se a alocação foi bem-sucedida
    return NULL;
  }

  novo->chave = chave; // Atribui a chave ao novo nó
  novo->prox = malloc(
      (nivel + 1) *
      sizeof(struct NO *)); // Aloca memória para os ponteiros dos próximos nós

  if (novo->prox == NULL) { // Verifica se a alocação foi bem-sucedida
    free(novo);
    return NULL;
  }

  for (int i = 0; i <= nivel; i++) { // Inicializa todos os ponteiros como NULL
    novo->prox[i] = NULL;
  }

  return novo;
}

// Função para criar uma nova Skip List
SkipList *criaSkiplist(int NivelMAX, float P) {
  SkipList *sk =
      (SkipList *)malloc(sizeof(SkipList)); // Aloca memória para a Skip List
  if (sk == NULL) { // Verifica se a alocação foi bem-sucedida
    return NULL;
  }

  sk->NivelMAX = NivelMAX;           // Atribui o nível máximo
  sk->P = P;                         // Atribui a probabilidade
  sk->nivel = 0;                     // Inicializa o nível atual como 0
  sk->inicio = novoNo(-1, NivelMAX); // Cria o nó inicial (cabeça) da Skip List

  if (sk->inicio ==
      NULL) { // Verifica se a criação do nó inicial foi bem-sucedida
    free(sk);
    return NULL;
  }

  return sk;
}

// Função para liberar a memória da Skip List
void liberaSkipList(SkipList *sk) {
  if (sk == NULL)
    return;

  struct NO *no,
      *atual = sk->inicio->prox[0]; // Começa pelo primeiro nó no nível 0
  while (atual != NULL) {           // Percorre todos os nós na lista
    no = atual;
    atual = atual->prox[0];
    free(no->prox); // Libera a memória dos ponteiros do nó
    free(no);       // Libera o nó
  }

  free(sk->inicio->prox); // Libera os ponteiros do nó inicial
  free(sk->inicio);       // Libera o nó inicial
  free(sk);               // Libera a estrutura da Skip List
}

// Função para buscar uma chave na Skip List
int buscaSkipList(SkipList *sk, int chave) {
  if (sk == NULL)
    return 0;

  struct NO *atual = sk->inicio; // Começa a busca pelo nó inicial
  for (int i = sk->nivel; i >= 0;
       i--) { // Percorre do nível mais alto ao nível mais baixo
    while (atual->prox[i] != NULL && atual->prox[i]->chave < chave) {
      atual = atual->prox[i]; // Avança no nível atual até que a chave seja
                              // encontrada ou ultrapassada
    }
  }

  atual = atual->prox[0]; // Move para o próximo nó no nível 0
  return (atual != NULL &&
          atual->chave ==
              chave); // Retorna 1 se a chave for encontrada, 0 caso contrário
}

// Função para inserir uma chave na Skip List
int insereSkipList(SkipList *sk, int chave) {
  if (sk == NULL)
    return 0;

  struct NO *atual = sk->inicio;
  struct NO **aux =
      malloc((sk->NivelMAX + 1) *
             sizeof(struct NO *)); // Aloca memória para o vetor auxiliar
  if (aux == NULL)
    return 0;

  for (int i = 0; i <= sk->NivelMAX; i++) {
    aux[i] = NULL; // Inicializa o vetor auxiliar
  }

  for (int i = sk->nivel; i >= 0;
       i--) { // Percorre a lista para encontrar o ponto de inserção
    while (atual->prox[i] != NULL && atual->prox[i]->chave < chave) {
      atual = atual->prox[i];
    }
    aux[i] = atual; // Guarda os nós anteriores em cada nível
  }

  atual = atual->prox[0];

  if (atual == NULL ||
      atual->chave != chave) { // Insere apenas se a chave não estiver presente
    int novo_nivel = sorteiaNivel(sk); // Determina o nível do novo nó

    if (novo_nivel > sk->NivelMAX)
      novo_nivel = sk->NivelMAX;
    struct NO *novo = novoNo(chave, novo_nivel);

    if (novo == NULL) { // Verifica se a criação do novo nó foi bem-sucedida
      free(aux);
      return 0;
    }

    if (novo_nivel >
        sk->nivel) { // Ajusta o nível atual da Skip List se necessário
      for (int i = sk->nivel + 1; i <= novo_nivel; i++) {
        aux[i] = sk->inicio;
      }
      sk->nivel = novo_nivel;
    }

    for (int i = 0; i <= novo_nivel;
         i++) { // Insere o novo nó nos níveis apropriados
      novo->prox[i] = aux[i]->prox[i];
      aux[i]->prox[i] = novo;
    }

    free(aux); // Libera a memória do vetor auxiliar
    return 1;
  }

  free(aux);
  return 0;
}

// Função para remover uma chave da Skip List
int removeSkipList(SkipList *sk, int chave) {
  if (sk == NULL)
    return 0;

  struct NO *atual = sk->inicio;
  struct NO **aux =
      malloc((sk->NivelMAX + 1) *
             sizeof(struct NO *)); // Aloca memória para o vetor auxiliar
  if (aux == NULL)
    return 0;

  for (int i = 0; i <= sk->NivelMAX; i++) {
    aux[i] = NULL;
  }

  for (int i = sk->nivel; i >= 0;
       i--) { // Percorre a lista para encontrar o nó a ser removido
    while (atual->prox[i] != NULL && atual->prox[i]->chave < chave) {
      atual = atual->prox[i];
    }
    aux[i] = atual;
  }

  atual = atual->prox[0];

  if (atual != NULL &&
      atual->chave == chave) { // Remove o nó apenas se a chave for encontrada
    for (int i = 0; i <= sk->nivel; i++) {
      if (aux[i]->prox[i] != atual)
        break;
      aux[i]->prox[i] = atual->prox[i];
    }

    while (sk->nivel > 0 && sk->inicio->prox[sk->nivel] == NULL) {
      sk->nivel--; // Ajusta o nível da Skip List se necessário
    }

    free(atual->prox); // Libera a memória do nó removido
    free(atual);
    free(aux);
    return 1;
  }

  free(aux);
  return 0;
}

// Função para imprimir a Skip List
void imprimeSkipList(SkipList *sk) {
  if (sk == NULL)
    return;

  printf("\n*****Skip List*****\n");
  for (int i = 0; i <= sk->nivel;
       i++) { // Imprime os nós em cada nível da Skip List
    struct NO *no = sk->inicio->prox[i];
    printf("Nivel %d: ", i);
    while (no != NULL) {
      printf("%d ", no->chave);
      no = no->prox[i];
    }
    printf("\n");
  }
}

// Função main
int main() {
  int vector[] = {29, 15, 51, 12, 3,  42, 81, 77, 5,  30,
                  16, 52, 13, 4,  43, 82, 78, 6,  64, 32};
  int num =
      sizeof(vector) / sizeof(int); // Calcula o número de elementos no vetor

  // Criação da Skip List com nível máximo 4 e probabilidade 0.5
  SkipList *sk = criaSkiplist(
      3, 0.5); // Cria uma Skip List com nível máximo 4 e probabilidade 0.5
  if (sk == NULL) { // Verifica se a criação foi bem-sucedida
    printf("Erro ao criar a SkipList\n");
    return 1;
  }

  // Inserção de elementos na Skip List
  for (int i = 0; i < num; i++) {
    if (!insereSkipList(sk, vector[i])) {
      printf("Erro ao inserir chave %d\n",
             vector[i]); // Verifica se a inserção foi bem-sucedida
    }
  }

  printf("Após a inserção:");
  imprimeSkipList(sk); // Imprime a Skip List após a inserção

  // Remoção de elementos específicos da Skip List
  removeSkipList(sk, 12); // Remove o elemento com chave 12
  removeSkipList(sk, 42); // Remove o elemento com chave 42
  removeSkipList(sk, 77); // Remove o elemento com chave 77

  printf("\nApós a remoção:");
  imprimeSkipList(sk); // Imprime a Skip List após a remoção

  // Liberação da memória alocada para a Skip List
  liberaSkipList(sk); // Libera a memória utilizada pela Skip List

  return 0;
} // Fim da main