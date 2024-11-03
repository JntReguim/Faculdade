// Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Declarações globais
// Ordem 4
#define MAX 3       // #MaxChave (Ordem - 1)
#define MIN 1       // #MinChave ((Ordem / 2) - 1) 

// Estrutura da Árvore B
struct ArvB{
    int chave[MAX];                       // Array que armazena as chaves no nó
    struct ArvB* filho[MAX + 1];          // Ponteiros para os nós filhos (subárvores)
    int nChaves;                          // Número de chaves no nó
    bool eFolha;                          // Indica se o nó é uma folha (sem filhos)
};

// Declaração global da raiz
struct ArvB* raiz = NULL;

// Função para criar um novo nó na árvore B
// A função inicializa um nó como filho ou não, e define o número de chaves como 0
struct ArvB* NovoNO(bool folha){
    struct ArvB* no = (struct ArvB *)malloc(sizeof(struct ArvB)); // Aloca memória para o nó
    no->eFolha = folha;  // Define se o nó é uma folha
    no->nChaves = 0;     // Inicializa o número de chaves no nó

    // Inicializa os ponteiros para os filhos como NULL
    for(int i = 0; i < MAX + 1; i++){
        no->filho[i] = NULL;
    }

    return no;  // Retorna o novo nó criado
}

// Função para buscar uma chave na árvore B
// Retorna o nó que contém a chave ou NULL se a chave não for encontrada
struct ArvB* busca(struct ArvB* raiz, int k){
    int i = 0;

    // Busca a posição da chave
    while(i < raiz->nChaves && k > raiz->chave[i]){
        i++;
    }

    // Se a chave for encontrada, retorna o nó
    if(i < raiz->nChaves && k == raiz->chave[i]){
        return raiz;
    }

    // Se o nó for uma folha e a chave não foi encontrada, retorna NULL
    if(raiz->eFolha){
        return NULL;
    }

    // Continua a busca recursivamente no filho adequado
    return busca(raiz->filho[i], k);
}

// Função para dividir um nó, a divisão ocorre quando um nó atinge a capacidade máxima de chaves
// Split (1-to-2)
void Split(struct ArvB* pai, int i, struct ArvB* noCheio){
    struct ArvB* novoFilho = NovoNO(noCheio->eFolha);   // Cria novo nó para a metade das chaves
    novoFilho->nChaves = MIN;                           // O novo nó conterá MIN chaves após a divisão

    // Move as chaves de noCheio para novoFilho
    for(int j = 0; j < MIN; j++){
        novoFilho->chave[j] = noCheio->chave[j + MIN + 1];
    }

    // Move os filhos de noCheio para novoFilho, se o nó não for uma folha
    if(!noCheio->eFolha){
        for(int j = 0; j <= MIN; j++){
            novoFilho->filho[j] = noCheio->filho[j + MIN + 1];
        }
    }

    // Reduz o número de chaves em noCheio
    noCheio->nChaves = MIN;

    // Move os filhos do pai para abrir espaço para o novo filho
    for(int j = pai->nChaves; j >= i + 1; j--){
        pai->filho[j + 1] = pai->filho[j];
    }
    pai->filho[i + 1] = novoFilho;  // Insere o novo filho no pai

    // Move as chaves do pai para abrir espaço para a chave promovida
    for(int j = pai->nChaves - 1; j >= i; j--){
        pai->chave[j + 1] = pai->chave[j];
    }

    // Promove a chave mediana para o pai
    pai->chave[i] = noCheio->chave[MIN];
    pai->nChaves++;
}

