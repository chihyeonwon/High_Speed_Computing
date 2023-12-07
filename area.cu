#include <stdio.h>
#include <math.h>

#define N 1280000
#define THREADS 128

__device__ float f(float x)
{
    // (1) COMPLETE f(x) 함수를 정의
   float temp;
   temp = x*x+2; 
   return x/(temp*temp*temp);
}

__global__ void area_kernel(float *sums)
{
    float a, b, dx, x, y;
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    __shared__ float sdata[THREADS];

    // (2) COMPLETE: a,b사이의 넓이를 계산한다.
    a = 0.0;
    b = 2.0;
    dx = (b - a) / N;

    x = a  + i * dx;
    y = f(x);

    // 각스레드들의 값을 합한다.
    sdata[threadIdx.x] = 0.5 * dx * (y + f(x + dx));

    // Synchronize threads before reduction
    __syncthreads();

    // doreduce in shared memory
    for (unsigned int s=blockDim.x/2; s>0; s>>=1)
    {
        if (threadIdx.x < s)
        {
            sdata[threadIdx.x] += sdata[threadIdx.x + s];
            __syncthreads();
        }
    }

    // write result for this block to global memory
    if (threadIdx.x == 0)
    {
        sums[blockIdx.x] = sdata[0];
    }
}

int main()
{
   float *sums, *sums_d, area, elapsed;
   int i;
    
   dim3 dimBlock(THREADS);
   dim3 dimGrid((N + dimBlock.x - 1) / dimBlock.x);
   cudaEvent_t start, stop;
   
   cudaMalloc((void **)&sums_d, sizeof(float) * dimGrid.x);
   sums = (float *)malloc(sizeof(float) * dimGrid.x);
    

   // (3) COMPLETE (timing -start)
   cudaEventCreate(&start);
   cudaEventCreate(&stop);
   cudaEventRecord(start, 0);

   // (4) COMPLETE: call GPU function
   area_kernel<<<dimGrid, dimBlock>>>(sums_d);

   // Copy values from GPU memory to CPU memory
   cudaMemcpy(sums, sums_d, sizeof(float) * dimGrid.x, cudaMemcpyDeviceToHost);
    
   // (5) COMPLETE: timing -stop
   cudaEventRecord(stop, 0);
   cudaEventSynchronize(stop);
   cudaEventElapsedTime(&elapsed, start, stop);
    
   cudaEventDestroy(start);
   cudaEventDestroy(stop);

   // add the computed value to the value of pi
   area = 0.0;
   for (i = 0; i < dimGrid.x; i++)
      area += sums[i];

   printf("area: %5.10f\n", area);
   printf("elapsed time: %f milliseconds\n", elapsed);
   printf("GFLOPS: %5.2f\n", (N * 12.0 / (elapsed / 1000.0)) / 1000000000.0); // I changed #Flops 16 to 12, because my prgram's #flops is 12.

   cudaFree(sums_d);
   free(sums);
    
   return 0;
}
