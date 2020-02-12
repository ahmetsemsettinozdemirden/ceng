#include "queue.h"

#include <stdlib.h>
#include <string.h>

struct Node {
        char *elem;
        struct Node *next;
};

static struct Node *new_node(void *elem, int elem_size)
{
        struct Node *n = malloc(sizeof(struct Node));
        n->elem = malloc(elem_size);
        memcpy(n->elem, elem, elem_size);
        n->next = NULL;

        return n;
}

static void free_node(struct Node *n)
{
        if (n != NULL) {
                free(n->elem);
                free(n);
        }
}

struct Queue
{
        int elem_size;
        struct Node *head;
        struct Node *tail;
        int n_elems;
};

struct Queue *queue_new(int elem_size)
{
        struct Queue *q = malloc(sizeof(struct Queue));
        q->elem_size = elem_size;
        q->head = NULL;
        q->tail = NULL;
        q->n_elems = 0;
        return q;
}

void queue_free(struct Queue *q)
{
        if (q != NULL) {
                while (q->head != NULL) {
                        struct Node *to_del = q->head;
                        q->head = q->head->next;
                        free_node(to_del);
                }
                free(q);
        }
}

void queue_put(struct Queue *q, void *elem)
{
        struct Node *n = new_node(elem, q->elem_size);

        if (q->head == NULL) {
                q->head = n;
                q->tail = n;
        } else {
                q->tail->next = n;
                q->tail = n;
        }

        q->n_elems++;
}

void queue_get(struct Queue *q, void *elem)
{
        memcpy(elem, q->head->elem, q->elem_size);
        struct Node *to_del = q->head;
        q->head = q->head->next;

        free_node(to_del);
        q->n_elems--;
}

int queue_size(const struct Queue *q)
{
        return q->n_elems;
}

int queue_is_empty(const struct Queue *q)
{
        return q->n_elems == 0;
}
