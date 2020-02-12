#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include <string>
#include <fstream>

class ContactList {
public:
        ContactList() { m_size = 0; m_item_list = 0; }
        ~ContactList() { delete_items(); }

        size_t size() const { return m_size; }
        bool add_from_user();
        void print() const;

        bool read_from(const std::string &filename);
        bool write_to(const std::string &filename) const;
private:
        struct ContactItem {
                std::string name;
                std::string tel_no;
                ContactItem *next;
        };

        void print_item(const ContactItem *item) const;
        void write_item(std::ofstream& fout, const ContactItem *item) const;
        void add_item_sorted(const std::string& name, const std::string& tel_no);
        void delete_items();

        size_t m_size;
        ContactItem *m_item_list; // linked list of items sorted by name
};

#endif
