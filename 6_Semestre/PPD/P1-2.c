#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <math.h>

// Versão sequencial
void media_movel_sequencial(double *A, double *B, int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            // Primeiro elemento: média de A[0] e A[1]
            B[i] = (A[i] + A[i+1]) / 2.0;
        } else if (i == n-1) {
            // Último elemento: média de A[n-2] e A[n-1]
            B[i] = (A[i-1] + A[i]) / 2.0;
        } else {
            // Elementos do meio: média de A[i-1], A[i], A[i+1]
            B[i] = (A[i-1] + A[i] + A[i+1]) / 3.0;
        }
    }
}

// Versão paralela com OpenMP
void media_movel_paralela(double *A, double *B, int n) {
    #pragma omp parallel
    {
        #pragma omp for schedule(static)
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                B[i] = (A[i] + A[i+1]) / 2.0;
            } 
            else if (i == n-1) {
                B[i] = (A[i-1] + A[i]) / 2.0;
            } 
            else {
                B[i] = (A[i-1] + A[i] + A[i+1]) / 3.0;
            }
        }
    }
}

void inicializar_vetor(double *vetor, int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = (double)rand() / RAND_MAX * 100.0;
    }
}

int verificar_resultados(double *seq, double *par, int n) {
    for (int i = 0; i < n; i++) {
        if(fabs(seq[i] - par[i]) > 1e-10) {
            printf("Diferença na posição %d: seq=%.10f, par=%.10f\n", i, seq[i], par[i]);
            return 0;
        }
    }
    return 1;
}

int main() {
    const int N = 1000000;
    int num_threads;
    double start_time, end_time;
    
    double *A = (double*)malloc(N * sizeof(double));
    double *B_seq = (double*)malloc(N * sizeof(double));
    double *B_par = (double*)malloc(N * sizeof(double));
    
    srand(time(NULL));
    inicializar_vetor(A, N);
    
    printf("Digite o número de threads: ");
    scanf("%d", &num_threads);
    
    omp_set_num_threads(num_threads);
    
    printf("Calculando média móvel para %d elementos...\n", N);
    printf("Número de threads: %d\n\n", num_threads);
    
    // Executar versão sequencial
    start_time = omp_get_wtime();
    media_movel_sequencial(A, B_seq, N);
    end_time = omp_get_wtime();
    double tempo_seq = end_time - start_time;
    printf("Tempo sequencial: %.6f segundos\n", tempo_seq);
    
    // Executar versão paralela
    start_time = omp_get_wtime();
    media_movel_paralela(A, B_par, N);
    end_time = omp_get_wtime();
    double tempo_par = end_time - start_time;
    printf("Tempo paralelo: %.6f segundos\n", tempo_par);
    
    // Verificar resultados
    printf("\nVerificando resultados...\n");
    if (verificar_resultados(B_seq, B_par, N)) {
        printf("OK! Resultados idênticos.\n");
    } else {
        printf("ERRO! Resultados diferentes!\n");
    }

    double speedup = tempo_seq / tempo_par;
    double eficiencia = speedup / num_threads * 100.0;
    
    printf("\nMÉTRICAS DE DESEMPENHO:\n");
    printf("Speedup: %.4f\n", speedup);
    printf("Eficiência: %.2f%%\n", eficiencia);
    
    free(A);
    free(B_seq);
    free(B_par);
    
    return 0;
}