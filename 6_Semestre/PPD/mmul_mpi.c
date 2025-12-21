#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define TAM 500
#define LINHA_A TAM
#define COL_A TAM
#define COL_B TAM

#define MESTRE 0
#define DO_MESTRE 1
#define DO_TRAB 2

int main(int argc, char *argv[]) {
    int qtd_tarefas, id_tarefa, qtd_trabalhadores;
    int origem, destino, tipo_msg;
    int linhas, media_linhas, extra, desloc, i, j, k, rc;

    double A[LINHA_A][COL_A];
    double B[COL_A][COL_B];
    double C[LINHA_A][COL_B];

    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id_tarefa);
    MPI_Comm_size(MPI_COMM_WORLD, &qtd_tarefas);

    if (qtd_tarefas < 2) {
        printf("É necessário pelo menos 2 tarefas MPI. Encerrando...\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
        exit(1);
    }

    qtd_trabalhadores = qtd_tarefas - 1;

    if (id_tarefa == MESTRE) {

        printf("Programa iniciado com %d tarefas MPI.\n", qtd_tarefas);

        for (i = 0; i < LINHA_A; i++)
            for (j = 0; j < COL_A; j++)
                A[i][j] = i + j;

        for (i = 0; i < COL_A; i++)
            for (j = 0; j < COL_B; j++)
                B[i][j] = i * j;

        double inicio = MPI_Wtime();

        media_linhas = LINHA_A / qtd_trabalhadores;
        extra = LINHA_A % qtd_trabalhadores;
        desloc = 0;
        tipo_msg = DO_MESTRE;

        for (destino = 1; destino <= qtd_trabalhadores; destino++) {
            linhas = (destino <= extra) ? media_linhas + 1 : media_linhas;

            MPI_Send(&desloc, 1, MPI_INT, destino, tipo_msg, MPI_COMM_WORLD);
            MPI_Send(&linhas, 1, MPI_INT, destino, tipo_msg, MPI_COMM_WORLD);
            MPI_Send(&A[desloc][0], linhas * COL_A, MPI_DOUBLE, destino, tipo_msg, MPI_COMM_WORLD);
            MPI_Send(&B, COL_A * COL_B, MPI_DOUBLE, destino, tipo_msg, MPI_COMM_WORLD);

            desloc += linhas;
        }

        tipo_msg = DO_TRAB;

        for (i = 1; i <= qtd_trabalhadores; i++) {
            origem = i;
            MPI_Recv(&desloc, 1, MPI_INT, origem, tipo_msg, MPI_COMM_WORLD, &status);
            MPI_Recv(&linhas, 1, MPI_INT, origem, tipo_msg, MPI_COMM_WORLD, &status);
            MPI_Recv(&C[desloc][0], linhas * COL_B, MPI_DOUBLE, origem, tipo_msg, MPI_COMM_WORLD, &status);
        }

        double fim = MPI_Wtime();
        printf("Concluído em %f segundos.\n", fim - inicio);
    }

    if (id_tarefa > MESTRE) {

        tipo_msg = DO_MESTRE;

        MPI_Recv(&desloc, 1, MPI_INT, MESTRE, tipo_msg, MPI_COMM_WORLD, &status);
        MPI_Recv(&linhas, 1, MPI_INT, MESTRE, tipo_msg, MPI_COMM_WORLD, &status);
        MPI_Recv(&A, linhas * COL_A, MPI_DOUBLE, MESTRE, tipo_msg, MPI_COMM_WORLD, &status);
        MPI_Recv(&B, COL_A * COL_B, MPI_DOUBLE, MESTRE, tipo_msg, MPI_COMM_WORLD, &status);

        for (k = 0; k < COL_B; k++)
            for (i = 0; i < linhas; i++) {
                C[i][k] = 0.0;
                for (j = 0; j < COL_A; j++) {
                    C[i][k] += A[i][j] * B[j][k];
                }
            }

        tipo_msg = DO_TRAB;

        MPI_Send(&desloc, 1, MPI_INT, MESTRE, tipo_msg, MPI_COMM_WORLD);
        MPI_Send(&linhas, 1, MPI_INT, MESTRE, tipo_msg, MPI_COMM_WORLD);
        MPI_Send(&C, linhas * COL_B, MPI_DOUBLE, MESTRE, tipo_msg, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}