#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h> 

#define ITER_MAX 3000 
#define CONV_THRESHOLD 1.0e-5f 

double **grid;
double **new_grid;
int size;
int num_threads;

double err;
double *local_err; 

// Barreiras para sincronização
pthread_barrier_t barrier_calc;
pthread_barrier_t barrier_copy;

// Flag para sinalizar o término das threads
volatile int global_done = 0;

// return the maximum value
double max(double a, double b){
    if(a > b)
        return a;
    return b;
}

// return the absolute value of a number
double absolute(double num){
    if(num < 0)
        return -1.0 * num;
    return num;
}

// allocate memory for the grid
void allocate_memory(){
    grid = (double **) malloc(size * sizeof(double *));
    new_grid = (double **) malloc(size * sizeof(double *));

    for(int i = 0; i < size; i++){
        grid[i] = (double *) malloc(size * sizeof(double));
        new_grid[i] = (double *) malloc(size * sizeof(double));
    }
}

// free memory
void free_memory(){
    for(int i = 0; i < size; i++){
        free(grid[i]);
        free(new_grid[i]);
    }
    free(grid);
    free(new_grid);
}

// initialize the grid
void initialize_grid(){
    srand(10);
    int linf = size / 2;
    int lsup = linf + size / 10;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if ( i>=linf && i < lsup && j>=linf && j<lsup)
                grid[i][j] = 100;
            else
                grid[i][j] = 0;
            new_grid[i][j] = 0.0;
        }
    }
}

// save the grid in a file
void save_grid(){
    char file_name[30];
    sprintf(file_name, "grid_laplace_pthread.txt");
    FILE *file = fopen(file_name, "w");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            fprintf(file, "%lf ", grid[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void *worker_function(void *arg) {
    long id = (long)arg;
    int rows_to_compute = size - 2;
    int chunk_size = rows_to_compute / num_threads;
    int start_row = 1 + id * chunk_size;
    int end_row;

    if (id == num_threads - 1) {
        end_row = size - 1; 
    } else {
        end_row = 1 + (id + 1) * chunk_size;
    }

    while (1) {
        local_err[id] = 0.0;
        for (int i = start_row; i < end_row; i++) {
            for (int j = 1; j < size - 1; j++) {
                new_grid[i][j] = 0.25 * (grid[i][j+1] + grid[i][j-1] + grid[i-1][j] + grid[i+1][j]);
                
                // Calcula o erro local máximo para esta thread
                local_err[id] = max(local_err[id], absolute(new_grid[i][j] - grid[i][j]));
            }
        }

        // Sincroniza: espera todas as threads terminarem a fase de cálculo
        pthread_barrier_wait(&barrier_calc);

        for (int i = start_row; i < end_row; i++) {
            for (int j = 1; j < size - 1; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
        
        // Sincroniza: espera todas as threads terminarem a fase de cópia
        pthread_barrier_wait(&barrier_copy);

        // Verifica se a thread main sinalizou o término
        if (global_done) {
            break;
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]){

    if(argc != 3){ // Agora espera 3 argumentos: ./exec N T
        printf("Usage: ./laplace_pthread N T\n");
        printf("N: The size of each side of the domain (grid)\n");
        printf("T: The number of threads\n");
        exit(-1);
    }

    struct timeval time_start;
    struct timeval time_end;

    size = atoi(argv[1]);
    num_threads = atoi(argv[2]);

    if (num_threads > size - 2) {
        printf("Error: Number of threads (%d) cannot be greater than rows to compute (%d).\n", num_threads, size - 2);
        exit(-1);
    }

    allocate_memory();
    initialize_grid();

    // Alocar recursos para threads
    pthread_t *threads = (pthread_t *)malloc(num_threads * sizeof(pthread_t));
    local_err = (double *)malloc(num_threads * sizeof(double));

    // Inicializa as barreiras
    pthread_barrier_init(&barrier_calc, NULL, num_threads);
    pthread_barrier_init(&barrier_copy, NULL, num_threads);


    err = 1.0;
    int iter = 0;
    global_done = 0;

    // Criar as threads
    for (long i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, worker_function, (void *)i);
    }

    printf("Jacobi relaxation calculation: %d x %d grid with %d threads\n", size, size, num_threads);
    gettimeofday(&time_start, NULL);

    while ( err > CONV_THRESHOLD && iter <= ITER_MAX ) {

        // Workers
        // As threads estão executando a Fase de Cálculo
        pthread_barrier_wait(&barrier_calc);
        
        // Agora que todas terminaram, a main thread calcula o erro global
        err = 0.0;
        for (int i = 0; i < num_threads; i++) {
            err = max(err, local_err[i]);
        }

        // Workers
        // As threads estão executando a Fase de Cópia
        pthread_barrier_wait(&barrier_copy);

        // Fim da iteração
        if(iter % 100 == 0)
            printf("Error of %0.10lf at iteration %d\n", err, iter);

        iter++;
    }

    gettimeofday(&time_end, NULL);

    // Sinaliza para as threads terminarem
    global_done = 1;

    // Libera as threads das barreiras uma última vez para que possam ler 'global_done'
    pthread_barrier_wait(&barrier_calc);
    pthread_barrier_wait(&barrier_copy);

    // Aguarda (join) todas as threads terminarem
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    double exec_time = (double) (time_end.tv_sec - time_start.tv_sec) +
                       (double) (time_end.tv_usec - time_start.tv_usec) / 1000000.0;

    save_grid();

    printf("\nKernel executed in %lf seconds with %d iterations and error of %0.10lf\n", exec_time, iter, err);

    // Liberar recursos
    free_memory();
    free(threads);
    free(local_err);
    pthread_barrier_destroy(&barrier_calc);
    pthread_barrier_destroy(&barrier_copy);

    return 0;
}