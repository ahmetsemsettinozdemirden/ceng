#include <stdlib.h>
#include <stdio.h>

struct Node {
        int data;
        struct Node *next;
};

// RECURSIVE SOLUTIONS TO Q5
void print_list(struct Node *n);
int sum_list(struct Node *n);
void free_list(struct Node *n);

int main(void) {
        struct Node *head = NULL;
        for (int i = 0; i < 10; ++i) {
                struct Node *n = malloc(sizeof(*n));
                n->data = i;
                n->next = head;
                head = n;
        }

        print_list(head);
        printf("Sum of the elements is %d\n", sum_list(head));
        free_list(head);
}

void print_list(struct Node *n)
{
        if (n == NULL) {
                printf("\n");
                return;
        }

        printf("%d ", n->data);
        print_list(n->next);
}

int sum_list(struct Node *n)
{
        if (n == NULL)
                return 0;

        return n->data + sum_list(n->next);
}

void free_list(struct Node *n)
{
        if (n == NULL)
                return;

        free_list(n->next);
        free(n);
}
