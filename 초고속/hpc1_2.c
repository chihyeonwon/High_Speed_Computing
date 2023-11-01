#include <stdio.h>
#include <math.h>
#define N 100000000

int main()
{
   double area=0.0;
   double i;
   unsigned int  start, end;

   start = millisecond();
   for(i=1; i<=N; i++)
      area += sqrt(1-(i/N)*(i/N))/N;
   end = millisecond();

   printf("%.10f\n time = %d\n",4* area, end-start);
}
//------------------------------------------------------
#include <stdio.h>
#include <sys/time.h>

int millisecond()
{
        struct timeval tv;
        gettimeofday(&tv, NULL);

        return (tv.tv_sec*1000 + tv.tv_usec/1000);
}


areasecond: area.o millisecond.o
        cc -o areasecond area.o millisecond.o -lm -fopenmp

area.o: area.c
        cc -c area.c

millisecond.o: millisecond.c
        cc -c millisecond.c

clean:
        rm -f *.o

run:
        @areasecond; echo $?
        