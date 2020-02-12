#include	"wb.h"

const int BLUR_SIZE = 3;

__global__ void bluringKernel(int imageWidth, int imageHeight, int imageChannels, float* inputImageData, float* outputImageData) {
    
    int col = blockDim.x * blockIdx.x + threadIdx.x;
    int row = blockDim.y * blockIdx.y + threadIdx.y;

    int size = imageWidth * imageHeight * imageChannels;

    if (col < imageWidth && row < imageHeight) {

        float pixVal = 0;
        int pixels = 0;

        for(int blurRow = -BLUR_SIZE; blurRow < BLUR_SIZE+1; ++blurRow) {
            for(int blurCol = -BLUR_SIZE; blurCol < BLUR_SIZE+1; ++blurCol) {
                int curRow = row + blurRow;
                int curCol = col + blurCol;
                // Verify we have a valid image pixel
                if(curRow > -1 && curRow < imageHeight && curCol > -1 && curCol < imageWidth) {
                    pixVal += inputImageData[(curRow * imageWidth + curCol) * imageChannels];
                    pixels++; // Keep track of number of pixels in the accumulated total
                }
            }
        }

        outputImageData[(row * imageWidth + col) * imageChannels] = pixVal / pixels;
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

    size_t size = imageWidth * imageHeight * imageChannels * sizeof(float);

    float* deviceInputImageData;
    float* deviceOutputImageData;

    cudaMalloc((void **) &deviceInputImageData, size);
    cudaMalloc((void **) &deviceOutputImageData, size);

    cudaMemcpy(deviceInputImageData, hostInputImageData, size, cudaMemcpyHostToDevice);

    dim3 dimGrid(1, 1);
    dim3 dimBlock(imageWidth, imageHeight);

    bluringKernel<<<dimGrid, dimBlock>>> (imageWidth, imageHeight, imageChannels, deviceInputImageData, deviceOutputImageData);

    cudaMemcpy(hostOutputImageData, deviceOutputImageData, size, cudaMemcpyDeviceToHost);
    
    /*UNTIL HERE*/
    
    wbImage_save(outputImage, outputImageFile);    
    return 0;
}


 

