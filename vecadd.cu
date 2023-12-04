#include <stdio.h>
#define THREADS 10
#define N 10000

__global__ void vecAdd(float *A, float*B, float *C)
{
   int i = blockDim.x * blockIdx.x + threadIdx.x;
   if(i < N)
      C[i] = A[i] + B[i];
}

int main()
{
   float A[N], B[N], C[N], C2[N], *A_d, *B_d, *C_d;
   int i;
   
   dim3 dimBlock(THREADS);
   dim3 dimGrid((N+dimBlock.x-1)/dimBlock.x);
   cudaSetDevice(1); // or 1

   for (i=0; i<N; i++) {
      A[i] = i*2;
      B[i] = N-i;
      C2[i] = A[i] + B[i]; // C2 is used to check the results
   }


   // allocate array on device
   cudaMalloc((void**)&A_d, sizeof(float)*N);
   cudaMalloc((void**)&B_d, sizeof(float)*N);
   cudaMalloc((void**)&C_d, sizeof(float)*N);


   // copy array from host memory to device memory   
   cudaMemcpy(A_d, A, sizeof(float)*N, cudaMemcpyHostToDevice);
   cudaMemcpy(B_d, B, sizeof(float)*N, cudaMemcpyHostToDevice);

   // call GPU function(vecAdd)
   vecAdd<<<dimGrid, dimBlock>>>(A_d, B_d, C_d);

   // Copy the result back
   cudaMemcpy(C, C_d, sizeof(float)*N, cudaMemcpyDeviceToHost);

   // Check the results
   for (i=0; i<N; i++)
      if (C[i] != C2[i]) printf("%d %f %f\n", i, C[i], C2[i]);

   // free memory on the device
   cudaFree(A_d);
   cudaFree(B_d);
   cudaFree(C_d);

   return 0;
}