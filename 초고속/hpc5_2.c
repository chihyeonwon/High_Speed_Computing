#include <stdio.h>
#include "mpi.h"

main(int argc, char* argv[])
{
   int np, pid;
   int source, dest;
   int tag=0, i, len;
   int temp[24];
   int a[24], b[24];
   MPI_Status status;

   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &np);
   MPI_Comm_rank(MPI_COMM_WORLD, &pid);
   len = 24/np;

   if(pid == 0)
   {   
      for(i=0; i<24; i++)
      {   
         a[i] = i+10; b[i] = i + 20; 
      }   
      for(i=0; i< len; i++)
         a[i] += b[i];

      for(dest=1; dest < np; dest++)
      {   
         MPI_Send(a+dest*len, len, MPI_INT, dest, tag, MPI_COMM_WORLD);
         MPI_Send(b+dest*len, len, MPI_INT, dest, tag, MPI_COMM_WORLD);
      }   

      for(source=1; source < np; source++)
         MPI_Recv(a+source*len, len, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
    
   }   
   else
   {   
      MPI_Recv(a, len, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
      MPI_Recv(b, len, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);

      for(i=0; i< len; i++)
         a[i] += b[i];

      MPI_Send(a, len, MPI_INT, 0, tag, MPI_COMM_WORLD);
   }

   if(pid == 0)
      for(i =0; i<24; i++)
         printf("%d\n", a[i]);

   MPI_Finalize();
}
