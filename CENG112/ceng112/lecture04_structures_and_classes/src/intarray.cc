#include "intarray.h"

IntArray::IntArray()
{
        const int INITIAL_CAPACITY = 8;

        m_items = new int[INITIAL_CAPACITY];
        m_capacity = INITIAL_CAPACITY;
        m_size = 0;
}

IntArray::~IntArray()
{
        delete [] m_items;
}

int IntArray::size()
{
        return m_size;
}

int IntArray::capacity()
{
        return m_capacity;
}

int  IntArray::item_at(int index)
{
        return m_items[index];
}

void IntArray::clear()
{
        m_size = 0;
}

void IntArray::insert(int item)
{
        if (m_size >= m_capacity) {
                int new_cap = 2*m_capacity;
                int *new_items = new int[new_cap];
                for (int i = 0; i < m_size; ++i)
                        new_items[i] = m_items[i];
                delete [] m_items;
                m_items = new_items;
                m_capacity = new_cap;
        }

        m_items[m_size] = item;
        m_size++;
}
