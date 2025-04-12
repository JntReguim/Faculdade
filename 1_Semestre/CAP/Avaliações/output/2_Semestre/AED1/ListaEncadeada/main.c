// Arquivos de cabeçalho
#include "Lista.h" // Adiciona TAD

// Funções não primitivas
// Função para verificar se duas listas circulares são iguais
bool Iguais(struct Lista *l1, struct Lista *l2) {
    if(Vazia(l1) && Vazia(l2)) {
        return true;
    }
    else if(Vazia(l1) || Vazia(l2)) {
        return false;
    }

    struct Node *n1 = l1->first;
    struct Node *n2 = l2->first;

    do {
        if(n1->info != n2->info) {
            return false;
        }
        n1 = n1->next;
        n2 = n2->next;
    } while(n1 != l1->first && n2 != l2->first);

    // Verifica se ambas as listas chegaram ao início ao mesmo tempo
    return (n1 == l1->first && n2 == l2->first);
}

// Função para imprimir a lista
void Imprime(struct Lista *l) {
    int dado;
    bool TemElemento;

    PegaFirst(l, &dado, &TemElemento);
    while(TemElemento) {
        printf("%d ", dado);
        PegaProx(l, &dado, &TemElemento);
    }

    printf("\n");
}

// Função main
int main() {
    // Declarações locais
    struct Lista l1, l2;
    int x = 50;
    bool ok;

    // Incia listas
    CriaLista(&l1);
    CriaLista(&l2);

    // Testando funções
    Insere(&l1, 10, &ok);
    Insere(&l1, 30, &ok);
    Insere(&l1, 20, &ok);
    Insere(&l1, 40, &ok);
    Insere(&l1, 50, &ok);

    Insere(&l2, 10, &ok);
    Insere(&l2, 30, &ok);
    Insere(&l2, 20, &ok);
    Insere(&l2, 40, &ok);

    Imprime(&l1);
    Imprime(&l2);

    bool existe = ExisteNaLista(&l1, 50);
    printf("O valor 50 existe na Lista1: %c\n", existe ? 's' : 'n');

    Remove(&l1, &x, &ok);
    printf("Removendo valor %d da Lista1...\n", x);
    printf("Deu certo a remocao? %c\n", ok ? 's' : 'n');

    Imprime(&l1);

    bool iguais = Iguais(&l1, &l2);
    printf("As listas 1 e 2 sao iguais? %c\n", iguais ? 's' : 'n');

    return 0;
} // Fim da main