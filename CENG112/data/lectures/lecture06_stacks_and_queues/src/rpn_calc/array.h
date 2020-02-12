#ifndef CENG112_ARRAY_H
#define CENG112_ARRAY_H

#include <iostream>

namespace ceng112 {

template <typename T>
class Array {
public:
        Array() { m_items = 0; m_size = 0; m_capacity = 0; }
        ~Array() { delete [] m_items; }

        size_t size() const { return m_size; }
        size_t capacity() const { return m_capacity; }
        void clear() { resize(0); }

        void resize(int new_size);
        void insert(T item);

        T& operator[](size_t index) { return m_items[index]; }
        const T& operator[](size_t index) const { return m_items[index]; }
private:
        T *m_items;
        size_t m_size;
        size_t m_capacity;
};

template <typename T>
void Array<T>::resize(int new_size)
{
        if (new_size > m_capacity) {
                size_t new_cap = (m_capacity > 0) ? m_capacity : 1;
                while (new_size > new_cap)
                        new_cap *= 2;
                T * new_items = new T[new_cap];
                for (size_t i = 0; i < m_size; ++i)
                        new_items[i] = m_items[i];
                delete [] m_items;
                m_items = new_items;
                m_capacity = new_cap;
        }

        m_size = new_size;
}

template <typename T>
void Array<T>::insert(T new_item)
{
        resize(m_size+1);
        m_items[m_size-1] = new_item;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
        os << "[";
        for (size_t i = 0; i < arr.size(); ++i)
                os << arr[i] << " ";
        os << "(C/S=" << arr.capacity() << "/" << arr.size();
        os << ")]";
        return os;
}

}

#endif
