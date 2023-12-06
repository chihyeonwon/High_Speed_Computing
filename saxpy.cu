#include <stdio.h>
#include <math.h>

#define N 10000
#define THREADS 100

__global__ void saxpy(float *A, float *B, float X, float Y) {
   int i = blockIdx.x * blockDim.x + threadIdx.x;
}

int main() {
   float A[N], B[N], B2[N], X, Y;
   float *d_A, *d_B;  // Device pointer for B2
   int i;
    
   // Initialize A on the host (CPU)
   for (int i = 0; i < N; i++)
      A[i] = i * 2;

   X = 1.23;
   Y = 2.34;
    
   cudaSetDevice(1); //cs17 17�� Ȧ��

   // Allocate memory on the device (GPU)
   cudaMalloc((void**)&d_A, N * sizeof(float));
   cudaMalloc((void**)&d_B, N * sizeof(float));
 
    
   // (1) The array A[N] is copied from CPU to GPU to compute SAXPY.
   cudaMemcpy(d_A, A, N * sizeof(float), cudaMemcpyHostToDevice);

   // Computing A[N] By SAXPY.
   int blocks = (N + THREADS - 1) / THREADS;
   saxpy<<<blocks, THREADS>>>(d_A, d_B, X, Y);

   // (2) The array B[N] is computed by GPU and copied from GPU to CPU.
   cudaMemcpy(B, d_B, N * sizeof(float), cudaMemcpyDeviceToHost); 
  
   // (3) The array B2[N] is computed by CPU. 
   for(i=0; i<N; i++) {
      B2[i] = A[i]*X + Y; // B2 is used for checking
   }  
    
   // Check the results
   for (i = 0; i < N; i++) 
      if (fabs(B[i] - B2[i]) > 0.001954) // ������ ������ �ִ� �� �����ϴ�. 0.001�� �� i�� 6660���� 0.001���� Ŀ���� ���� ��µǰ� �˴ϴ�. �ּڰ��� 0.001954�� �����Ͽ� �ƹ��͵� ����� �����ʵ��� �����Ͽ����ϴ�. 
         printf("%d: %f %f\n", i, B[i], B2[i]);

   // Free memory on the device
   cudaFree(d_A);
   cudaFree(d_B);

   return 0; 
}
