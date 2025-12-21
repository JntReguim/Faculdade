#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mpi.h"

void readPGM_P5_root(const char *filename, int *w, int *h, int *maxval, unsigned char **img) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) { perror("Erro ao abrir entrada"); MPI_Abort(MPI_COMM_WORLD, 1); }
    char magic[3] = {0};
    if (fscanf(fp, "%2s", magic) != 1) { fprintf(stderr, "Cabeçalho inválido\n"); MPI_Abort(MPI_COMM_WORLD, 1); }
    if (strcmp(magic, "P5") != 0) { fprintf(stderr, "Apenas P5 suportado\n"); MPI_Abort(MPI_COMM_WORLD, 1); }

    int c = getc(fp);
    while (c == '#') { while (getc(fp) != '\n'); c = getc(fp); }
    ungetc(c, fp);

    if (fscanf(fp, "%d %d %d", w, h, maxval) != 3) { fprintf(stderr, "Erro ao ler dimensões\n"); MPI_Abort(MPI_COMM_WORLD, 1); }
    fgetc(fp);

    size_t size = (size_t)(*w) * (size_t)(*h);
    *img = (unsigned char*)malloc(size);
    if (!*img) { fprintf(stderr, "Falha malloc imagem\n"); MPI_Abort(MPI_COMM_WORLD, 1); }
    if (fread(*img, 1, size, fp) != size) { fprintf(stderr, "Erro leitura dados P5\n"); MPI_Abort(MPI_COMM_WORLD, 1); }
    fclose(fp);
}

void apply_mean3x3(unsigned char *local_img, unsigned char *out, int w, int local_h) {
    if (local_h <= 0) return;
    for (int y = 1; y <= local_h; y++) {
        for (int x = 0; x < w; x++) {
            int out_idx = (y - 1) * w + x;

            if (x == 0 || x == w - 1) {
                out[out_idx] = local_img[y * w + x];
                continue;
            }
            int sum = 0;

            for (int ky = -1; ky <= 1; ky++)
                for (int kx = -1; kx <= 1; kx++)
                    sum += local_img[(y + ky) * w + (x + kx)];
            out[out_idx] = (unsigned char)(sum / 9);
        }
    }
}

