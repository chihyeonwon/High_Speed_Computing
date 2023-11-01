#include <stdio.h>

#define N 10000
#define THREAD_X 4
__global__ void index(float *A, float *B) 
{
   int i = blockDim.x * blockIdx.x + threadIdx.x;
   float X = 1.23, Y = 2.34;

    B[i] = A[i]*X + Y;  
}

int main()
{
   float A[N], B[N];
   float *A_d, *B_d;
   int i;

   dim3 dimBlock(THREAD_X);
   dim3 dimGrid(N/THREAD_X);

   cudaMalloc((void **)&A_d, sizeof(float)*N);
   cudaMalloc((void **)&B_d, sizeof(float)*N);

   for(i=0; i<N;i++)
      A[i] = i*2;

   cudaMemcpy(A_d, A, sizeof(int)*N, cudaMemcpyHostToDevice);

   index <<<dimGrid, dimBlock>>> (A_d,B_d);

   cudaMemcpy(B, B_d, sizeof(int)*N, cudaMemcpyDeviceToHost);

   for(i=0; i<N; i++)
      printf("%lf ", B[i]);
   printf("\n");

   cudaFree(A_d);
   cudaFree(B_d);
}
