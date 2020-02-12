
#include <cstdlib>
#include <cstring>
#include <iostream>

// import header file to use external functions
#include "temp_utils.h"

using namespace std;

int main(int argc, char const *argv[])
{
	// unsigned means pozitive numbers

	// atof()

	// EXIT_FAILURE
	// EXIT_SUCCESS

	if(argc < 2){
		cout << "Usage" << argv[0] << " <temperature-in-fahr>" << endl;
		return EXIT_FAILURE;
	}

	double tempInFahr = atof(argv[1]);
	double tempInCelc = fahr_to_celc(tempInFahr);

	cout << "fahr: " << tempInFahr << " - celc: " << tempInCelc << endl;

	return EXIT_SUCCESS;
}

