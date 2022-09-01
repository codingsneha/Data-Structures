/* Menu driven program to implement following queue operations using array
    1. Traversing
    2. Push
    3. Pop
    4. Peep
*/

#include <stdio.h>
#define size 20

int queue[size], front = -1, rear = -1;


void display() {
    if (rear == -1) {
        printf("\n\nQueue is empty!");
        return;
    }
    printf("\n\nQueue - \n\n[\t");
    for(int i = front; i <= rear; i++){
        printf("%d\t", queue[i]);
    }
    printf("]");
}


void push(int data) {
    if (rear == size - 1){
        printf("\n\nOverflow!");
        return;
    }
    if (front == -1, rear == -1) {
        front = rear = 0;
    }
    else ++rear;
    queue[rear] = data;
}

void pop() {
    if( front == -1 || front > rear){
        printf("\n\nUnderflow!");
        return;
    }
    if ( front == rear )
        front = rear = -1;
    else ++front;
}

void peep(){
    if (rear == -1) {
        printf ("\n\nList is empty!");
        return;
    }
    printf("\n\nPeekaboo! Latest element is %d", queue[rear]);
}


main() {
    int choice = -1, data;

    while (choice) {
        printf("\n\nChoose - \n\t1. Display\n\t2. Push\n\t3. Pop\n\t4. Peep\n\t5. Exit\n\nEnter choice[1-5]: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: display(); break;
            case 2: 
                printf("\n\nEnter value: ");
                scanf("%d", &data);
                push(data);
                display();
                break;
            case 3: pop(); display(); break;
            case 4: peep(); break;
            case 5: choice = 0; break;
            default: printf("\n\nEnter valid choice!"); break;
        }
    }
}