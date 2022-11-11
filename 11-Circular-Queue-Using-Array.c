#include <stdio.h>
#include <stdlib.h>
#define maxsize 5

int queue[maxsize], f = -1, r = -1;

int isFull() {
    if (f == (r + 1) % maxsize) return 1;
    return 0;
}

int isEmpty() {
    if (f == -1) return 1;
    return 0;
}

void enqueue(int data) {
    if (isFull()) { 
        printf("\n\nOverflow!");
        return;
    }
    r = (r + 1) % maxsize;
    queue[r] = data;
    if (f == -1) f = 0;
}

void dequeue() {
    if (isEmpty()) {
        printf ("\n\nUnderflow!");
        return;
    }
    if (f == r) f = r = -1; //empty queue condition
    else ++f;
}

void display() {
    if (isEmpty()) {
        printf("\n\nQueue is empty!");
        return;
    }
    printf("\n\nQueue - \n\n[\t");
    for(int i = f; i != r; ) {
        printf("%d\t", queue[i]);
        i = (i + 1) % maxsize;
    }
    printf ("%d\t", queue[r]);
    printf("]");
    printf("\nFront = %d\nRear = %d", f, r);
}

main() {
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