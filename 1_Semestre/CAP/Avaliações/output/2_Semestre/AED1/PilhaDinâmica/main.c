// Arquivos de cabeçalho
#include "Pilha.h" // Adiciona TAD

// Funções não primitivas
// Função para verificar se um elemento "x" existe na pilha
bool ExisteNaPilha(struct Pilha *p, int x) {
    struct Node *atual = p->topo;

    while(atual != NULL) {
        if(atual->info == x) {
            return true;
        }
        atual = atual->next;
    }

    return false;
}

// Função para verificar se duas pilhas são iguais
bool Iguais(struct Pilha *p1, struct Pilha *p2) {
    if(Vazia(p1) && Vazia(p2)) {
        return true;
    }
    else if(Vazia(p1) || Vazia(p2)) {
        return false;
    }
    else {
        struct Node *P1atual = p1->topo;
        struct Node *P2atual = p2->topo;

        // Percorrer ambas as pilhas simultaneamente
        while(P1atual != NULL && P2atual != NULL) {
            // Se os valores dos nós forem diferentes, as pilhas não são iguais
            if(P1atual->info != P2atual->info) {
                return false;
            }
            // Avançar para o próximo nó
            P1atual = P1atual->next;
            P2atual = P2atual->next;
        }

        // Verificar se ambas as pilhas terminaram ao mesmo tempo
        return (P1atual == NULL && P2atual == NULL);
    }
}

// Função para imprimir os elementos de uma pilha
void Imprime(struct Pilha *p) {
    struct Node *atual = p->topo;

    while(atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->next;
    }
    printf("\n");
}

// Função main
int main() {
    // Declarações globais
    struct Pilha p1, p2;
    int x;
    bool ok;

    // Inicia Pilhas
    CriaPilha(&p1);
    CriaPilha(&p2);

    // Testando funções
    Insere(&p1, 10, &ok);
    Insere(&p1, 20, &ok);
    Insere(&p1, 30, &ok);
    Insere(&p1, 40, &ok);
    Insere(&p1, 50, &ok);

    Insere(&p2, 10, &ok);
    Insere(&p2, 20, &ok);
    Insere(&p2, 30, &ok);
    Insere(&p2, 40, &ok);

    Imprime(&p1);
    Imprime(&p2);

    bool existe = ExisteNaPilha(&p1, 50);
    printf("O valor 50 existe na Pilha1? %c\n", existe ? 's' : 'n');

    Remove(&p1, &x, &ok);
    printf("Removendo valor %d da Pilha1\n", x);

    Imprime(&p1);

    bool iguais = Iguais(&p1, &p2);
    printf("As pilhas P1 e P2, sao iguais? %c\n", iguais ? 's' : 'n');

    return 0;
} // Fim da main