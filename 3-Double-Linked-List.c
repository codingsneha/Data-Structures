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


static struct node *head = NULL;

//~~is list empty
int isEmpty() {
    return head==NULL;
}



//Traversing
void display() {

    if(isEmpty){
        printf("\n\nList is empty!");
        return;
    }

    struct node *temp = head;
    printf("\n\nElements in the list - \n[\t");
    while(temp){
        printf("%d\t", temp->data);
        temp = temp -> next;
    }
    printf("]");
}




//INSERTION
//At first
void insertAtFirst(int data) {

    struct node *new = (struct node *) malloc(sizeof (struct node) );
    new -> data = data;

    new -> next = head;        //First make new node point to the first node
    new -> prev = NULL;        //Make previous NULL
    
    if(!isEmpty) {
        head -> prev = new;     //Change head previous new node
    }

    head = new;    //Move head to point to new
}



//At end
void insertAtEnd(int data) {
    struct node *new = (struct node *) malloc(sizeof (struct node) );
    new -> data = data;
    new -> next = NULL;

    if(isEmpty()){
        head = new;
        return;
    }

    struct node *temp = head;

    while(temp -> next) {
        temp = temp -> next;
    }

    temp -> next = new;
    new -> prev = temp;
    temp -> next = '\0';
}



//at any other position
void atAnyPos(int pos, int data) {
    if (pos<=1){
        printf("Enter valid postion!");
        return;
    }

    struct node *new = (struct node *) malloc (sizeof (struct node));
    new -> data = data;
    new -> next = NULL;

    if (isEmpty()) {
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

}


int main() {
    int data = 1;
    display();
    insertAtFirst(data);
    display();
    return 0;
}