// filename: args.cc
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // This for loops iterates as 0, 1, ..., (argc-1).
    // Each iteration prints one command line argument on a
    // seperate line.
    for (int i = 0; i < argc; i++)
            cout << "[" << i << "] " << argv[i] << endl;

    // <cstdlib> header contains the constant EXIT_SUCCESS
    // which is zero. It also contains the constant
    // EXIT_FAILURE which is non-zero.
    return EXIT_SUCCESS;
}
