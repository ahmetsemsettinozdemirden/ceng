#include <stdio.h>

__global__ void mykernel(void) {
printf("Hello World inside kernel!\n");
}

int main() {
  mykernel<<<1,1>>>();
  
  return 0;
}
