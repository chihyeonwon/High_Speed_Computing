#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define N 120

void main(int argc, char* argv[])
{
   float *A, sum, a;
   int i, pid;

   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &pid);

   if(pid == 0)
   {   
      A = (float *)malloc(sizeof(float)*N);
      for(i=0; i<N; i++)
         A[i] = (float)i;
   }   

   MPI_Scatter(A, 1, MPI_FLOAT, &a, 1, MPI_FLOAT, 0, MPI_COMM_WORLD); 

   sum = 0.0;
   
   MPI_Reduce(&a, &sum, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);

   if(pid == 0)
      printf("%lf\n", sum);

   free(A);
   MPI_Finalize();
}
