// Bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Função para mesclar e contar as inversões
long long int merge(long long int arr[], long long int temp[], long long int esq, long long int mid, long long int dir) {
    long long int i = esq;     // Índice para a sublista da esquerda
    long long int j = mid + 1; // Índice para a sublista da direita
    long long int k = esq;     // Índice para a sublista temporária
    long long int inv_count = 0;

    // Mescla as duas metades enquanto conta as inversões
    while(i <= mid && j <= dir) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // Todas as entradas restantes em arr[i...mid] são maiores que arr[j]
        }
    }

    // Copia os elementos restantes da sublista esquerda, se houver
    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copia os elementos restantes da sublista direita, se houver
    while(j <= dir) {
        temp[k++] = arr[j++];
    }

    // Copia os elementos de volta para o array original
    for(i = esq; i <= dir; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

// Função auxiliar para contar inversões usando merge sort
long long int mergeAndCount(long long int arr[], long long int temp[], long long int esq, long long int dir) {
    long long int mid, inv_count = 0;

    if(esq < dir) {
        mid = (esq + dir) / 2;

        // Contando inversões na metade esquerda e direita
        inv_count += mergeAndCount(arr, temp, esq, mid);
        inv_count += mergeAndCount(arr, temp, mid + 1, dir);

        // Contando inversões durante a fusão
        inv_count += merge(arr, temp, esq, mid, dir);
    }

    return inv_count;
}

// Função principal
int main() {
    long long int N;

    // Leitura dos dados
    scanf("%lld", &N);

    long long int *genoma1 = (long long int *)malloc(N * sizeof(long long int));
    long long int *genoma2 = (long long int *)malloc(N * sizeof(long long int));

    // Lê os dois genomas
    for(long long int i = 0; i < N; i++) {
        scanf("%lld", &genoma1[i]);
    }
    for(long long int i = 0; i < N; i++) {
        scanf("%lld", &genoma2[i]);
    }

    // Criando um mapeamento de índices de genoma1
    long long int *pos = (long long int *)malloc(N * sizeof(long long int));
    for(long long int i = 0; i < N; i++) {
        pos[genoma1[i]] = i;
    }

    // Reorganizando genoma2 de acordo com os índices de genoma1
    for(long long int i = 0; i < N; i++) {
        genoma2[i] = pos[genoma2[i]];
    }

    // Criando o vetor temporário para o merge sort
    long long int *temp = (long long int *)malloc(N * sizeof(long long int));

    // Contando as inversões necessárias
    long long int result = mergeAndCount(genoma2, temp, 0, N - 1);

    // Imprimindo o resultado
    printf("%lld\n", result);

    // Liberando a memória alocada
    free(genoma1);
    free(genoma2);
    free(pos);
    free(temp);

    return 0;
}