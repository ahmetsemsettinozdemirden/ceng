#include <cstdlib>
#include <iostream>

#include "contact_list.h"

using namespace std;

int main(int argc, char** argv)
{
        const string contacts_filename = "contacts.txt";

        ContactList contacts;
        if (contacts.read_from(contacts_filename))
                clog << "Read " << contacts.size() << " contacts from " << contacts_filename << endl;
        else
                clog << "No contacts to read!" << endl;
        while (contacts.add_from_user())
                ;
        contacts.print();
        if (!contacts.write_to(contacts_filename)) {
                cerr << "Error writing contacts to " << contacts_filename << endl;
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
}
