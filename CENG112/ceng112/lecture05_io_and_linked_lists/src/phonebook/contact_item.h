#ifndef CONTACT_ITEM_H
#define CONTACT_ITEM_H

#include <fstream>
#include <string>

class ContactItem {
public:
        bool get_from_user();
        void print() const;

        bool read_from(std::ifstream &fin);
        void write_to(std::ofstream &fout) const;
private:
        std::string m_name;
        std::string m_tel_no;
};

#endif
