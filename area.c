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
   long N, i;
   double a, b, area, local_area, dx, x;
   long start, elapsed;
   int nt, tid;

   int pid, size;

   MPI_Init(&argc,&argv);
   MPI_Comm_rank(MPI_COMM_WORLD,&pid);
   MPI_Comm_size(MPI_COMM_WORLD,&size);
   
   if (argc != 2) {
      printf("usage:%s N\n", argv[0]);
      exit(1);
   }            

   N = atol(argv[1]);

   // sequential calculation of area
   start = millisecond();
   a = 0.0;
   b = 2.0;
   dx = (b-a)/(double)N;

   area = 0.0;

   x = a;
   for (i=0; i<N; i++) {
      area += 0.5*(f(x)+f(x+dx))*dx;
      x += dx;
   }

   elapsed = millisecond() - start;

   printf("%5.10lf\n", area);
   printf("elapsed time: %ld milliseconds\n", elapsed);
   printf("GFLOPS: %10.2f\n", (N*16.0/(elapsed/1000.0))/1000000000.0);


   // calculates local area
   MPI_Barrier(MPI_COMM_WORLD);
   start = millisecond();

   double local_a = ((b-a)/size)*pid;
   double local_b = ((b-a)/size)*(pid+1);

   local_area = 0.0;
   
    
   x = local_a;
   for(i=0; i<N; i++) {
      local_area += 0.5*(f(x)+f(x+dx))*dx;
      x += dx;
   }

   // add local_areas onto area on p0 (pid==0. tag = 17)
   if(pid == 0) {
      for(i=1; i<size; i++) {
         MPI_Recv(&local_area, 1, MPI_DOUBLE, i, 17, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
         area += local_area;
      }
      
      area += local_area;
      
   } else {
      MPI_Send(&local_area, 1, MPI_DOUBLE, 0, 17, MPI_COMM_WORLD);
   }

   elapsed = millisecond() - start;

   if(pid == 0) {
      // print elapsed time and GFLOPS
      printf("elapsed time(MPI): %ld milliseconds\n", elapsed);
      printf("GFLOPS(MPI): %5.2f\n", (N*12.0/(elapsed/1000.0))/1000000000.0); 
   }

   MPI_Finalize();

   exit(0);
}