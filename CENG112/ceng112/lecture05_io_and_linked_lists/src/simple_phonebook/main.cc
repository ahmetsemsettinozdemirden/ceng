#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct ContactItem {
        string name;
        string tel_no;
};

int main(int argc, char** argv)
{
        string contacts_filename = "contacts.txt";
        vector<ContactItem> contacts;

        ifstream fin(contacts_filename.c_str());
        if (fin.is_open()) {
                while (true) {
                        ContactItem c;
                        getline(fin, c.name, ':');
                        getline(fin, c.tel_no);
                        if (fin.fail())
                                break;
                        contacts.push_back(c);
                }
                clog << "Read " << contacts.size() << " contacts from file " << contacts_filename << endl;
        } else {
                clog << "No contacts to read!" << endl;
        }
        fin.close();

        while (true) {
                ContactItem c;
                cout << "Enter name (\"q\" to quit): ";
                cin >> c.name;
                if (c.name == "q")
                        break;
                cout << "Enter telephone number: ";
                cin >> c.tel_no;
                contacts.push_back(c);
        }

        for (size_t i = 0; i < contacts.size(); ++i)
                cout << contacts[i].name << " -> " << contacts[i].tel_no << endl;

        ofstream fout(contacts_filename.c_str());
        if (fout.is_open()) {
                for (size_t i = 0; i < contacts.size(); ++i)
                        fout << contacts[i].name << ":" << contacts[i].tel_no << endl;
        } else {
                cerr << "Error opening contacts file " << contacts_filename << " for writing" << endl;
                return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
}
