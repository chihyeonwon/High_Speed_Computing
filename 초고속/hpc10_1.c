#include <stdio.h>
#include <math.h>

#define N 1000000
#define RADIUS 100
#define THREADS 32

__global__ void area_f(float *A, float *area)
{
   __shared__ float sarea[THREADS];

   sarea[threadIdx.x] = A[threadIdx.x];
   for(int s=blockDim.x/2; s>0; s>>=1)
   {   
      if(threadIdx.x < s)
      {   
        sarea[threadIdx.x] += sarea[threadIdx.x + s]; 
        __syncthreads();
      }   
   }   

   if(threadIdx.x == 0)
      *area = sarea[threadIdx.x];
}

main()
{
   int i;
   double dx, x, gpu_area, cpu_area;
   float A[N];
   float *C_area, *area_d, *A_d;

   dim3 dimBlock(THREADS);
   dim3 dimGrid((N+dimBlock.x-1)/dimBlock.x);

   dx = (float)RADIUS/(float)N;
   x = 0.0; cpu_area = 0.0;
   for(i=1; i<N; i++)
   {   
      x += dx; 
      A[i] = sqrt(fabs((float)RADIUS * (float)RADIUS - x * x)) * dx;
      cpu_area += A[i];
   }

   cudaMalloc((void **)&A_d, sizeof(float)*N);
   cudaMalloc((void **)&area_d, sizeof(float)*dimGrid.x);

   cudaMemcpy(A_d, A, sizeof(float)*N, cudaMemcpyHostToDevice);

   area_f <<< dimGrid, dimBlock >>> (A_d, area_d);

   C_area = (float*)malloc(sizeof(float)*dimGrid.x);
   cudaMemcpy(C_area, area_d, sizeof(float)*dimGrid.x, cudaMemcpyDeviceToHost);

   gpu_area = 0.0;
   for(i=0; i<dimGrid.x; i++)
      gpu_area += (float)C_area[i];

   printf("cpu area = %5.10f\ngpu area = %5.10f\n", cpu_area*4, gpu_area*4);

   cudaFree(A_d);
   cudaFree(area_d);
   free(C_area);
}
