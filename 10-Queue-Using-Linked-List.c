#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL, *front = NULL, *rear = NULL;

typedef struct Node node;

node *createNode (int data) {
    node *newNode = (node *) malloc( sizeof(node) );
    newNode -> next = NULL;
    newNode -> data = data;
    return newNode;
}

void enqueue (int data) {
    node *newNode = createNode(data);
    if (!head) head = newNode;
    else {
        node *temp = head;
        while (temp -> next) temp = temp -> next;
        temp -> next = newNode;
    }
}

void dequeue () {
    if (!head) {
        printf("\n\nQueue empty!");
        return;
    }
    node *temp = head;
    head = head -> next;
    free(temp);
}

void display () {
    if (!head) printf("\n\nQueue empty!");
    node *temp = head;
    while (temp) {
        printf ("%d\t", temp -> data);
        temp = temp -> next;
    }
}

int main() {
    int ch = -1, val;
    while (ch) {
        printf("\n\nChoose -\n\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. Exit\nEnter[1-4]: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\n\nEnter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                ch = 0;
                break;
            default:
                printf("\n\nEnter valid choice!");
        }
    }
    return 0;
}