
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string filename = "D301.txt";
	ifstream file(filename, ios::in);

	string data;

	if(file){
		cout << "dosya bulunamadi: " << filename << endl;
		return 1;
	}

	file >> data;

	cout << data << endl;


	return 0;
}