/* Menu driven binary tree implementation in C using Linked List (Structures) */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
} *root;

typedef struct Node node;


//CREATE NEW NODE
node *create () {
    int value;
    node *newNode = (node *) malloc( sizeof(node) );
    newNode -> left = newNode -> right = NULL;
    printf ("\n\nEnter value: ");
    scanf ("%d", &value);
    newNode -> data = value;
    return newNode;
}


// INSERTION
void insert (node **tree) {
    node *new = create();

    if (!(*tree)) {
        *tree = new;
        return;
    }

    if ( (new -> data) < ((*tree) -> data) )
        insert(&(*tree)->left);
    if ( (new ->data) > ((*tree) -> data) )
        insert(&(*tree)->right);


}


//TRAVERSAL

//Inorder traversal
void inorder(node *tree) {
    if (!tree) return;

    inorder (tree -> left);
    printf ("%d ", tree -> data);
    inorder (tree -> right);
}



void main () {
    int ch = -1;

    while (ch) {
        printf ("\n\nChoose -\n\t1. Insert \n\t2. Display\n\t3. Exit\n\tEnter[1-3]: ");
        scanf ("%d", &ch);
        switch (ch) {
            case 1:
                insert(&root);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                ch = 0;
                break;
            default:
                printf ("\n\nEnter valid choice!"); 
        }
    }

}