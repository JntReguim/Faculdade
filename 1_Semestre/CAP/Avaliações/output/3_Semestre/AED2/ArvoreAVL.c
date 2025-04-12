// Bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó da árvore AVL
struct NO {
  int info;
  int altura;
  struct NO *esq; // Ponteiro para subárvore esquerda
  struct NO *dir; // Ponteiro para subárvore direita
};

typedef struct NO *ArvAVL;

// Função para criar uma árvore AVL
ArvAVL *cria_ArvAVL() {
  ArvAVL *raiz = (ArvAVL *)malloc(sizeof(ArvAVL));

  if (raiz != NULL) {
    *raiz = NULL; // Inicializa a raiz como NULL
  }

  return raiz;
}

// Função para liberar a memória de um nó
void libera_NO(struct NO *no) {
  if (no == NULL) {
    return;
  }

  libera_NO(no->esq); // Libera subárvore esquerda
  libera_NO(no->dir); // Libera subárvore direita

  free(no); // Libera o nó atual
}

// Função para liberar a memória da árvore
void libera_ArvAVL(ArvAVL *raiz) {
  if (raiz == NULL) {
    return;
  }

  libera_NO(*raiz); // Libera todos os nós

  free(raiz); // Libera a raiz
}

// Função para obter a altura de um nó
int altura_NO(struct NO *no) {
  if (no == NULL) {
    return -1;
  } else {
    return no->altura;
  }
}

// Função para calcular o fator de balanceamento de um nó
int fatorBalanceamento_NO(struct NO *no) {
  return (altura_NO(no->esq) - altura_NO(no->dir));
}

// Função para retornar o maior valor entre dois inteiros
int maior(int x, int y) { return (x > y) ? x : y; }

// Função para verificar se a árvore está vazia
int estaVazia_ArvAVL(ArvAVL *raiz) {
  if (raiz == NULL || *raiz == NULL) {
    return 1; // Árvore está vazia
  }

  return 0; // Árvore não está vazia
}

// Função para contar o número total de nós na árvore
int totalNO_ArvAVL(ArvAVL *raiz) {
  if (raiz == NULL || *raiz == NULL) {
    return 0;
  }

  int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
  int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));

  return (alt_esq + alt_dir + 1);
}

// Função para calcular a altura da árvore
int altura_ArvAVL(ArvAVL *raiz) {
  if (raiz == NULL || *raiz == NULL) {
    return 0;
  }

  int alt_esq = altura_ArvAVL(&((*raiz)->esq));
  int alt_dir = altura_ArvAVL(&((*raiz)->dir));

  return maior(alt_esq, alt_dir) + 1;
}

// Função para percorrer a árvore em pré-ordem
void preOrdem_ArvAVL(ArvAVL *raiz) {
  if (raiz == NULL) {
    return;
  }

  if (*raiz != NULL) {
    printf("No %d: %d\n", (*raiz)->info, altura_NO(*raiz));

    preOrdem_ArvAVL(&((*raiz)->esq));
    preOrdem_ArvAVL(&((*raiz)->dir));
  }
}

// Função para percorrer a árvore em ordem
void emOrdem_ArvAVL(ArvAVL *raiz) {
  if (raiz == NULL) {
    return;
  }

  if (*raiz != NULL) {
    emOrdem_ArvAVL(&((*raiz)->esq));

    printf("No %d: H(%d) fb(%d)\n", (*raiz)->info, altura_NO(*raiz),
           fatorBalanceamento_NO(*raiz));

    emOrdem_ArvAVL(&((*raiz)->dir));
  }
}

// Função para percorrer a árvore em pós-ordem
void posOrdem_ArvAVL(ArvAVL *raiz) {
  if (raiz == NULL) {
    return;
  }

  if (*raiz != NULL) {
    posOrdem_ArvAVL(&((*raiz)->esq));
    posOrdem_ArvAVL(&((*raiz)->dir));

    printf("%d\n", (*raiz)->info);
  }
}

