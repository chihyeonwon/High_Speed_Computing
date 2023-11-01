#include <stdio.h>

#define N 10000
#define THREAD_X 4

__global__ void index(float *A, float *B, float *C) 
{
   int i = blockDim.x * blockIdx.x + threadIdx.x;

    C[i] = A[i] + B[i]; 
}

__global__ void in(float *A, float *B) 
{
   int i = blockDim.x * blockIdx.x + threadIdx.x;
   
   A[i] = i*2;
   B[i] = N-i;
}

int main()
{
   float C[N];
   float *A_d, *B_d, *C_d;
   int i;

   dim3 dimBlock(THREAD_X);
   dim3 dimGrid(N/THREAD_X);

   cudaMalloc((void **)&A_d, sizeof(float)*N);
   cudaMalloc((void **)&B_d, sizeof(float)*N);
   cudaMalloc((void **)&C_d, sizeof(float)*N);
   
   in <<<dimGrid, dimBlock>>> (A_d, B_d);
   index <<<dimGrid, dimBlock>>> (A_d, B_d, C_d);

   cudaMemcpy(C, C_d, sizeof(int)*N, cudaMemcpyDeviceToHost);

   for(i=0; i<N; i++)
      printf("%f ", C[i]);
   printf("\n");

   cudaFree(A_d);
   cudaFree(B_d);
   cudaFree(C_d);
}
