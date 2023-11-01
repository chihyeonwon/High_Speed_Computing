#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
//cc -fopenmp dotprod_omp.c
#define N 50000000
#define M 1000

int millisecond()
{
   struct timeval tv;

   gettimeofday(&tv, NULL);

   return (tv.tv_sec*1000 + tv.tv_usec/1000);
}

main()
{
   double *A, *B, dotprod;
   double MFLOPS = 0.0;
   int start, end, time;
   unsigned int i;

   A = malloc(sizeof(double)*N);
   B = malloc(sizeof(double)*N);

   start = millisecond();

   #pragma omp parallel for private(i)
   for(i=0; i<N; i++)
   {
      A[i] = i * 0.000000000001;
      B[i] = i * 0.000000000002 + 3.0;
   }

   dotprod = 0.0;
   #pragma omp parallel for reduction(+:dotprod)
   for(i=0; i<N; i++)
      dotprod += A[i] * B[i];


   end = millisecond();
   time = end - start;

   MFLOPS = (5.0 * N)/(double)(time*M);

   printf("time = %d millisecond\ndotprod = %.10lf\n", time, dotprod);
   printf("MFLOPS = %lf\n", MFLOPS);

   free(A);
   free(B);
}
