#include	"wb.h"

const int BLUR_SIZE = 1; // distance to edge, extual blur size is 3

__global__ void bluringKernel(int imageWidth, int imageHeight, int imageChannels, float* inputImageData, float* outputImageData) {
    
    int col = blockDim.x * blockIdx.x + threadIdx.x;
    int row = blockDim.y * blockIdx.y + threadIdx.y;

    if (col < imageWidth && row < imageHeight) {

        for(int ch = 0; ch < imageChannels; ch++) {

            float data = 0;
            int dataCount = 0;

            for(int blurRow = -BLUR_SIZE; blurRow < BLUR_SIZE+1; ++blurRow) {
                for(int blurCol = -BLUR_SIZE; blurCol < BLUR_SIZE+1; ++blurCol) {
                    int curRow = row + blurRow;
                    int curCol = col + blurCol;
                    // Verify we have a valid image pixel
                    if(curRow > -1 && curRow < imageHeight && curCol > -1 && curCol < imageWidth) {
                            data += inputImageData[(curRow * imageWidth + curCol) * imageChannels + ch];
                            dataCount++; // Keep track of number of pixels(channels) in the accumulated total
                    }
                }
            }
            
            outputImageData[(row * imageWidth + col) * imageChannels + ch] = data / dataCount;
        }
    }
}

void wbImage_save(const wbImage_t& image, const char* fName) {

    std::ostringstream oss;
    oss << "P6\n" << "# Created for blurring output " << "\n" << image.width << " " << image.height << "\n" << image.colors << "\n";
    std::string headerStr(oss.str());

    std::ofstream outFile(fName, std::ios::binary);
    outFile.write(headerStr.c_str(), headerStr.size());

    const int numElements = image.width * image.height * image.channels;

    unsigned char* rawData = new unsigned char[numElements];

    for (int i = 0; i < numElements; ++i)
    {
        rawData[i] = static_cast<unsigned char>(image.data[i] * wbInternal::kImageColorLimit + 0.5f);
    }

    outFile.write(reinterpret_cast<char*>(rawData), numElements);
    outFile.close();

    delete [] rawData;
}

int main(int argc, char ** argv) {
    
    // Error code to check return values for CUDA calls
    cudaError_t err = cudaSuccess;

    char * inputImageFile;
    char * outputImageFile;
    wbImage_t inputImage;
    wbImage_t outputImage;

    float * hostInputImageData;
    float * hostOutputImageData;

    inputImageFile = argv[1];
    outputImageFile = argv[2];
    printf("Loading %s\n", inputImageFile);
    inputImage = wbImport(inputImageFile);
    hostInputImageData = wbImage_getData(inputImage);

    int imageWidth = wbImage_getWidth(inputImage);
    int imageHeight = wbImage_getHeight(inputImage);
    int imageChannels = wbImage_getChannels(inputImage);
    
    printf("%d %d %d\n", imageWidth, imageHeight, imageChannels);
    
    outputImage = wbImage_new(imageWidth, imageHeight, imageChannels);
    hostOutputImageData = wbImage_getData(outputImage);

    /*YOUR CODE FROM HERE*/

    int imageSize = imageWidth * imageHeight * imageChannels;
    size_t size = imageSize * sizeof(float);

    float* deviceInputImageData;
    float* deviceOutputImageData;

    err = cudaMalloc((void **) &deviceInputImageData, size);

    if (err != cudaSuccess)
    {
        fprintf(stderr, "Failed to allocate deviceInputImageData (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }

    err = cudaMalloc((void **) &deviceOutputImageData, size);

    if (err != cudaSuccess)
    {
        fprintf(stderr, "Failed to allocate deviceInputImageData (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }

    err = cudaMemcpy(deviceInputImageData, hostInputImageData, size, cudaMemcpyHostToDevice);

    if (err != cudaSuccess)
    {
        fprintf(stderr, "Failed to copy inputImageData from host to device (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }

    int threadsPerBlock = 16;
    dim3 dimGrid((imageWidth + threadsPerBlock - 1) / threadsPerBlock, (imageHeight + threadsPerBlock - 1) / threadsPerBlock);
    dim3 dimBlock(threadsPerBlock, threadsPerBlock);

    bluringKernel<<<dimGrid, dimBlock>>> (imageWidth, imageHeight, imageChannels, deviceInputImageData, deviceOutputImageData);
    err = cudaGetLastError();

    if (err != cudaSuccess)
    {
        fprintf(stderr, "Failed to launch bluringKernel kernel (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }

    err = cudaMemcpy(hostOutputImageData, deviceOutputImageData, size, cudaMemcpyDeviceToHost);

    if (err != cudaSuccess)
    {
        fprintf(stderr, "Failed to copy output from device to host (error code %s)!\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
    
    /*UNTIL HERE*/
    
    wbImage_save(outputImage, outputImageFile);  

    return 0;
}


 

