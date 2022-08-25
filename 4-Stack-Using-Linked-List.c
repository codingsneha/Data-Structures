/*
Operations performed on STACK - 
1.  PUSH
2.  POP
3.  PEEK
4.  SHOW

*/


#include <stdio.h>
#include <stdlib.h>

// Structure to create nodes with data and next pointer
struct node {
    int data;
    struct node *next;
};

static struct node *top = NULL;


void push() {
    struct node *new = (struct node*) malloc(sizeof(struct node));

    int data;
    printf("\n\nEnter value to be pushed: ");
    scanf("%d", &data);

    new->data = data;

    if(top == NULL){
        new->next = NULL;
        top = new;
    }
    else{
        new->next = top;
        top = new;
    }   
}




void pop(){
    if(top == NULL){
        printf("\n\nEmpty stack!");
        return;
    }
    else{
        struct node *temp = top;
        int t = top->data;
        top = top->next;
        free(temp);
    }
}



void peek(){
    if(top == NULL)
        printf("\n\nEmpty stack!");
    else{
        printf("\n\nPeekaboo! Top most element is %d", top->data);
    }
}



void show(){
    if(top == NULL)
        printf("\n\nEmpty stack!");
    else{
        struct node *temp = top;
        printf("\n\nStack - \n[ ");
        while(temp){
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf(" ]");
    }
}




void menu(){
    printf("\n\nChoose one - ");
    printf("\n\t1. PUSH\n\t2. POP\n\t3. PEEP\n\t4. SHOW\n\t5. EXIT");
    printf("\n\nEnter choice [1-6]: ");
}



void main(){
    int choice=1;
    while(choice){
        menu();
        scanf("%d", &choice);
        
        switch (choice){
        case 1:
            push();
            show();
            break;
        
        case 2:
            printf("\n\nPopping . . .");
            pop();
            show();
            break;
        
        case 3:
            peek();
            break;
        
        case 4:
            show();
            break;
        
        case 5:
            choice=0;
            break;
        
        default:
            printf("\n\nEnter valid choice!");
            break;
        }
    }
}