#include "contact_list.h"

#include <fstream>

using std::ofstream;
using std::ifstream;

bool ContactList::add_from_user()
{
        ContactItem c;
        if (c.get_from_user()) {
                m_items.push_back(c);
                return true;
        } else {
                return false;
        }
}

void ContactList::print() const
{
        for (size_t i = 0; i < m_items.size(); ++i)
                m_items[i].print();
}

bool ContactList::read_from(const std::string &filename)
{
        ifstream fin(filename.c_str());
        if (fin.is_open()) {
                ContactItem c;
                while (c.read_from(fin))
                        m_items.push_back(c);
                return true;
        } else {
                return false;
        }
}

bool ContactList::write_to(const std::string &filename) const
{
        ofstream fout(filename.c_str());
        if (fout.is_open()) {
                for (size_t i = 0; i < m_items.size(); ++i)
                        m_items[i].write_to(fout);
                return true;
        } else {
                return false;
        }
}
