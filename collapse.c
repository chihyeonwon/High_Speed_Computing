#include <stdio.h>
#include <mpi.h>

#define N 12 

int main(int argc, char* argv[]) {
   int np, pid, i, tag = 0;
   MPI_Status status;

   float A[N];
   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &np);
   MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    
    
   int local_N = N/np;
   
   // 쪼개기 
   for(i = 0; i<local_N; i++)
      A[i] = pid * local_N + i;
      
   //합치기
   if(pid != 0)
      MPI_Send(A, local_N, MPI_FLOAT, 0, tag, MPI_COMM_WORLD);
   else {
      for(i=1; i<np; i++)
         MPI_Recv(A+i*local_N, local_N, MPI_FLOAT, i, tag, MPI_COMM_WORLD, &status);
         

      for(i=0; i<N; i++)
         printf("%2.1f ", A[i]);
         printf("\n");
   }
   
   MPI_Finalize();
   
}