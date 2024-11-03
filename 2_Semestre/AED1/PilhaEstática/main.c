// Arquivos de cabeçalho
#include "Pilha.h" // Adiciona TAD

// Funções não primitivas
// Função para verificar se existe um elemento "x" n pilha
bool ExisteNaPilha(struct Pilha *p, int x) {
    for(int i = 0; i <= p->topo; i++) {
        if(x == p->elem[i]) {
            return true;
        }
    }

    return false;
}

// Função que verifique se duas pilha são iguais
bool Iguais(struct Pilha *p1, struct Pilha *p2) {
    if(Vazia(p1) && Vazia(p2)) {
        return true;
    }
    else if(Vazia(p1) || Vazia(p2)) {
        return false;
    }
    else {
        // Verifica se ambas as pilhas têm o mesmo número de elementos
        if(p1->topo != p2->topo) {
            return false;
        }

        // Variáveis temporárias para iterar sobre os elementos
        int tempTopo1 = p1->topo;
        int tempTopo2 = p2->topo;

        // Verifica elemento por elemento
        while(tempTopo1 >= 0 && tempTopo2 >= 0) {
            if(p1->elem[tempTopo1] != p2->elem[tempTopo2]) {
                return false; // Se qualquer elemento for diferente, as pilhas não são iguais
            }
            tempTopo1--;
            tempTopo2--;
        }

        // Se todas as comparações foram iguais, as pilhas são idênticas
        return true;
    }
}

// Função para imprimir elementos da Pilha
void Imprime(struct Pilha *p) {
    for(int i = 0; i <= p->topo; i++) {
        printf("%d ", p->elem[i]);
    }
}

// Função main
int main() {
    // Declrações locais
    struct Pilha p1, p2;
    int x;
    bool ok;

    // Inicia as Pilhas
    CriaPilha(&p1);
    CriaPilha(&p2);

    // Testando funções
    Insere(&p1, 10, &ok);
    Insere(&p1, 20, &ok);
    Insere(&p1, 30, &ok);
    Insere(&p1, 40, &ok);

    Insere(&p2, 10, &ok);
    Insere(&p2, 20, &ok);
    Insere(&p2, 30, &ok);
    Insere(&p2, 40, &ok);
    Insere(&p2, 50, &ok);

    bool existe = ExisteNaPilha(&p2, 50);
    printf("O valor 50 existe na p2?: %c\n", existe ? 's' : 'n');

    Imprime(&p1);
    printf("\n");
    Imprime(&p2);
    printf("\n");

    Remove(&p2, &x, &ok);

    bool iguais = Iguais(&p1, &p2);
    printf("As pilhas sao iguais?: %c\n", iguais ? 's' : 'n');

    return 0;
} // Fim da main