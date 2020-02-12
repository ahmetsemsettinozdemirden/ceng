#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){
	srand(time(0));
	
	fstream fout("numbers.txt", fstream::out);
	int mobileCodes[40] = { 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559 };

	int r = 0;

	for(int i = 0; i < 10000; i++){
		r = rand()%40;

		string randomNumber = "90" + to_string(mobileCodes[r]);

		for(int j = 0; j < 7; j++){
			r = rand()%10;
			randomNumber += to_string(r);
		}

		randomNumber += '\n';
		fout << randomNumber;
	}

	return 0;
}