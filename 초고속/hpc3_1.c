#include <stdio.h>
#include <sys/time.h>
#include <math.h>
//circle.c
#define N 500000000
#define RADIUS 100

int millisecond()
{
   struct timeval tv;

   gettimeofday(&tv, NULL);

   return (tv.tv_sec*1000 + tv.tv_usec/1000);
}

main()
{
   long i;
   double dx, x, area, y;
   int start, end;
   int pid, np;

   start = millisecond();

   area = 0.0;
   dx = (double)RADIUS/(double)N;

   #pragma omp parallel private(i, x, y, pid) shared(dx, np, area)
   {
      np = omp_get_num_threads();
      pid = omp_get_thread_num();
      x = ((double)RADIUS/(double)np) * (double)pid;

      #pragma omp for reduction(+:area)
      for(i=0; i<N; i++)
      {
         x += dx;
         y = sqrt(fabs((double)RADIUS * (double)RADIUS - x * x));
         area += dx * y;
      }
   }
   end = millisecond();

   printf("time = %d millisecond, area = %5.10f\n", end-start, area*4);
}