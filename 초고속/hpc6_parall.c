#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mpi.h"

main(int argc, char* argv[])
{
   int N, pid, np, i, prod, prod2, tag = 0;
   int eor_bits, partner;
   MPI_Status status;

   MPI_Init(&argc, &argv);

   MPI_Comm_size(MPI_COMM_WORLD, &np);
   MPI_Comm_rank(MPI_COMM_WORLD, &pid);

   prod = pid + 1;

   N = (int)(log(np)/log(2));
   eor_bits = np; 
   for (i = 0; i < N; i++) {
      //if(pid < eor_bits){
         eor_bits = eor_bits >> 1;
         partner = pid ^ eor_bits;
         if (pid < eor_bits) {
            MPI_Recv(&prod2, 1, MPI_INT, partner, tag, MPI_COMM_WORLD, &status);
            prod *= prod2;
         }   
         else
            MPI_Send(&prod, 1, MPI_INT, partner, tag, MPI_COMM_WORLD);
       //} 
   }   

   if (pid == 0) printf("%d\n", prod);

   MPI_Finalize();
}