void apply_sobel(unsigned char *in, unsigned char *out, int w, int local_h) {
    if (local_h <= 0) return;
    int gx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int gy[3][3] = {{1,2,1},{0,0,0},{-1,-2,-1}};
    for (int y = 0; y < local_h; y++) {
        for (int x = 0; x < w; x++) {
            int out_idx = y * w + x;

            if (x == 0 || x == w - 1 || y == 0 || y == local_h - 1) {
                out[out_idx] = in[out_idx];
                continue;
            }

            int sx = 0, sy = 0;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    int v = in[(y + ky) * w + (x + kx)];
                    sx += gx[ky+1][kx+1] * v;
                    sy += gy[ky+1][kx+1] * v;
                }
            }
            int mag = (int)(sqrt((double)(sx*sx + sy*sy)));
            if (mag > 255) mag = 255;
            out[out_idx] = (unsigned char)mag;
        }
    }
}

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc < 3) {
        if (rank == 0) fprintf(stderr, "Uso: %s entrada.pgm saida.pgm\n", argv[0]);
        MPI_Finalize();
        return 1;
    }

    if (size < 2) {
        if (rank == 0) fprintf(stderr, "Execute com pelo menos 2 processos MPI (-np 2)\n");
        MPI_Finalize();
        return 1;
    }

    const char *infile = argv[1];
    const char *outfile = argv[2];
    int w = 0, h = 0, maxval = 255;
    unsigned char *full_img = NULL;

    if (rank == 0) readPGM_P5_root(infile, &w, &h, &maxval, &full_img);

    MPI_Bcast(&w, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&h, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&maxval, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int base = h / size;
    int rem = h % size;
    int local_h = base + (rank < rem ? 1 : 0);

    int *sendcounts = NULL, *displs = NULL;
    if (rank == 0) {
        sendcounts = (int*)malloc(size * sizeof(int));
        displs = (int*)malloc(size * sizeof(int));
        int offset = 0;

        for (int r = 0; r < size; r++) {
            int rh = base + (r < rem ? 1 : 0);
            sendcounts[r] = rh * w;
            displs[r] = offset;
            offset += sendcounts[r];
        }
    }

    unsigned char *local_img_halo = (unsigned char*)calloc((size_t)(local_h + 2) * w, 1);
    unsigned char *local_after_mean = NULL;
    unsigned char *local_after_sobel = NULL;

    if (local_h > 0) {
        local_after_mean = (unsigned char*)malloc((size_t)local_h * w);
        local_after_sobel = (unsigned char*)malloc((size_t)local_h * w);
    }

    int recvcount = local_h * w;
    MPI_Scatterv(full_img, sendcounts, displs, MPI_UNSIGNED_CHAR,
                 local_img_halo + w, recvcount, MPI_UNSIGNED_CHAR,
                 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);
    double t_start = MPI_Wtime();

    int top = (rank == 0) ? MPI_PROC_NULL : rank - 1;
    int bot = (rank == size - 1) ? MPI_PROC_NULL : rank + 1;

    if (local_h > 0) {
        MPI_Sendrecv(local_img_halo + w, w, MPI_UNSIGNED_CHAR, top, 100,
                     local_img_halo, w, MPI_UNSIGNED_CHAR, top, 101,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        MPI_Sendrecv(local_img_halo + local_h * w, w, MPI_UNSIGNED_CHAR, bot, 101,
                     local_img_halo + (local_h + 1) * w, w, MPI_UNSIGNED_CHAR, bot, 100,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    } else {
        MPI_Sendrecv(NULL, 0, MPI_UNSIGNED_CHAR, top, 100,
                     NULL, 0, MPI_UNSIGNED_CHAR, top, 101,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Sendrecv(NULL, 0, MPI_UNSIGNED_CHAR, bot, 101,
                     NULL, 0, MPI_UNSIGNED_CHAR, bot, 100,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    apply_mean3x3(local_img_halo, local_after_mean ? local_after_mean : NULL, w, local_h);

    if (local_h > 0) {
        unsigned char *mean_with_halo = (unsigned char*)calloc((size_t)(local_h + 2) * w, 1);

        for (int y = 0; y < local_h; y++)
            memcpy(mean_with_halo + (y+1)*w, local_after_mean + y*w, w);


        MPI_Sendrecv(mean_with_halo + w, w, MPI_UNSIGNED_CHAR, top, 200,
                     mean_with_halo, w, MPI_UNSIGNED_CHAR, top, 201,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        MPI_Sendrecv(mean_with_halo + local_h*w, w, MPI_UNSIGNED_CHAR, bot, 201,
                     mean_with_halo + (local_h+1)*w, w, MPI_UNSIGNED_CHAR, bot, 200,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        for (int y = 1; y <= local_h; y++) {
            for (int x = 0; x < w; x++) {
                int out_idx = (y-1)*w + x;

                if (x == 0 || x == w - 1 || (y == 1 && rank == 0 && displs[rank] == 0) || (y == local_h && rank == size-1 && (displs ? displs[rank] + sendcounts[rank] == w*h : 0))) {
                    local_after_sobel[out_idx] = mean_with_halo[y*w + x];
                    continue;
                }

                int sx = 0, sy = 0;
                int gx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
                int gy[3][3] = {{1,2,1},{0,0,0},{-1,-2,-1}};

                for (int ky = -1; ky <= 1; ky++) {
                    for (int kx = -1; kx <= 1; kx++) {
                        int v = mean_with_halo[(y+ky)*w + (x+kx)];
                        sx += gx[ky+1][kx+1] * v;
                        sy += gy[ky+1][kx+1] * v;
                    }
                }

                int mag = (int)(sqrt((double)(sx*sx + sy*sy)));
                if (mag > 255) mag = 255;
                local_after_sobel[out_idx] = (unsigned char)mag;
            }
        }
        free(mean_with_halo);
    }

    double t_proc_end = MPI_Wtime();

    char header[256];
    int header_len = 0;
    if (rank == 0) {
        header_len = snprintf(header, sizeof(header), "P5\n%d %d\n%d\n", w, h, maxval);
    }

    MPI_Bcast(&header_len, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank != 0) header[0] = '\0';
    MPI_Bcast(header, header_len, MPI_CHAR, 0, MPI_COMM_WORLD);

    MPI_File fh;
    MPI_Info info = MPI_INFO_NULL;
    MPI_File_open(MPI_COMM_WORLD, outfile, MPI_MODE_CREATE | MPI_MODE_WRONLY, info, &fh);

    if (rank == 0) {
        MPI_File_write_at(fh, 0, header, header_len, MPI_CHAR, MPI_STATUS_IGNORE);
    }
    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Offset pixel_offset = 0;
    if (displs) pixel_offset = (MPI_Offset)displs[rank];
    MPI_Offset byte_offset = (MPI_Offset)header_len + pixel_offset;

    if (local_h > 0) {
        MPI_File_write_at(fh, byte_offset, local_after_sobel, (MPI_Count)(local_h * w), MPI_UNSIGNED_CHAR, MPI_STATUS_IGNORE);
    }

    MPI_File_close(&fh);

    double t_end = MPI_Wtime();

    if (rank == 0) {
        printf("T_total (incl. IO): %f s\n", t_end - t_start);
        printf("T_proc (comunicações+filtros): %f s\n", t_proc_end - t_start);
    }

    if (full_img) free(full_img);
    if (sendcounts) free(sendcounts);
    if (displs) free(displs);
    if (local_img_halo) free(local_img_halo);
    if (local_after_mean) free(local_after_mean);
    if (local_after_sobel) free(local_after_sobel);

    MPI_Finalize();
    return 0;
}