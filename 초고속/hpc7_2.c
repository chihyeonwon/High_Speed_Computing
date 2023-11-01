#include <mpi.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>

#define N 10000000000
#define RADIUS 100

int millisecond()
{
   struct timeval tb; 
   gettimeofday( &tb, 0 );

   return(1000*tb.tv_sec + tb.tv_usec/1000);
}

main(int argc, char *argv[])
{
   int np, pid, M;
   int source, dest;
   int tag = 0, eor_bits, partner;
   MPI_Status status;

   long i;
   double w, x, y, area, local_area;
   int local_N;
   int start, end;

   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &pid);
   MPI_Comm_size(MPI_COMM_WORLD, &np);

   start = millisecond();

   M = (int)(log(np)/log(2));
   eor_bits = np; 

   local_N = N/np;
   local_area = 0.0;
   w = (double)RADIUS/(double)N;
   x = ((double)RADIUS/(double)np)*(double)pid;

   for (i=1; i<local_N; i++) {
      x += w;
      y = sqrt(fabs((double)RADIUS*(double)RADIUS-x*x));
      local_area +=  w * y;
   }   
   for (i = 0; i < M; i++) {
         eor_bits = eor_bits >> 1;
         partner = pid ^ eor_bits;
         if (pid < eor_bits) {
            MPI_Recv(&local_area, 1, MPI_INT, partner, tag, MPI_COMM_WORLD, &status);
            area += local_area;
         }   
         else
            MPI_Send(&local_area, 1, MPI_INT, partner, tag, MPI_COMM_WORLD);
   }

   end = millisecond();

   if (pid == 0) {
      printf("time: %d milliseconds, area: %f\n", end-start, area*4);
   }

   MPI_Finalize();

   return 0;;
}