// Função para consultar a existência de um valor na árvore
int consulta_ArvAVL(ArvAVL *raiz, int valor) {
  if (raiz == NULL) {
    return 0;
  }

  struct NO *atual = *raiz;

  while (atual != NULL) {
    if (valor == atual->info) {
      return 1; // Valor encontrado
    }
    if (valor > atual->info) {
      atual = atual->dir;

    } else {
      atual = atual->esq;
    }
  }

  return 0; // Valor não encontrado
}

/* =============================================================================
 */

// Rotação simples à direita
void RotacaoLL(ArvAVL *A) {
  printf("Rotação simples a Direita!\n");

  struct NO *B;

  B = (*A)->esq;
  (*A)->esq = B->dir;
  B->dir = *A;
  (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
  B->altura = maior(altura_NO(B->esq), (*A)->altura) + 1;
  *A = B;
}

// Rotação simples à esquerda
void RotacaoRR(ArvAVL *A) {
  printf("Rotação simples a Esquerda!\n");

  struct NO *B;

  B = (*A)->dir;
  (*A)->dir = B->esq;
  B->esq = (*A);
  (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
  B->altura = maior(altura_NO(B->dir), (*A)->altura) + 1;
  (*A) = B;
}

// Rotação dupla à esquerda-direita
void RotacaoLR(ArvAVL *A) {
  RotacaoRR(&(*A)->esq); // Rotação simples à direita
  RotacaoLL(A);          // Rotação simples à esquerda
}

// Rotação dupla à direita-esquerda
void RotacaoRL(ArvAVL *A) {
  RotacaoLL(&(*A)->dir); // Rotação simples à esquerda
  RotacaoRR(A);          // Rotação simples à direita
}

// Função para inserir um valor na árvore AVL
int insere_ArvAVL(ArvAVL *raiz, int valor) {
  int res;

  if (*raiz == NULL) { // Árvore vazia ou nó folha
    struct NO *novo;
    novo = (struct NO *)malloc(sizeof(struct NO));

    if (novo == NULL) {
      return 0; // Falha ao alocar memória
    }

    novo->info = valor;
    novo->altura = 0;
    novo->esq = NULL;
    novo->dir = NULL;
    *raiz = novo;

    return 1; // Inserção bem-sucedida
  }

  struct NO *atual = *raiz;

  if (valor < atual->info) {
    if ((res = insere_ArvAVL(&(atual->esq), valor)) == 1) {
      if (labs(fatorBalanceamento_NO(atual)) >= 2) {
        if (valor < (*raiz)->esq->info) {
          RotacaoLL(raiz); // Rotação simples à direita
        } else {
          RotacaoLR(raiz); // Rotação dupla à esquerda-direita
        }
      }
    }
  } else {
    if (valor > atual->info) {
      if ((res = insere_ArvAVL(&(atual->dir), valor)) == 1) {
        if (labs(fatorBalanceamento_NO(atual)) >= 2) {
          if ((*raiz)->dir->info < valor) {
            RotacaoRR(raiz); // Rotação simples à esquerda
          } else {
            RotacaoRL(raiz); // Rotação dupla à direita-esquerda
          }
        }
      }
    } else {
      printf("Valor duplicado!!\n");

      return 0; // Valor duplicado não é inserido
    }
  }

  atual->altura = maior(altura_NO(atual->esq), altura_NO(atual->dir)) + 1;

  return res;
}

// Função para encontrar o menor valor na subárvore
struct NO *procuraMenor(struct NO *atual) {
  struct NO *no1 = atual;
  struct NO *no2 = atual->esq;

  while (no2 != NULL) {
    no1 = no2;
    no2 = no2->esq;
  }

  return no1;
}

struct NO *sucessor_ArvAVL(ArvAVL *raiz, int valor) {
  if (raiz == NULL || *raiz == NULL) {
    return NULL; // Árvore vazia ou valor não encontrado
  }

  struct NO *atual = *raiz;
  struct NO *sucessor = NULL;

  // Primeiro, encontre o nó com o valor desejado
  while (atual != NULL && atual->info != valor) {
    if (valor < atual->info) {
      sucessor = atual; // Possível sucessor
      atual = atual->esq;
    } else {
      atual = atual->dir;
    }
  }

  if (atual == NULL) {
    return NULL; // Valor não encontrado
  }

  // Caso 1: O nó tem um filho direito
  if (atual->dir != NULL) {
    sucessor = procuraMenor(atual->dir);
  }

  // Caso 2: O nó não tem filho direito
  // O sucessor já foi definido durante a busca

  return sucessor;
}

// Função para remover um valor da árvore AVL
int remove_ArvAVL(ArvAVL *raiz, int valor) {
  if (*raiz == NULL) {
    printf("Valor não existe!\n");

    return 0; // Valor não encontrado
  }

  int res;

  if (valor < (*raiz)->info) {
    if ((res = remove_ArvAVL(&(*raiz)->esq, valor)) == 1) {
      if (labs(fatorBalanceamento_NO(*raiz)) >= 2) {
        if (altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir)) {
          RotacaoRR(raiz); // Rotação simples à esquerda
        } else {
          RotacaoRL(raiz); // Rotação dupla à direita-esquerda
        }
      }
    }
  }
  if ((*raiz)->info < valor) {
    if ((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1) {
      if (labs(fatorBalanceamento_NO(*raiz)) >= 2) {
        if (altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq)) {
          RotacaoLL(raiz); // Rotação simples à direita
        } else {
          RotacaoLR(raiz); // Rotação dupla à esquerda-direita
        }
      }
    }
  }
  if ((*raiz)->info == valor) {
    if (((*raiz)->esq == NULL ||
         (*raiz)->dir == NULL)) { // Nó com 1 filho ou nenhum
      struct NO *oldNode = (*raiz);

      if ((*raiz)->esq != NULL) {
        *raiz = (*raiz)->esq;
      } else {
        *raiz = (*raiz)->dir;
      }

      free(oldNode);
    } else { // Nó com 2 filhos
      struct NO *temp = procuraMenor((*raiz)->dir);
      (*raiz)->info = temp->info;
      remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);

      if (fatorBalanceamento_NO(*raiz) >= 2) {
        if (altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq)) {
          RotacaoLL(raiz); // Rotação simples à direita
        } else {
          RotacaoLR(raiz); // Rotação dupla à esquerda-direita
        }
      }
    }

    if (*raiz != NULL) {
      (*raiz)->altura =
          maior(altura_NO((*raiz)->esq), altura_NO((*raiz)->dir)) + 1;
    }

    return 1; // Remoção bem-sucedida
  }

  (*raiz)->altura = maior(altura_NO((*raiz)->esq), altura_NO((*raiz)->dir)) + 1;

  return res;
}

// Função main
int main() {
  int vet[] = {11, 12, 13, 14, 15, 20, 19, 18, 17, 16,
               5,  4,  3,  2,  1,  6,  7,  8,  9,  10};
  int num = sizeof(vet) / sizeof(int);

  ArvAVL *raiz = cria_ArvAVL();

  for (int i = 0; i < num; i++) {
    insere_ArvAVL(raiz, vet[i]);
  }

  printf("\nÁrvore em ordem após a inserção:\n");
  emOrdem_ArvAVL(raiz);
  printf("\n");

  remove_ArvAVL(raiz, 5);
  remove_ArvAVL(raiz, 10);
  remove_ArvAVL(raiz, 15);

  printf("\nÁrvore em ordem após a remoção:\n");
  emOrdem_ArvAVL(raiz);
  printf("\n");

  return 0;
} // Fim da main