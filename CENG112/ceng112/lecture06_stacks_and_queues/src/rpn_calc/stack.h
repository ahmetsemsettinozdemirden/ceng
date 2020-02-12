#ifndef CENG112_STACK_H
#define CENG112_STACK_H

#include <cstdlib>
#include <iostream>
#include "array.h"

namespace ceng112 {

template <typename T>
class Stack {
public:
        void push(const T& item);
        T pop();
        size_t size() const { return m_items.size(); }
        bool is_empty() const { return m_items.size() == 0; }
private:
        ceng112::Array<T> m_items;
};

template <typename T>
void Stack<T>::push(const T& item)
{
        m_items.insert(item);
}

template <typename T>
T Stack<T>::pop() {
        if (is_empty()) {
                std::cerr << "Can not pop from an empty stack!" << std::endl;
                std::exit(EXIT_FAILURE);
        }
        size_t n = m_items.size();
        T item = m_items[n-1];
        m_items.resize(n-1);
        return item;
}

}

#endif
