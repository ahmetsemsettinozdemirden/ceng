#ifndef CENG112_QUEUE_H
#define CENG112_QUEUE_H

#include <cstdlib>
#include <iostream>

namespace ceng112 {

template <typename T>
class Queue {
public:
        Queue() { m_head = 0; m_size = 0; }
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

        Node *m_head;
        size_t m_size;
};

template <typename T>
void Queue<T>::enqueue(const T& item)
{
        Node *node = new Node;
        node->data = item;
        node->prev = 0;
        node->next = 0;


        if (is_empty()) {
                m_head = node;
        } else {

                Node *p = m_head;
                if(p->prev != 0){
                        while(p->prev != m_head){ // go to the lastest node
                                p = p->prev;
                        }
                }

                p->prev = node;
                node->next = p;

                node->prev = m_head;
                m_head->next = node;
        }
        m_size++;
        printf("enqueue\n");
}

template <typename T>
T Queue<T>::dequeue()
{
        if (is_empty()) {
                std::cerr << "Can not dequeue from an empty queue!" << std::endl;
                std::exit(EXIT_FAILURE);
        }

        m_size--;
        T item = m_head->data;

        if(m_size > 0){

                Node *new_head = m_head->prev;
                Node *new_tail = m_head->next;
                delete m_head;
                
                m_head = new_head;

                new_head->next = new_tail;
                new_tail->prev = new_head;

        }else{
                delete m_head;
                m_head = 0;
        }
        printf("dequeue\n");
        return item;
}

template <typename T>
void Queue<T>::clear()
{
        printf("start clear\n");
        Node *p = m_head;
        Node *newTail = m_head->next;
        while (p != 0) {
                Node *to_delete = p;
                if(p == newTail)
                        p = 0;
                else
                        p = p->prev;
                delete to_delete;
        }

        m_head = 0;
        m_size = 0;
        printf("clear\n");
}



}

#endif
