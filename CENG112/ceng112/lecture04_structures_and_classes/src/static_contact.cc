#include <cstdlib>
#include <iostream>

#include "contact.h"

using namespace std;

int main(int argc, char** argv)
{
        ContactEntry c;

        cout << "Enter contact name: ";
        cin >> c.name;
        cout << "Enter contact surname: ";
        cin >> c.surname;
        cout << "Enter contact telephone number: ";
        cin >> c.tel;

        print_contact(c);

        return EXIT_SUCCESS;
}
