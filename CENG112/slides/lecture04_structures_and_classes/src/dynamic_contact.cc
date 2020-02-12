#include <cstdlib>
#include <iostream>

#include "contact.h"

using namespace std;

ContactEntry *read_contact()
{
        ContactEntry *c = new ContactEntry;
        // c->name is shorthand for (*c).name
        cout << "Enter contact name: ";
        cin >> c->name;
        cout << "Enter contact surname: ";
        cin >> c->surname;
        cout << "Enter contact telephone number: ";
        cin >> c->tel;

        return c;
}

int main(int argc, char** argv)
{
        ContactEntry *c = read_contact();
        print_contact(*c);
        delete c;

        return EXIT_SUCCESS;
}
