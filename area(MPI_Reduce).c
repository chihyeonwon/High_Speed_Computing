#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include <sys/time.h>

long millisecond()
{
   struct timeval tv;
   gettimeofday(&tv, NULL);
   return(1000*tv.tv_sec + tv.tv_usec/1000) ;
}

double f(double x)
{
   double temp;
   temp = x*x+2;
   return x/(temp*temp*temp);
}

int main(int argc, char *argv[])
{
   long N, local_N, i;
   double a, b, area, local_area, dx, x;
   long start, elapsed;

   int pid, size;

   MPI_Init(&argc,&argv);
   MPI_Comm_rank(MPI_COMM_WORLD,&pid);
   MPI_Comm_size(MPI_COMM_WORLD,&size);
   
   if (argc != 2) {
      printf("usage:%s N\n", argv[0]);
      exit(1);
   }            

   N = atol(argv[1]);
   
   a = 0.0, b = 2.0;
   dx = (b-a)/(double)N;

   
   // calculates local area
   start = millisecond();

   local_area = 0.0;
   area = 0.0;
   
   local_N = N/(long)size;
   
   x = ((b-a)/(double)size)*(double)pid;

   
   for(i=0; i<local_N; i++) {
      local_area += 0.5*(f(x)+f(x+dx))*dx;
      x += dx;
   }

   // add local_areas onto area on p0 (by using MPI_Reduce instead of using MPI_Send, MPI_Recv)
   MPI_Reduce(&local_area, &area, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

   elapsed = millisecond() - start;

   if(pid == 0) {
      // print elapsed time and GFLOPS
      printf("area is %5.10lf\n", area);
      printf("elapsed time(MPI): %ld milliseconds\n", elapsed);
      printf("GFLOPS(MPI): %5.2f\n", (N*12.0/(elapsed/1000.0))/1000000000.0); 
   }

   MPI_Finalize();

   exit(0);
}
