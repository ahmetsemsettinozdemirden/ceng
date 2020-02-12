#include <stdlib.h>
#include <stdio.h>

struct Node {
        int data;
        struct Node *next;
};

// ITERATIVE SOLUTIONS TO Q5
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
        while (n != NULL) {
                printf("%d ", n->data);
                n = n->next;
        }
        printf("\n");
}

int sum_list(struct Node *n)
{
        int sum = 0;
        while (n != NULL) {
                sum += n->data;
                n = n->next;
        }

        return sum;
}

void free_list(struct Node *n)
{
        while (n != NULL) {
                struct Node* to_del = n;
                n = n->next;
                free(to_del);
        }
}
