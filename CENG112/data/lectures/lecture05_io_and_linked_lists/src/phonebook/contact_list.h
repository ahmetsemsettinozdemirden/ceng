#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include <vector>

#include "contact_item.h"

class ContactList {
public:
        size_t size() const { return m_items.size(); }
        bool add_from_user();
        void print() const;

        bool read_from(const std::string &filename);
        bool write_to(const std::string &filename) const;
private:
        std::vector<ContactItem> m_items;
};

#endif
