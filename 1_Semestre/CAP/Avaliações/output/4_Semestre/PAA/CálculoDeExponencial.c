// Biliotecas
#include <stdio.h>
#include <stdlib.h>

int main() {
    long long int N;

    // Leitura dos dados
    scanf("%lld", &N);

    long long int genoma1[N], genoma2[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &genoma1[i]);
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &genoma2[i]);
    }

    // Criando um mapeamento de índices de genoma1
    long long int pos[N];
    for(int i = 0; i < N; i++) {
        pos[genoma1[i]] = i;
    }

    // Reorganizando genoma2 de acordo com os índices de genoma1
    for(int i = 0; i < N; i++) {
        genoma2[i] = pos[genoma2[i]];
    }

    // Contando as inversões necessárias
    long long int result = countInversions(genoma2, N);

    // Imprimindo o resultado
    printf("%d\n", result);

    return 0;
}

// Função auxiliar para contar inversões usando merge sort
int mergeAndCount(int arr[], int temp[], int esq, int dir) {
    long long int mid, inv_count = 0;

    if(esq < dir) {
        mid = (esq + dir) / 2;

        inv_count += mergeAndCount(arr, temp, esq, mid);
        inv_count += mergeAndCount(arr, temp, mid + 1, dir);

        inv_count += merge(arr, temp, esq, mid, dir);
    }
    return inv_count;
}

// Função auxiliar para fundir as duas metades e contar inversões
long long int merge(int arr[], int temp[], int esq, int mid, int dir) {
    long long int i = esq;     // Índice inicial para a sublista esquerda
    long long int j = mid + 1; // Índice inicial para a sublista direita
    long long int k = esq;     // Índice para a sublista temporária
    int inv_count = 0;

    while(i <= mid && j <= dir) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // Todos os elementos restantes na sublista esquerda
        }
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    while(j <= dir) {
        temp[k++] = arr[j++];
    }

    for(i = esq; i <= dir; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

// Função principal para calcular as inversões necessárias
long long int countInversions(int arr[], int n) {
    long long int *temp = (int *)malloc(n * sizeof(long long int));
    long long int result = mergeAndCount(arr, temp, 0, n - 1);
    free(temp);

    return result;
}