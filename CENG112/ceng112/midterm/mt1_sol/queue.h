#ifndef QUEUE_H
#define QUEUE_H

struct Queue;

struct Queue *queue_new(int elem_size);
void queue_free(struct Queue *q);

void queue_put(struct Queue *q, void *elem);
void queue_get(struct Queue *q, void *elem);

int queue_size(const struct Queue *q);
int queue_is_empty(const struct Queue *q);

#endif
