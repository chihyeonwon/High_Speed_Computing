#define N 1000000

main()
{
   double oscillation, sum;
   int i;
   
   oscillation = 1.0;
   sum = 0.0
   for(i = 0; i < N; i++) {
      sum += oscillation/(2 * i + 1);
      oscillation = -oscillation;
   }
   printf("%f\n", 4.0 * sum);
}