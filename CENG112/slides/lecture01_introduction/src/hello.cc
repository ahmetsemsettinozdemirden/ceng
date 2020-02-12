// filename: hello.cc
// This is a C++ style single-line comment.
// The following includes a header file containing
// the definition of std::cout and std::endl.
#include <iostream>

// This is necessary so that we do not have to write std::cout.
using namespace std;

// This is the main function where execution will start.
int main(int argc, char* argv[]) {
        // This outputs Hello World! followed by a newline.
        cout << "Hello World!" << endl;

        // Returning zero means no error
        return 0;
}
