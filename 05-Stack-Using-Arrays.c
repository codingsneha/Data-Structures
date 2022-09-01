/*
Stack follows the Last In First Out (LIFO) fashion wherein
the last element entered is the first one to be popped out.

Operations performed on stacks
1.  push
2.  pop
3.  peep
4.  show

*/


#include <stdio.h>
#define size 4         


static int stack[size], top=-1;




void push () {
    
    int data;

    if(top == size-1)
        printf("\n\nOverflow!");

    else{
        printf("\n\nEnter element to be inserted to the stack: ");
        scanf("%d", &data);
        stack[++top]=data;
    }
}






void pop () {

    if(top == -1)
        printf("\n\nUnderflow!");
    
    else{
        printf("\n\nPopped element: %d", stack[top--]);
    }
    
}





void peek () {
    if(top == -1)
        printf("\n\nStack is empty!");
    else
        printf("\n\nPeekaboo! Top most element is %d", stack[top]);
}





void show () {
    if(top == -1)
        printf("\n\nStack is empty!");

    else{
        printf("\n\nElements present in stack: [\t");
        for(int i=0; i<=top; i++){
            printf("%d\t", stack[i]);
        }
        printf("]");
    }
}




void main() {
    int choice=1;
    while(choice){
        printf("\n\nChoose one of the following stack operations- ");
        printf("\n\n\t1. PUSH\n\t2. POP\n\t3. PEEP\n\t4. SHOW\n\t5. EXIT");
        printf("\n\nEnter choice [1-4]: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                push();
                show();

                break;

            case 2:
                show();
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