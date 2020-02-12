#ifndef CONTACT_H
#define CONTACT_H

#include <string>

struct ContactEntry {
        std::string name;
        std::string surname;
        std::string tel;
};

void print_contact(const ContactEntry &contact);

#endif
