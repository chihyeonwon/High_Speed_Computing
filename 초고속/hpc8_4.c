#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#define N 5

main(int argc, char* argv[])
{
   int pid, i, j, tag = 0;
   MPI_Status status;
   int A[N][N], B[N];

   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &pid);
   MPI_Datatype vector_t;

   if(pid == 0)
   {   
      for(i=0; i<N; i++)
      {   
         for(j=0; j<N; j++)
         {   
            A[i][j] = i*N + j;
            printf("%4d ", A[i][j]);
         }   
         printf("\n");
      }   
      printf("------------------------\n");
   }   

   int count = N, stride = N+1, block_length = 1;
   MPI_Type_vector(count, block_length, stride, MPI_INT, &vector_t);
   MPI_Type_commit(&vector_t);

   if(pid == 0)
      MPI_Send(&(A[0][0]), 1, vector_t, 1, tag, MPI_COMM_WORLD);

   if(pid == 1)
   {   
      MPI_Recv(B, N, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
      for(i=0; i<N; i++)
         printf("%4d ", B[i]);
      printf("\n======================== \n");
   }   

   MPI_Finalize();
}
/*
   0    1    2    3    4 
   5    6    7    8    9 
  10   11   12   13   14 
  15   16   17   18   19 
  20   21   22   23   24 
------------------------
   0    6   12   18   24 
======================== 
*/