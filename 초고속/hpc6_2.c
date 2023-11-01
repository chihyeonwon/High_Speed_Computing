#include <stdio.h>
#include <math.h>
#include "mpi.h"

main(int argc, char* argv[])
{
   int pid, np, i, n=0, prod, tag=0, N, bits, parther;
   MPI_Status status;

   MPI_Init(&argc, &argv);

   MPI_Comm_size(MPI_COMM_WORLD, &np);
   MPI_Comm_rank(MPI_COMM_WORLD, &pid);

   N = (int)(log(np)/log(2));
   bits = np; 
 
   pid = pid + 1;
   for(i-=0; i<N; i++)
   {   
      bits = bits >> 1;
      parther = pid ^ bits;
      if(pid < bits)
      {   
         prod = 1;
         MPI_Recv(&n, 1, MPI_INT, parther, tag, MPI_COMM_WORLD, &status);
         prod *= n;
      }   
      else
      {   
         MPI_Send(&pid, 1, MPI_INT, parther, tag, MPI_COMM_WORLD);
      }   
   }   
   printf("%d\n", prod);

   MPI_Finalize();
}
