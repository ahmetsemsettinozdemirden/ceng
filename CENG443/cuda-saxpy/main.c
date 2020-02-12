#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "wb.h"
#include <cuda_runtime.h>
#include <math.h>

__global__ void saxpy(int numElements, int A, const float *x, const float *y, float *result) {
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    if (i < numElements) {
        result[i] = A * x[i] + y[i];
    }
}

void printGPUDetails(int argc, char* argv[]);

int main(int argc, char* argv[]) {

    printGPUDetails(argc, argv);

    if (argc != 3) {
        printf("please type ./program <size of arrays> <scalar value>");
        return EXIT_FAILURE;
    }

    cudaError_t err = cudaSuccess;
    const int numOfElements = atoi(argv[1]);
    const int A = atoi(argv[2]);
    printf("numOfElements: %d, A: %d", numOfElements, A);

    size_t size = numOfElements * sizeof(float);

    float *x = malloc(size);
    float *y = malloc(size);
    float *result = malloc(size);

    srand(time(0));
    for (int i = 0; i < numOfElements; ++i) {
        x[i] = rand();
        y[i] = rand();
    }

    // Verify that allocations succeeded
    if (x == NULL || y == NULL || result == NULL)
    {
        fprintf(stderr, "Failed to allocate host vectors!\n");
        return EXIT_FAILURE;
    }

    // Allocate the device input vector A
    float *d_x = NULL;
    err = cudaMalloc((void **)&d_x, size);
    if (err != cudaSuccess) {
        fprintf(stderr, "Failed to allocate device vector x (error code %s)!\n", cudaGetErrorString(err));
        return EXIT_FAILURE;
    }

    // Allocate the device input vector B
    float *d_y = NULL;
    err = cudaMalloc((void **)&d_y, size);
    if (err != cudaSuccess) {
        fprintf(stderr, "Failed to allocate device vector y (error code %s)!\n", cudaGetErrorString(err));
        return EXIT_FAILURE;
    }

    // Allocate the device output vector C
    float *d_result = NULL;
    err = cudaMalloc((void **)&d_result, size);
    if (err != cudaSuccess) {
        fprintf(stderr, "Failed to allocate device vector result (error code %s)!\n", cudaGetErrorString(err));
        return EXIT_FAILURE;
    }

    printf("Copy input data from the host memory to the CUDA device\n");
    err = cudaMemcpy(d_x, x, size, cudaMemcpyHostToDevice);
    if (err != cudaSuccess) {
        fprintf(stderr, "Failed to copy vector A from host to device (error code %s)!\n", cudaGetErrorString(err));
        return EXIT_FAILURE;
    }

    err = cudaMemcpy(d_y, y, size, cudaMemcpyHostToDevice);
    if (err != cudaSuccess) {
        fprintf(stderr, "Failed to copy vector B from host to device (error code %s)!\n", cudaGetErrorString(err));
        return EXIT_FAILURE;
    }

    // Launch the Vector Add CUDA Kernel
    int threadsPerBlock = 256;
    int blocksPerGrid = (numOfElements + threadsPerBlock - 1) / threadsPerBlock;
    printf("CUDA kernel launch with %d blocks of %d threads\n", blocksPerGrid, threadsPerBlock);
    saxpy<<<blocksPerGrid, threadsPerBlock>>>(numOfElements, A, d_x, d_y, d_result);
    err = cudaGetLastError();
    if (err != cudaSuccess) {
        fprintf(stderr, "Failed to launch saxpy kernel (error code %s)!\n", cudaGetErrorString(err));
        return EXIT_FAILURE;
    }

    printf("Copy output data from the CUDA device to the host memory\n");
    err = cudaMemcpy(result, d_result, size, cudaMemcpyDeviceToHost);
    if (err != cudaSuccess) {
        fprintf(stderr, "Failed to copy vector C from device to host (error code %s)!\n", cudaGetErrorString(err));
        return EXIT_FAILURE;
    }

    // print result vector
    for (int i = 0; i < numOfElements; ++i) {
        if (fabs((A * x[i] + y[i]) - result[i]) > 1e-5) {
            fprintf(stderr, "Result verification failed at element %d!\n", i);
            return EXIT_FAILURE;
        }
    }

    // Free device global memory
    err = cudaFree(d_x);
    if (err != cudaSuccess) {
        fprintf(stderr, "Failed to free device vector x (error code %s)!\n", cudaGetErrorString(err));
        return EXIT_FAILURE;
    }

    err = cudaFree(d_y);
    if (err != cudaSuccess) {
        fprintf(stderr, "Failed to free device vector y (error code %s)!\n", cudaGetErrorString(err));
        return EXIT_FAILURE;
    }

    err = cudaFree(d_result);
    if (err != cudaSuccess) {
        fprintf(stderr, "Failed to free device vector result (error code %s)!\n", cudaGetErrorString(err));
        return EXIT_FAILURE;
    }

    // Free host memory
    free(x);
    free(y);
    free(result);

    printf("saxpy calculation completed!\n");
    return EXIT_SUCCESS;
}

void printGPUDetails(int argc, char* argv[]) {

    int deviceCount;
    wbArg_read(argc, argv);
    cudaGetDeviceCount(&deviceCount);
    wbTime_start(GPU, "Getting GPU Data.");

    for (int dev = 0; dev < deviceCount; dev++) {

        cudaDeviceProp deviceProp;
        cudaGetDeviceProperties(&deviceProp, dev);

        if (dev == 0) {
            if (deviceProp.major == 9999 && deviceProp.minor == 9999) {
                wbLog(TRACE, "No CUDA GPU has been detected");
                return EXIT_FAILURE;
            } else if (deviceCount == 1) {
                wbLog(TRACE, "There is 1 device supporting CUDA");
            } else {
                wbLog(TRACE, "There are ", deviceCount, " devices supporting CUDA");
            }
        }

        wbLog(TRACE, "Device ", dev, " name: ", deviceProp.name);
        wbLog(TRACE, " Computational Capabilities: ", deviceProp.major, ".", deviceProp.minor);
        wbLog(TRACE, " Maximum global memory size: ", deviceProp.totalGlobalMem);
        wbLog(TRACE, " Maximum constant memory size: ", deviceProp.totalConstMem);
        wbLog(TRACE, " Maximum shared memory size per block: ", deviceProp.sharedMemPerBlock);
        wbLog(TRACE, " Maximum block dimensions: ", deviceProp.maxThreadsDim[0], " x ", deviceProp.maxThreadsDim[1], " x ", deviceProp.maxThreadsDim[2]);
        wbLog(TRACE, " Maximum grid dimensions: ", deviceProp.maxGridSize[0], " x ", deviceProp.maxGridSize[1], " x ", deviceProp.maxGridSize[2]);
        wbLog(TRACE, " Warp size: ", deviceProp.warpSize);
    }

    wbTime_stop(GPU, "Getting GPU Data.");
}