/* Program to implement basic double linked list operations
    1. Traversing
    2. Insertion
    3. Deletion
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};


static struct node *head;


//Traversing
void display() {

    if(head == NULL){
        printf("\n\nList is empty!");
        return;
    }

    struct node *temp = head;
    printf("\n\nElements in the list - \n[\t");
    while(temp){                        //till temp!=NULL (go till the end of list)
        printf("%d\t", temp->data);
        temp = temp -> next;         
    }
    printf("]");
}




//INSERTION
//At first
void insertAtFirst(int data) {

    struct node *new = (struct node *) malloc(sizeof (struct node));
    new -> data = data;

    if(head == NULL) {                  //List is empty
        new -> next = NULL;    
        new -> prev = NULL;
        head = new;
        return;
    }

    new -> prev = NULL;
    new -> next = head;
    head -> prev = new;
    head = new;

    printf("\n\nInserting... \n %d", head -> next -> data);
}



//At end
void insertAtEnd(int data) {
    struct node *new = (struct node *) malloc(sizeof (struct node) );
    new -> data = data;
    new -> next = NULL;

    if(new == NULL){
        printf("\n\nOverflow!");
        return;
    }

    struct node *temp = head;

    if (head == NULL){
        new -> next = NULL;
        new -> prev = NULL;
        head = new;
        return;
    }

    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = new;
    new -> prev = temp;
    new -> next = NULL;
}



//at any other position
void insertAtPos(int pos, int data) {
    if (pos<1){
        printf("Enter valid postion!");
        return;
    }

    struct node *new = (struct node *) malloc (sizeof (struct node));
    new -> data = data;
    new -> next = NULL;

    if (head == NULL) {
        head = new;
        return;
    }

    struct node *temp = head;
    while(--pos){
        temp = temp -> next;
    }
    new -> prev = temp;
    new -> next = temp -> next;
    temp -> next = new;
    temp -> next -> prev = new;

}


//DELETION

//delete first element
void deleteFirst(){
    struct node *temp = head;

    if(head == NULL) {
        printf("\n\nUnderflow!");
        return;
    }

    if(head -> next == NULL){
        head = NULL;
        free(head);
        return;
    }

    head = head -> next;
    head -> prev = NULL;
    free(temp);
}


//delete last element
void deleteLast() {
    struct node *temp = head;
    if(head == NULL) {
        printf("\n\nUnderflow!");
        return;
    }

    if(head -> next == NULL) {
        head = NULL;
        free(head);
        return;
    }
    while(temp->next){
        temp = temp -> next;
    }

    temp -> prev -> next = NULL;
    free(temp);
}


//delete element at a given position
void deletePos(int pos) {
    struct node *temp = head;
    while(--pos){
        temp = temp -> next;
    }
    if(temp -> next == NULL){
        printf("\n\nCan't delete bro : (");
        return;
    }
    struct node *ptr;
    ptr = temp -> next;
    temp -> next -> prev = temp;
    free(temp);
}


int getValue(){
    int data;
    printf("\n\nEnter value: ");
    scanf("%d",&data);
    return data;
}

int getPos(){
    int pos;
    printf("\n\nEnter position: ");
    scanf("%d",&pos);
    return pos;
}

int main() {
    int choice = -1;
    while(choice){
        choice = -1;
        printf("\n\nChoose -\n\t1. Display\n\t2. Insert\n\t3. Delete\n\t4. Exit\n\nEnter choice[1-4]: ");
        scanf("%d", &choice);
        switch(choice){
            case 2:
                printf("\n\nChoose - \n\t1. Insert at beginning\n\t2. Insert at end\n\t3. Insert at poisition\n\t4. Exit\n\nEnter choice[1-4]: ");
                int c1 = 1;
                scanf("%d", &c1);

                switch(c1) {
                    case 1: 
                        insertAtFirst(getValue());
                        break;
                    case 2:
                        insertAtEnd(getValue());
                        break;
                    case 3:
                        insertAtPos(getPos(), getValue());
                        break;
                    case 4:
                        choice = 0;
                        break;
                    default:
                        printf("\n\nEnter correct choice!");

                }
                break;

            case 3:
                printf("\n\nChoose - \n\t1. Delete first element\n\t2. Delete last element\n\t3. Delete element at a position\n\t4. Exit\n\nEnter choice[1-4]: ");
                scanf("%d", &c1);

                switch(c1) {
                    case 1: 
                        deleteFirst();
                        break;
                    case 2:
                        deleteLast();
                        break;
                    case 3:
                        deletePos(getPos());
                        break;
                    case 4:
                        choice = 0;
                        break;
                    default:
                        printf("\n\nEnter correct choice!");

                }
                break;

            case 1:
                display();
                break;

            case 4:
                choice = 0;
                break;

            default:
                printf("\n\nEnter valid choice!");

        }
    }

    return 0;
}