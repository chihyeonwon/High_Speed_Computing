#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include "mpi.h"
#define N 200000000

int millisecond()
{
   struct timeval tv; 

   gettimeofday(&tv, NULL);

   return (tv.tv_sec*1000 + tv.tv_usec/1000);
}

main(int argc, char* argv[])
{
   double *A, *B, *local_A, *local_B, dotprod, local_dotprod;
   int start, end, time, np, pid, len;
   long i;

   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &np);
   MPI_Comm_rank(MPI_COMM_WORLD, &pid);

   if(pid == 0)
   {   
      A = malloc(sizeof(double)*N);
      B = malloc(sizeof(double)*N);

      for(i=0; i<N; i++)
      {   
         A[i] = i * 0.000000000001;
         B[i] = i * 0.000000000002 + 3.0;
      }   
   }   
 
   len = N/np;

   local_A = malloc(sizeof(double)*len);
   local_B = malloc(sizeof(double)*len);

   start = millisecond();
   local_dotprod = 0.0; 

   MPI_Scatter(A, len, MPI_DOUBLE, local_A, len, MPI_DOUBLE, 0, MPI_COMM_WORLD);
   MPI_Scatter(B, len, MPI_DOUBLE, local_B, len, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  
   for(i=0; i<len; i++)
     local_dotprod += local_A[i] * local_B[i];
   dotprod = 0.0;

   MPI_Reduce(&local_dotprod, &dotprod, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

   end = millisecond();
   time = end - start;
   if(pid == 0)
      printf("time = %d millisecond\ndotprod = %.10lf\n", time, dotprod);

   MPI_Finalize();
}
