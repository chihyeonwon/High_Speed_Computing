#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h> // gettimeofday 함수를 사용하기 위함

double f(double x)
{
   double temp;
   temp = x*x+2; // 1곱하기 1덧셈 -> 2
   return x/(temp*temp*temp); // 2곱하기 1나눗셈->3 함수 호출 때마다 총 개
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
   long N; // loops 수
   long I;
   int flops; // flops 수
   double a, b, area, dx, x;

   long start, elapsed;
  

   N = atol(argv[1]); // area 뒤에오는 수를 loops 수로 저장



   if(argc != 2)	{
      printf("argument error\n");
      return 1;
   }

   // 시작 시간 기록
   start = milliseconds();   
   
   a = 0.0; // 구간 시작
   b = 2.0; // 구간 끝
   dx = (b-a)/N;

   area = 0.0;

   x = a;
   
   flops = 15;
   
    for(i=0; i<N; i++) {
      area += 0.5*(f(x)+f(x+dx))*dx; // f 호출->5 * 2= 12, 덧셈 2 곱셈 2 = 14  
      x += dx; // 덧셈 1 -> 14 + 1 = 15 
   }
   // 종료 시간 기록
   elapsed = milliseconds() - start;
   
   // the calculated area 값 계산
   printf("the calculated area is %5.10lf\n", area);

   // 계산한 elapsed time 결과 출력
   printf("Elapsed Time is %lf ms.\n", elapsed);
   
   // GFLOPS 계산
   long total_operations = N * flops; // 총 연산 수 계산
   long gflops = (total_operations / (elapsed / 1000.0)) * 1e-9; // GFLOPS 계산

   // GFLOPS 결과 출력
   printf("GFLOPS: %lf\n", gflops);
   
   return 0;
}    