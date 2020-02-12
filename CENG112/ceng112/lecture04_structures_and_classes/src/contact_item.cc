#include "contact_item.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ContactItem::read()
{
        cout << "Enter contact name: ";
        cin >> m_name;
        cout << "Enter contact surname: ";
        cin >> m_surname;
        cout << "Enter contact telephone number: ";
        cin >> m_tel;
}

void ContactItem::print()
{
        cout << "(" << m_name << " "
             << m_surname << ", "
             << m_tel << ")" << endl;
}

