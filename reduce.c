#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
   int np, pid, tag =0;
   float data, local_data;
   MPI_Status status;
   

   MPI_Init(&argc,&argv);
   MPI_Comm_rank(MPI_COMM_WORLD,&pid);
   MPI_Comm_size(MPI_COMM_WORLD,&size);
   

   float data, local_data;
   
   data = pid + 100.0;

   MPI_Reduce(&local_data, &data, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
   
   if(pid ==0) printf("data is %f", data);
   
   MPI_Finalize();

   exit(0);
}