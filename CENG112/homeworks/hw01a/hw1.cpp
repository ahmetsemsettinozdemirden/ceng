
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]){
	
	if(argc < 2){
		cout << "Usage " << argv[0] << " <operator (x|+)> *[numbers]" << endl;
		return EXIT_FAILURE;
	}
	
	int result;
	
	if(strcmp(argv[1], "x") == 0){

		result = 1;

		for(int i=2; i < argc; i++){
			result *= atof(argv[i]);
		}

	}else if(strcmp(argv[1], "+") == 0){

		result = 0;

		for(int i=2; i < argc; i++){
			result += atof(argv[i]);
		}

	}else{
		cerr << "Invalid arguement usage!" << endl;
		return EXIT_FAILURE;
	}

	cout << "result: " << result << endl;

	return EXIT_SUCCESS;
}
