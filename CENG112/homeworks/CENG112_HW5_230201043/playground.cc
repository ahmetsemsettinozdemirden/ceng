#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int less_than(string i0, string i1) { return i0 > i1; }
void exchange(string *x, int i, int j);
void selection_sort(string *x, int l, int r);

int main(int argc, char const *argv[])
{
	
	fstream fin("numbers.txt", fstream::in);

	string x[10000];
	int i = 0;

	string l;
	if(fin.is_open()){
		while(getline(fin, l)){
			x[i] = l;
			i++;
		}
		fin.close();
	}else{
		cout << "Unable to open file" << endl; // throw catch
	}

    selection_sort(x, 0, 10000);

    fstream fout("numberssorted.txt", fstream::out);

	while (i > 0) {
	    fout << x[i] << '\n';
	    i--;
	}
	fout.close();

	return 0;
}

void exchange(string *x, int i, int j)
{
	string t = x[i];
	x[i] = x[j];
	x[j] = t;
}

void selection_sort(string *x, int l, int r)
{
	for (int i = l; i < r; ++i) {
		int min_id = i;
		for (int j = i+1; j <= r; ++j) {
			if (less_than(x[j], x[min_id]))
		        min_id = j;
		}
		exchange(x, min_id, i);
	}
}
