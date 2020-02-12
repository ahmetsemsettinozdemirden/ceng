// filename: fahr2celc.cc
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "temp_utils.h"
using namespace std;

int main(int argc, char** argv)
{
    if (argc < 2) {
            cerr << "Usage: " << argv[0]
                 << " <temperature-in-F>" << endl;
            return EXIT_FAILURE;
    }

    double temp_in_f = atof(argv[1]);
    double temp_in_c = fahr_to_celcius(temp_in_f);
    cout << temp_in_f << " degrees Fahrenheit is "
         << temp_in_c << " degrees Celcius" << endl;

    return EXIT_SUCCESS;
}
