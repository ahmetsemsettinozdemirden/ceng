#include "linkedList.h"

// Create and return a node with the given value
Node* createNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;            
    newNode->link = NULL;
    return newNode;
} 

// Checks if there is an element in the list or not
int isEmpty(Node *head) {
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
} 

// Add given value
void add(Node **head, int value) {

    Node *current;
    Node *new_node = createNode(value);
    /* Special case for the first element */
    if (*head == NULL || (*head)->value >= new_node->value) {
        if (*head != NULL && (*head)->value == new_node->value) {
            printf("%d cannot be inserted\n", value);
            return;
        }
        new_node->link = *head;
        *head = new_node;
    } else {
        /* Locate the node before the point of insertion */
        current = *head;
        while (current->link != NULL && current->link->value < new_node->value) {
            current = current->link;
        }
        if (current->link != NULL && current->link->value == new_node->value) {
            printf("%d cannot be inserted\n", value);
            return;
        }
        new_node->link = current->link;
        current->link = new_node;
    }
    printf("%d inserted\n", value);
}

// Search value
Node* search(Node **head, int value) {

    Node *node = *head;
    if (node == NULL) {
        printf("%d is not found\n", value);
        return NULL;
    }

    if (node->value == value) {
        printf("%d is found\n", value);
        return node;
    }

    Node *prevNode = *head;
    while (prevNode->link != NULL) {
        if(prevNode->link->value == value) {
            printf("%d is found\n", value);
            return prevNode->link;
        }
        prevNode = prevNode->link;
    }

    printf("%d is not found\n", value);
    return NULL;
}

// Delete first Node where given value occurs
Node* delete(Node **head, int value) {
    
    Node *node = *head;
    if (node == NULL) {
        printf("%d cannot be deleted\n", value);
        return NULL;
    }

    if (node->value == value) {
        *head = node->link;
        printf("%d deleted\n", value);
        return node;
    }

    Node *prevNode = *head;
    while (prevNode->link != NULL) {
        if(prevNode->link->value == value) {
            Node *tmp = prevNode->link;
            prevNode->link = prevNode->link->link;
            printf("%d deleted\n", value);
            return tmp;
        }
        prevNode = prevNode->link;
    }
    printf("%d cannot be deleted\n", value);
    return NULL;
}

// Return size of the list
int getSize(Node *head) {
    int size = 0;
    Node *node = head;
    while (node != NULL) {
        size++;
        node = node->link;
    }
    return size;
}

// Print the values of each node in the list
void printList(Node *head) {
    printf("[ ");
    Node *node = head;
    while (node != NULL) {
        printf("%d", node->value);
        if(node->link != NULL) {
            printf(", ");
        }
        node = node->link;
    }
    printf(" ]\n");
} 

// Return number of occurrences of a value in nodes
int getFrequency(Node *head, int value) {
    int num = 0;
    Node *node = head;
    while (node != NULL) {
        if (node->value == value) {
            num++;
        }
        node = node->link;
    }
    return num;
}