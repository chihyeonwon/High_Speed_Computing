#include <stdio.h>
#include "mpi.h"

#define N 5

void main(int argc, char** argv) {
   int pid, np, flag, tag = 0, i, j;
   MPI_Status status;
   MPI_Datatype index_t;
   int displacements[N];
   int block_lengths[N];

   float A[N][N], T[N][N];

   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &pid);
   MPI_Comm_size(MPI_COMM_WORLD, &np);

   for (i = 0; i < N; i++) {
      block_lengths[i] = i + 1;
      displacements[i] = i * N;
   }
   MPI_Type_indexed(N, block_lengths, displacements, MPI_FLOAT, &index_t);
   MPI_Type_commit(&index_t);

   if (pid == 0) {
      for (i = 0; i < 5; i++)
         for (j = 0; j < 5; j++)
            A[i][j] = i * N + j;
      MPI_Send(A, 1, index_t, 1, 0, MPI_COMM_WORLD);
   }

   if (pid == 1) {
      for (i = 0; i < 5; i++)
         for (j = 0; j < 5; j++)
            T[i][j] = -1.0;
      
      MPI_Recv(T, 1, index_t, 0, tag, MPI_COMM_WORLD, &status);

      for (i = 0; i < 5; i++) {
         for (j = 0; j < 5; j++) {
            printf("%2.1f ", T[i][j]);
         }
         printf("\n");
      }
   }

   MPI_Finalize();
}


