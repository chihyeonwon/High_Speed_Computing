#define N 8
int printf(char *, ...);

void swap(int *a, int *b) {
   int temp;
   temp = a;
   *a = *b;
   *b = temp;
}

main()
{
   int A[N], stage, i;
   
   for(i=0; i < N; i++) 
      A[i] = N-i;
      
   for(stage = 0; stage < N; stage++)
      if(stage % 2 == 1)
         for(i = 1; i < N; i += 2)
            if(A[i-1] > A[i])
               swap(&A[i], &A[i-1]);
      else
         for(i = 1; i < N-1; i +=2)
            if(A[i] > A[i+1])
               swap(&A[i], &A[i+1]);
   
   for(i = 0; i < N; i++) {
      printf("%d ", A[i]);
      printf("\n");
   }
}