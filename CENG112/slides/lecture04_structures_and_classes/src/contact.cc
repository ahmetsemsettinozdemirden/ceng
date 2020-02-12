#include "contact.h"

#include <iostream>

using std::cout;
using std::endl;

void print_contact(const ContactEntry &contact)
{
        cout << "(" << contact.name << " "
             << contact.surname << ", "
             << contact.tel << ")" << endl;
}

