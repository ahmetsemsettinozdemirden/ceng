
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

	// get dimensions of matrix
	int row, column;
	cin >> row >> column;

	int matrix[row][column];

	// input
	for(int i=0; i < row; i++)
		for(int j=0; j < column; j++)
			cin >> matrix[i][j];

	// output
	for(int i=0; i < column; i++){
		for(int j=0; j < row; j++){
			cout << matrix[j][i] << " ";
		}
		cout << endl;
	}

	return 0;
}
