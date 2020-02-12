#include <stdio.h>

__global__ void mykernel(void) {
int i = blockDim.x * blockIdx.x + threadIdx.x;
printf("***blockDim=%d\n",blockDim.x);
printf("***blockIdx=%d\n",blockIdx.x);
printf("***threadIdx=%d\n",threadIdx.x);
printf("***index=%d\n",i);
}

int main() {
  mykernel<<<1,1>>>();
  
  return 0;
}
