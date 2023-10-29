#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h> 

double f(double x)
{
   double temp;
   temp = x*x+2; 
   return x/(temp*temp*temp); 
}

long milliseconds()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (long)(tv.tv_sec) * 1000 + (long)(tv.tv_usec) / 1000;
}

int main(int argc, char *argv[])
{ 
   int i;
   long N; 
   long I;
   int flops; 
   double a, b, area, dx, x;

   long start, elapsed;
  

   N = atol(argv[1]); 



   if(argc != 2)	{
      printf("argument error\n");
      return 1;
   }


   start = milliseconds();   
   
   a = 0.0; 
   b = 2.0; 
   dx = (b-a)/N;

   area = 0.0;

   x = a;
   
   flops = 15;
   
    for(i=0; i<N; i++) {
      area += 0.5*(f(x)+f(x+dx))*dx; 
      x += dx; 
   }
  
   elapsed = milliseconds() - start;
   
  
   printf("the calculated area is %5.10lf\n", area);


   printf("Elapsed Time is %lf ms.\n", elapsed);
   
 
   long total_operations = N * flops; 
   long gflops = (total_operations / (elapsed / 1000.0)) * 1e-9; 


   printf("GFLOPS: %lf\n", gflops);
   
   return 0;
}    
