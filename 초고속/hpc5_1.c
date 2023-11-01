#include <stdio.h>
#include <string.h>
#include "mpi.h"

main(int argc, char* argv[])
{
   int np, pid;
   int source, dest;
   int tag=0;

   MPI_Status status;

   char message[100];

   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &np);
   MPI_Comm_rank(MPI_COMM_WORLD, &pid);

   if(pid == 0)
   {
      sprintf(message, "Greetings from processor %d", pid);
      for(dest=1; dest < np; dest++)
         MPI_Send(message, strlen(message)+1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
   }
   else
   {
      MPI_Recv(message, 100, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
      printf("%d: %s\n", pid, message);
   }

   MPI_Finalize();
}
//----------------------------------------------------------------------------------
main(int argc, char* argv[])
{
   int np, pid;

   char hostname[6];
   char* host;

   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &np);
   MPI_Comm_rank(MPI_COMM_WORLD, &pid);

   gethostname(hostname, 6);
   host = strtok(hostname, ".");

   printf("%d %s\n", pid, host);
   MPI_Finalize();
}
