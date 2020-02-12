#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Contact{
    unsigned long id;
    string name;
    string surname;
    string telephone;
    Contact *next;
};

Contact *hashTable[30];

void readContacts();
void readAndHashContacts();
void insertItemToHashTable(Contact *c);
void printHashTable();

int main(int argc, char const *argv[]){

    readContacts();

    cout << "Number of items in the Hash Table" << endl;
    printHashTable();

	return 0;
}

void readContacts(){

    vector<string> v;
    string l;
    ifstream f;
    f.open("contacts.txt");

    if(f.is_open()){

        while(getline(f, l)){
            v.push_back(l);
        }

        int v_size = v.size();

        for(int i = 0; i < v_size/3; i++){

            Contact *c = new Contact;

            c->telephone = v.back();
            v.pop_back();
            c->surname = v.back();
            v.pop_back();
            c->name = v.back();
            v.pop_back();
            c->id = 100000 + i;

            insertItemToHashTable(c);
        }

        f.close();
    }else{
        cerr << "Unable to open file" << endl;
    }

}

int hashFunction(unsigned long key){
	return key % 30;
}

void insertItemToHashTable(Contact *c){

    int hashValue = hashFunction(c->id);

    if (hashTable[hashValue] == 0) {
        c->next = hashTable[hashValue];
        hashTable[hashValue] = c;
    } else {
        
        Contact *p = hashTable[hashValue];
        while (p->next != 0)
            p = p->next;
        
        c->next = p->next;
        p->next = c;
    }

}

void printHashTable(){

	for (int i = 0; i < 30; ++i){

		int n = 0;
		Contact *p = hashTable[i];

	    while (p->next != 0){
	        p = p->next;
	        n++;
	    }

	    cout << i << " -> " << n << endl;
	    n = 0;
	}
}
