#include "mpi.h"
#include "assert.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);
    int rank, size;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    double msg[2] = {1,1};

    if (rank > 0) {
        double fibs[2];
        do {
            MPI_Recv(fibs, 2, MPI_DOUBLE,
            MPI_ANY_SOURCE, /*tag*/ 0,
            MPI_COMM_WORLD, &status);
        }
        while (status.MPI_ERROR);

        double next = fibs[0] + fibs[1];
        msg[0] = fibs[1]; msg[1] = next;
        printf("The %dth Fibonacci number is%g.\n", rank+2, next);
        }

    if (rank+1 < size) {
        int ret;
        ret = MPI_Send(msg, 2, MPI_DOUBLE,/*dest*/ rank + 1, /*tag*/ 0, MPI_COMM_WORLD);
        assert(ret == MPI_SUCCESS);
    }
    
    MPI_Finalize();
    return 0;
}