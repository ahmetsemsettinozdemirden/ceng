#include<stdio.h>
#include"linkedList.h"

int main() {
    
    printf("create node\n");
    Node *newNode = createNode(5);
    Node *head = newNode;

    printf("add 3\n");
    addNode(&head,1,3);
    printf("add 7\n");
    addNode(&head,1,7);
    printf("add 9\n");
    addNode(&head,2,9);
    printf("add 3\n");
    addNode(&head,1,3);
    printf("add 3\n");
    addNode(&head,2,3);

    printf("print node\n");
    printList(head);

    printf("delete 9\n");
    deleteNode(&head,7);

    printf("print node\n");
    printList(head);

    printf("size: %d\n", getSize(head));
    printf("frequency: %d\n", getFrequency(head, 3));

}