// Insere uma chave em um nó que ainda não está cheio
void InsereNaoCheio(struct ArvB* no, int k){
    int i = no->nChaves - 1;

    // Se o nó for folha, insere a chave diretamente na posição correta
    if(no->eFolha){
        // Encontra a posição correta para inserir a nova chave
        while(i >= 0 && k < no->chave[i]){
            no->chave[i + 1] = no->chave[i]; // Move as chaves maiores uma posição para a direita
            i--;
        }

        // Insere a nova chave na posição encontrada
        no->chave[i + 1] = k;
        no->nChaves++;

    } 
    else{
        // Se o nó não for uma folha, encontra o filho apropriado para a inserção
        while(i >= 0 && k < no->chave[i]){
            i--;
        }
        i++; // Ajusta o índice para o filho correto

        // Se o filho escolhido estiver cheio, realiza a divisão (split)
        if(no->filho[i]->nChaves == MAX){
            Split(no, i, no->filho[i]); // Realiza a divisão do filho

            // Após a divisão, verifica se a nova chave deve ser inserida no próximo filho
            if(k > no->chave[i]){
                i++;
            }
        }

        // Continua a inserção recursivamente no filho adequado
        InsereNaoCheio(no->filho[i], k);
    }
}

// Função para inserir uma chave na árvore B
void Insere(struct ArvB** raiz, int k){
    struct ArvB* r = *raiz;

    // Se a árvore estiver vazia, cria um novo nó como raiz
    if(r == NULL){
        *raiz = NovoNO(true);
        (*raiz)->chave[0] = k;
        (*raiz)->nChaves = 1;
    } 
    else{
        // Se a raiz estiver cheia, precisa ser dividida
        if(r->nChaves == MAX){
            struct ArvB* novo = NovoNO(false);
            *raiz = novo;
            novo->filho[0] = r;
            
            Split(novo, 0, r);       // Divide a raiz
            InsereNaoCheio(novo, k); // Continua a inserção no nó adequado
        } 
        else{
            InsereNaoCheio(r, k);    // Se a raiz não estiver cheia, insere diretamente
        }
    }
}

// Função auxiliar para encontrar o predecessor de uma chave
int getPredecessor(struct ArvB* no, int i){
    struct ArvB* atual = no->filho[i];  // Começa pelo filho à esquerda da chave
    
    // O predecessor é a chave mais à direita da subárvore esq
    while(!atual->eFolha){                      // Continua descendo até encontrar uma folha
        atual = atual->filho[atual->nChaves];   // Vai para o filho mais à direita
    }
    
    return atual->chave[atual->nChaves - 1];    // Retorna a última chave da folha
}

// Função para fundir dois nós (Concatenação)
void Merge(struct ArvB* no, int i){
    struct ArvB* filho = no->filho[i];   // Obtém o nó filho à esquerda
    struct ArvB* irmao = no->filho[i + 1];   // Obtém o irmão à direita

    // Move a chave do nó pai para o nó filho
    filho->chave[filho->nChaves] = no->chave[i];  // A chave do nó pai que separa os dois filhos é movida para o filho

    // Move todas as chaves do irmão para o nó filho
    for(int j = 0; j < irmao->nChaves; j++){
        filho->chave[filho->nChaves + 1 + j] = irmao->chave[j];  // Posiciona as chaves do irmão após a chave movida do pai
    }

    // Se o nó não for folha, também move os ponteiros para os filhos do irmão
    if(!filho->eFolha){
        for(int j = 0; j <= irmao->nChaves; j++){
            filho->filho[filho->nChaves + 1 + j] = irmao->filho[j];  // Move os ponteiros para os filhos do irmão
        }
    }

    // Remove a chave do pai que foi movida e ajusta os ponteiros de filhos
    // Desloca as chaves no nó pai para a esquerda, sobrescrevendo a chave já movida
    for(int j = i + 1; j < no->nChaves; j++){
        no->chave[j - 1] = no->chave[j];
    }

    // Desloca os ponteiros de filhos no nó pai para a esquerda
    for(int j = i + 2; j <= no->nChaves; j++){
        no->filho[j - 1] = no->filho[j];
    }

    // Atualiza o número de chaves no nó filho após a fusão
    filho->nChaves += irmao->nChaves + 1;   // Soma as chaves do filho e do irmão + 1 chave que veio do pai
    no->nChaves--;                          // Reduz o número de chaves no nó pai

    free(irmao);                            // Libera a memória ocupada pelo nó irmão, que agora foi fundido
}

