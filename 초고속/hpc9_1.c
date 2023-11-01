#include <stdio.h>

#define X 12
#define THREAD_X 4

__global__ void index(int *A) 
{
   int i = blockDim.x * blockIdx.x + threadIdx.x;
   // int i = threadIdx.x;

   //A[i] = i;
   //A[i] = gridDim.x;  //3 3 3 3
   //A[i] = blockdim.x; //4, 4, 4, 4
   A[i] = threadIdx.x; //0,1,2,3
}

int main()
{
   int A[X], *A_d;
   int i;

   dim3 dimBlock(THREAD_X);
   dim3 dimGrid(X/THREAD_X);

   cudaMalloc((void **)&A_d, sizeof(int)*X);

   for(i=0; i<X;i++)
      A[i] = -1; 

   cudaMemcpy(A_d, A, sizeof(int)*X, cudaMemcpyHostToDevice);

   index <<<dimGrid, dimBlock>>> (A_d);

   cudaMemcpy(A, A_d, sizeof(int)*X, cudaMemcpyDeviceToHost);

   for(i=0; i<X; i++)
      printf("%d ", A[i]);
   printf("\n");

   cudaFree(A_d);
}
