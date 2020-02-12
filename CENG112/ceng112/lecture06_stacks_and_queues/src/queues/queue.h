#ifndef CENG112_QUEUE_H
#define CENG112_QUEUE_H

#include <cstdlib>
#include <iostream>

namespace ceng112 {

template <typename T>
class Queue {
public:
        Queue() { m_head = m_tail = 0; m_size = 0; }
        ~Queue() { clear(); }

        void enqueue(const T& item);
        T dequeue();
        void clear();

        size_t size() const { return m_size; }
        bool is_empty() const { return size() == 0; }
private:
        struct Node {
                T data;
                Node *next;
                Node *prev;
        };

        Node *m_head; // dequeue from head
        Node *m_tail; // enqueue from tail
        size_t m_size;
};

template <typename T>
void Queue<T>::enqueue(const T& item)
{
        Node *node = new Node;
        node->data = item;
        node->prev = 0;
        node->next = m_tail;

        if (is_empty()) {
                m_tail = m_head = node;
        } else {
                m_tail->prev = node;
                m_tail = node;
        }
        m_size++;
}

template <typename T>
T Queue<T>::dequeue()
{
        if (is_empty()) {
                std::cerr << "Can not dequeue from an empty queue!" << std::endl;
                std::exit(EXIT_FAILURE);
        }

        T item = m_head->data;
        Node *new_head = m_head->prev;
        delete m_head;
        m_head = new_head;
        if (m_head == 0)
                m_tail = 0;
        else
                m_head->next = 0;

        m_size--;

        return item;
}

template <typename T>
void Queue<T>::clear()
{
        Node *p = m_tail;
        while (p != 0) {
                Node *to_delete = p;
                p = p->next;
                delete to_delete;
        }

        m_head = m_tail = 0;
        m_size = 0;
}



}

#endif
