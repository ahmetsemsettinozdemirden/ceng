#include "contact_item.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool ContactItem::get_from_user()
{
        cout << "Enter name (\"q\" to quit): ";
        cin >> m_name;
        if (m_name == "q")
                return false;
        cout << "Enter telephone number: ";
        cin >> m_tel_no;
        return true;
}

void ContactItem::print() const
{
        cout << m_name << " -> " << m_tel_no << endl;
}

bool ContactItem::read_from(std::ifstream &fin)
{
        string name;
        getline(fin, name, ':');
        string tel_no;
        getline(fin, tel_no);
        if (!fin.fail()) {
                m_name = name;
                m_tel_no = tel_no;
                return true;
        } else {
                return false;
        }

}

void ContactItem::write_to(std::ofstream &fout) const
{
        fout << m_name << ":" << m_tel_no << endl;
}
