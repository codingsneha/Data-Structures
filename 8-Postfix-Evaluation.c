/*  Program to evaluate postfix expression    */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

typedef struct Stack Stack;


Stack *createStack ( unsigned capacity ) {

    Stack *stack = (Stack*) malloc(sizeof(Stack));

    if (!stack) return NULL;

    stack -> top = -1;
    stack -> capacity = capacity;
    stack -> array = (int*) malloc(stack -> capacity * sizeof(int));

    if (!stack -> array) return NULL;

    return stack;
}


int isEmpty(Stack *stack) {
    return stack -> top == -1;
}

char peek(Stack *stack) {
    return stack -> array [stack -> top];
}

char pop(Stack *stack){
    if (!isEmpty(stack))
        return stack -> array[stack -> top--];
    return '#';
}

void push(Stack *stack, char op) {
    stack -> array [++stack -> top] = op;
}

int evaluatePostfix(char *exp) {
    Stack *stack = createStack(strlen(exp));

    if (!stack) return -1;

    for (int i = 0; exp[i]; ++i){           //Scan expression characters one by one
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');

        else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch(exp[i]) {
                case '+': push(stack, val2 + val1); break;
                case '-': push(stack, val2 - val1); break;
                case '*': push(stack, val2 * val1); break;
                case '/': push(stack, val2/val1); break;
            }
        }

    }
    return pop(stack);
}

int main() {
    char exp[] = "237*+9-";
    printf("\n\nEnter expression: ");
    scanf("%s", exp);
    printf("\n\n %s = %d\n\n", exp, evaluatePostfix(exp));
    return 0;
}