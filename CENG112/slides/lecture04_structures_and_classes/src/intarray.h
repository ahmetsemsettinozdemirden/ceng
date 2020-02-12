#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray {
public:
        IntArray();  // constructor
        ~IntArray(); // destructor

        int size();
        int capacity();
        void insert(int item);
        int  item_at(int index);
        void clear(); // removes all items
private:
        int *m_items;
        int m_size;
        int m_capacity;
};


#endif
