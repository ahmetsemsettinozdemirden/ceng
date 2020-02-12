#include "contact_list.h"

#include <iostream>

using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

void ContactList::print_item(const ContactItem *item) const
{
        cout << item->name << " -> " << item->tel_no << endl;
}

void ContactList::write_item(ofstream& fout, const ContactItem *item) const
{
        fout << item->name << ":" << item->tel_no << endl;
}

void ContactList::add_item_sorted(const std::string& name, const std::string& tel_no)
{
        ContactItem *new_contact = new ContactItem;
        new_contact->name = name;
        new_contact->tel_no = tel_no;

        if (m_item_list == 0 || m_item_list->name.compare(new_contact->name) > 0) {
                // If the list is empty or the new contact should be the first item
                new_contact->next = m_item_list;
                m_item_list = new_contact;
        } else {
                // We iterate until *p is the last item or *(p->next) has a name that should come after new_contact's name
                ContactItem *p = m_item_list;
                while (p->next != 0 && p->next->name.compare(new_contact->name) < 0)
                        p = p->next;
                // We insert the new contact after *p
                new_contact->next = p->next;
                p->next = new_contact;
        }
        m_size++;
}

void ContactList::delete_items()
{
        ContactItem *p = m_item_list;
        while (p != 0) {
                ContactItem *n = p->next;
                delete p;
                p = n;
        }
}

bool ContactList::add_from_user()
{
        string name;
        cout << "Enter name (\"q\" to quit): ";
        cin >> name;
        if (name == "q")
                return false;

        string tel_no;
        cout << "Enter telephone number: ";
        cin >> tel_no;

        add_item_sorted(name, tel_no);
        return true;
}

void ContactList::print() const
{
        const ContactItem *p = m_item_list;
        while (p != 0) {
                print_item(p);
                p = p->next;
        }
}

bool ContactList::read_from(const std::string &filename)
{
        ifstream fin(filename.c_str());
        if (fin.is_open()) {
                while (true) {
                        string name;
                        getline(fin, name, ':');
                        string tel_no;
                        getline(fin, tel_no);
                        if (!fin.fail())
                                add_item_sorted(name, tel_no);
                        else
                                break;
                }
                return true;
        } else {
                return false;
        }
}

bool ContactList::write_to(const std::string &filename) const
{
        ofstream fout(filename.c_str());
        if (fout.is_open()) {
                const ContactItem *p = m_item_list;
                while (p != 0) {
                        write_item(fout, p);
                        p = p->next;
                }
                return true;
        } else {
                return false;
        }
}
