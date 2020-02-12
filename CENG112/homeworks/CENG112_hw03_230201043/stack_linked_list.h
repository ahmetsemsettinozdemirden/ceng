#ifndef CENG112_STACK_H
#define CENG112_STACK_H

#include <cstdlib>
#include <iostream>

namespace ceng112 {

template <typename T>
class Stack {
public:
        Stack() { m_size = 0; m_head = 0; }

        void push(const T& item);
        T pop();
        size_t size() const { return m_size; }
        bool is_empty() const { return m_size == 0; }
private:

        struct Node
        {
                T data;
                Node *next;
        };

        size_t m_size;
        Node *m_head;

};

template <typename T>
void Stack<T>::push(const T& item)
{
        Node *newNode = new Node;
        newNode->data = item;

        newNode->next = m_head;
        m_head = newNode;

        m_size++;
}

template <typename T>
T Stack<T>::pop() {
        if (is_empty()) {
                std::cerr << "Can not pop from an empty stack!" << std::endl;
                std::exit(EXIT_FAILURE);
        }

        Node *p = m_head;
        
        m_head = m_head->next;

        m_size--;

        return p->data;
}

}

#endif
