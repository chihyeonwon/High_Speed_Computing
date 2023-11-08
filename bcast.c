#include <stdio.h>
#include <math.h>
#include "mpi.h"

int MPI_Bcast2(void *buffer, int count, MPI_Datatype datatype, MPI_Comm comm)
{
   int np, pid, N, eor_bits, partner, i, j;
   int tag = 0;
   MPI_Status status;
      
   MPI_Comm_size(MPI_COMM_WORLD, &np);
   MPI_Comm_rank(MPI_COMM_WORLD, &pid);
      
   N = (int)(log(np)/log(2)); // for any number of processes
   
   eor_bits = np;
   for (i = 0; i < N; i++) {
      eor_bits = 1 << i;
      partner = pid ^ eor_bits;
      if (pid < partner) {
         MPI_Send(buffer, count, datatype, partner, tag, comm);
         break;
      } else if (pid > partner) {
         MPI_Recv(buffer, count, datatype, partner, tag, comm, &status);
      }
   }   

   return 0;
}

int main(int argc, char* argv[])
{
   int np, pid, root, i;
   int tag = 0;
   MPI_Status status;
   int data[10];
   
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &pid);
      
   if (pid == 0)
      for (i=0; i<10; i++)
         data[i] = i+1;
                  
   MPI_Bcast2(data, 10, MPI_INT, MPI_COMM_WORLD);
      
   printf("%d: %d %d\n", pid, data[0], data[9]);
      
   MPI_Finalize();
}