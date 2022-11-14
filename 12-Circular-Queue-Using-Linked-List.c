#include <stdio.h>
#include <stdlib.h>

struct List {
    int data;
    struct List *next;
} *front = NULL, *rear = NULL;

typedef struct List node;

int isEmpty () {
    return front == NULL ? 1 : 0;
}

void enqueue (int data) {
    node *newNode = (node *) malloc ( sizeof(node) );
    newNode -> data = data;
    newNode -> next = NULL;
    if (!front) {
        front = newNode;
        newNode -> next = front;
        rear = front;
        return;
    }
    newNode -> next = front;
    rear -> next = newNode;
    rear = newNode;
}

void dequeue () {
    if (!front) {
        printf ("\n\nEmpty!");
        return;
    }
    if (front == (front -> next)) {
        front = NULL;
        rear = NULL;
        return;
    }
    front = front -> next;
    rear -> next = front;
}

void display () {
    if (isEmpty()) {
        printf ("\n\nEmpty!");
        return;
    }
    node *temp = front;
    while (temp != rear) {
        printf ("%d\t", temp -> data);
        temp = temp -> next;
    }
    printf ("%d", temp -> data);
    printf ("\nFront: %d\nRear: %d\n", front->data, rear->data);
}

int main() {
    int choice = -1, data;

    while (choice) {
        printf("\n\nChoose - \n\t1. Display\n\t2. Enqueue\n\t3. Dequeue\n\t4. Exit\n\nEnter choice[1-4]: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: display(); break;
            case 2: 
                printf("\n\nEnter value: ");
                scanf("%d", &data);
                enqueue(data);
                display();
                break;
            case 3: dequeue(); display(); break;
            case 4: choice = 0; break;
            default: printf("\n\nEnter valid choice!"); break;
        }
    }
    return 0;
}