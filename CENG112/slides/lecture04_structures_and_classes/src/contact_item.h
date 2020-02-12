#ifndef CONTACT_ITEM_H
#define CONTACT_ITEM_H

#include <string>

class ContactItem {
public:
        std::string name()    { return m_name; }
        std::string surname() { return m_surname; }
        std::string tel()     { return m_tel; }

        void print();
        void read();
private:
        std::string m_name;
        std::string m_surname;
        std::string m_tel;
};

#endif
