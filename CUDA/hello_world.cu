#include<stdio.h>
#include<cuda.h>

__global__ void dkernel(){
   printf("hello world from %d\n",threadIdx.x);
}

int main()
{
    dkernel<<<1,8>>>();
    cudaDeviceSynchronize();
    return 0;
}