// Função para remover uma chave da Árvore B
void RemoveChave(struct ArvB* no, int k){
    // Verifica se a chave existe antes de tentar removê-la
    struct ArvB* noComChave = busca(no, k);

    if(noComChave == NULL){
        printf("A chave %d nao esta na Arvore\n", k);

        return;
    }

    int indice = 0;

    // Encontra o índice da chave a ser removida
    while(indice < no->nChaves && no->chave[indice] < k){
        indice++;
    }

    // Se a chave está presente no nó e o nó é uma folha
    if(indice < no->nChaves && no->chave[indice] == k){
        
        // Caso 1: Nó é uma folha, removemos diretamente
        if(no->eFolha){
            // Move todas as chaves após a chave removida uma posição à esquerda
            for(int i = indice + 1; i < no->nChaves; i++){
                no->chave[i - 1] = no->chave[i];
            }
            no->nChaves--;  // Atualiza o número de chaves no nó
        }
        
        // Caso 2: O nó não é uma folha, substituímos pela chave predecessora
        else{
            int pred = getPredecessor(no, indice); // Obtém o predecessor
            no->chave[indice] = pred;              // Substitui a chave pelo predecessor
            RemoveChave(no->filho[indice], pred);  // Remove o predecessor recursivamente
        }
    }

    // Caso a chave não esteja presente no nó
    else{
        // Flag para indicar se estamos no último filho
        bool flag = (indice == no->nChaves);

        // Verifica se o filho que contém a chave tem o número mínimo de chaves
        if(no->filho[indice]->nChaves < MIN + 1){
            
            // Caso 3A: Tenta pegar uma chave do irmão esquerdo, se possível
            if(indice != 0 && no->filho[indice - 1]->nChaves > MIN){
                struct ArvB* filho = no->filho[indice];
                struct ArvB* irmao = no->filho[indice - 1];

                // Move as chaves do filho para abrir espaço para a chave do irmão
                for(int i = filho->nChaves - 1; i >= 0; i--){
                    filho->chave[i + 1] = filho->chave[i];
                }

                // Se o nó filho não for folha, move os ponteiros de filhos também
                if(!filho->eFolha){
                    for(int i = filho->nChaves; i >= 0; i--){
                        filho->filho[i + 1] = filho->filho[i];
                    }
                }

                // Move a chave do pai para o filho, e a chave do irmão para o pai
                filho->chave[0] = no->chave[indice - 1];
                if(!filho->eFolha){
                    filho->filho[0] = irmao->filho[irmao->nChaves];
                }

                no->chave[indice - 1] = irmao->chave[irmao->nChaves - 1];
                filho->nChaves++;  // Incrementa o número de chaves do filho
                irmao->nChaves--;  // Decrementa o número de chaves do irmão
            }

            // Caso 3B: Se não puder pegar do irmão esquerdo, tenta pegar do direito
            else if(indice != no->nChaves && no->filho[indice + 1]->nChaves > MIN){
                struct ArvB* filho = no->filho[indice];
                struct ArvB* irmao = no->filho[indice + 1];

                // Move a chave do pai para o filho
                filho->chave[filho->nChaves] = no->chave[indice];

                // Se o filho não for folha, ajusta os ponteiros de filhos
                if(!filho->eFolha){
                    filho->filho[filho->nChaves + 1] = irmao->filho[0];
                }

                // Move a chave do irmão para o pai e ajusta o irmão
                no->chave[indice] = irmao->chave[0];
                for(int i = 1; i < irmao->nChaves; i++){
                    irmao->chave[i - 1] = irmao->chave[i];
                }

                // Ajusta os ponteiros de filhos do irmão, se necessário
                if(!irmao->eFolha){
                    for(int i = 1; i <= irmao->nChaves; i++){
                        irmao->filho[i - 1] = irmao->filho[i];
                    }
                }

                filho->nChaves++;  // Incrementa o número de chaves do filho
                irmao->nChaves--;  // Decrementa o número de chaves do irmão
            }

            // Caso 3C: Se nenhum irmão tem chaves suficientes, realiza concatenação
            else{
                if(indice != no->nChaves){
                    Merge(no, indice + 1);      // Funde com o irmão direito
                } 
                else{
                    Merge(no, indice - 1);      // Funde com o irmão esquerdo
                }
            }
        }

        // Continuação recursiva da remoção no filho correto
        if(flag && indice > no->nChaves){
            RemoveChave(no->filho[indice - 1], k);  // Caso especial: remove no último filho
        } 
        else{
            RemoveChave(no->filho[indice], k);      // Remove no filho indicado
        }
    }
}

