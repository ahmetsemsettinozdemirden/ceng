#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct Node {
        int data;
        Node *rest;
};

typedef void (*visit_fn)(Node *n);

Node *cons(int d, Node *rest);
int count(Node *list);
void traverse(Node *list, visit_fn visit);
void traverseR(Node *list, visit_fn visit);
Node *remove_all(Node *list, int value);
void release(Node *list);

void print_node(Node *n) { cout << n->data << " "; }

int main(int argc, char *argv[])
{
        Node *list = NULL;
        for (int i = 10; i > 0; --i)
                list = cons(i, list);

        cout << "Node count = " << count(list) << endl;

        cout << "List data = ";
        traverse(list, print_node);
        cout << endl;

        cout << "List data (in reverse) = ";
        traverseR(list, print_node);
        cout << endl;

        list = remove_all(list, 7);
        cout << "List data (after remove_all 7) = ";
        traverse(list, print_node);
        cout << endl;

        release(list);

        return EXIT_SUCCESS;
}

Node *cons(int d, Node *rest)
{
        Node *n = new Node;
        n->data = d;
        n->rest = rest;
        return n;
}

int count(Node *list)
{
        if (list == NULL)
                return 0;

        return 1 + count(list->rest);
}

void traverse(Node *list, visit_fn visit)
{
        if (list == NULL)
                return;

        (*visit)(list);
        traverse(list->rest, visit);
}

void traverseR(Node *list, visit_fn visit)
{
        if (list == NULL)
                return;

        traverseR(list->rest, visit);
        (*visit)(list);
}

Node *remove_all(Node *list, int value)
{
        if (list == NULL)
                return list;

        if (list->data == value) {
                Node *rest = list->rest;
                delete list;
                return remove_all(rest, value);
        } else {
                list->rest = remove_all(list->rest, value);
                return list;
        }
}

void release(Node *list)
{
        if (list == 0)
                return;

        release(list->rest);
        delete list;
}
