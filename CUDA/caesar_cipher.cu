#include<stdio.h>
#include<cuda.h>
#define N 1     //shift/key of cipher
 
__global__ void encrypt(char *a)
{
    a[threadIdx.x]+=N;
    if(a[threadIdx.x]>122)
    a[threadIdx.x]=200-a[threadIdx.x];
}

__global__ void decrypt(char *a)
{
    a[threadIdx.x]-=N;
    if(a[threadIdx.x]<97)
    a[threadIdx.x]=200-a[threadIdx.x];
}

int main()
{
    char a[]="teststring",*b,*c;
    c=(char*)malloc(sizeof(a));
    cudaMalloc(&b,sizeof(a));
    printf("Message : %s\n",a);
    cudaMemcpy(b,a,sizeof(a),cudaMemcpyHostToDevice);
    encrypt<<<1,sizeof(a)-1>>>(b);
    cudaMemcpy(c,b,sizeof(a),cudaMemcpyDeviceToHost);
    printf("Encrypted message is : %s\n",c);
    decrypt<<<1,sizeof(a)-1>>>(b);
    cudaMemcpy(c,b,sizeof(a),cudaMemcpyDeviceToHost);
    printf("After decrypting, message is : %s\n",c);
}