// Função para imprimir a Árvore B
void Imprime(struct ArvB* no, int nivel){
    if(no != NULL){
        for(int i = 0; i < no->nChaves; i++){

            if(!no->eFolha){
                Imprime(no->filho[i], nivel + 1);
            }

            printf("Nivel %d: %d\n", nivel, no->chave[i]);
        }

        if(!no->eFolha){
            Imprime(no->filho[no->nChaves], nivel + 1);
        }
    }
}

// Função main
int main(){
    // Insere elementos na Árvore B
    Insere(&raiz, 10);
    Insere(&raiz, 20);
    Insere(&raiz, 5);
    Insere(&raiz, 6);
    Insere(&raiz, 12);
    Insere(&raiz, 30);
    Insere(&raiz, 7);
    Insere(&raiz, 17);
    Insere(&raiz, 13);
    Insere(&raiz, 21);
    Insere(&raiz, 37);
    Insere(&raiz, 40);      // Realiza Split 
    
    // Impressão após o fim das inserções
    printf("Arvore apos as insercoes:\n");
    Imprime(raiz, 0);
    printf("\n");

    // Tenta remover chave inexistente
    RemoveChave(raiz, 2);

    // Remove chave 17
    RemoveChave(raiz, 17);
    printf("\nArvore apos remover 17:\n");
    Imprime(raiz, 0);

    // Remove chave 10, era elemento da raiz!
    // Promoção do nó 7 é realizada
    RemoveChave(raiz, 10);
    printf("\nArvore apos remover 10:\n");
    Imprime(raiz, 0);

    return 0;
} // Fim da main

/*
// Função para redistribuir chaves entre dois nós irmãos
bool Redistribuir(struct ArvB* pai, int indice){
    struct ArvB* esq = pai->filho[indice];          // Nó filho à esquerda
    struct ArvB* dir = pai->filho[indice + 1];      // Nó filho à direita

    // Redistribui da direita para a esquerda se possível
    if(esq->nChaves < MAX){
        // Move chave do pai para o nó esquerdo
        esq->chave[esq->nChaves] = pai->chave[indice];
        esq->nChaves++;

        // Move a primeira chave do nó direito para o pai
        pai->chave[indice] = dir->chave[0];

        // Ajusta as chaves do nó direito
        for(int i = 0; i < dir->nChaves; i++){
            dir->chave[i] = dir->chave[i + 1];
        }

        dir->nChaves--;
        return true;
    }

    // Redistribui da esquerda para a direita se possível
    else if(dir->nChaves < MAX){
        // Move as chaves do nó direito para abrir espaço
        for(int i = dir->nChaves; i > 0; i--){
            dir->chave[i] = dir->chave[i - 1];
        }

        // Move chave do pai para o nó direito
        dir->chave[0] = pai->chave[indice];
        dir->nChaves++;

        // Move a última chave do nó esquerdo para o pai
        pai->chave[indice] = esq->chave[esq->nChaves - 1];

        esq->nChaves--;
        return true;
    }

    return false;
}
*/