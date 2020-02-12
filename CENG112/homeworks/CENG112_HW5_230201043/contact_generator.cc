#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;

struct Contact{
	string name;
	string surname;
	string telephone;
};

void readFile(string filename, vector<string> &v);
void generateContacts(vector<string> &names, vector<string> &surnames, vector<string> &telephones, Contact contacts[]);
void writeFile(string filename, Contact contacts[]);

int main(int argc, char const *argv[]){

	// TODO: for help type -h

	if(argc != 5){
		cerr << "Usage: " << argv[0] << " <names_file> <surnames_file> <telephone_numbers_file> <contacts_output_file>" << endl;
		return 1;
	}
	
	vector<string> names;
	vector<string> surnames;
	vector<string> telephones;

	// get file names with argument
	// throw catch
	readFile(argv[1], names);
	readFile(argv[2], surnames);
	readFile(argv[3], telephones);

	Contact contacts[1000];

	generateContacts(names, surnames, telephones, contacts);

	writeFile(argv[4], contacts);

	return 0;
}

void readFile(string filename, vector<string> &v){

	string l;
	ifstream f;
	f.open(filename);

	if(f.is_open()){
		while(getline(f, l)){
			v.push_back(l);
		}
		f.close();
	}else{
		cerr << "Unable to open file" << endl; // throw catch
	}
}

void generateContacts(vector<string> &names, vector<string> &surnames, vector<string> &telephones, Contact contacts[]){
	srand(time(0));

	for(int i=0; i < 1000; i++){

		Contact randomContact;

		randomContact.name = names[rand()%names.size()];
		randomContact.surname = surnames[rand()%surnames.size()];
		randomContact.telephone = telephones[rand()%telephones.size()];

		cout << randomContact.name << " " << randomContact.surname << " " << randomContact.telephone << endl;

		contacts[i] = randomContact;
	}
}

void writeFile(string filename, Contact contacts[]){

	ofstream f;
	f.open(filename);

	if(f.is_open()){
		for(int i = 0; i < sizeof(contacts) / sizeof(contacts[0]); i++){
			f << contacts[i].name << '\n' << contacts[i].surname << '\n' << contacts[i].telephone << '\n';
		}
		f.close();
	}else{
		cerr << "Unable to open file" << endl; // throw catch
	}

}

