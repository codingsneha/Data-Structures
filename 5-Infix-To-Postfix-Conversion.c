/*
* INFIX – Any operation of format a op b format example a + b is called an infix operation
POSTFIX – An operation or expression can also be written in the 
format of a b op i.e. a b + which is similar to writing a + b in infix. 
All we are doing is shifting operator to the right of operands



Algorithm - 
    1. Scan given expression from left to right
    2. If scanned character is operand, output it
    3. Else
            * If precedence of scanned operator is higher than the
            precedence of the operator in stack (or stack is empty
            or has '('   ), then push operator in the stack

            * Else, pop all the operators, that have greater or equal
            precedence than the scanned operator. Once you pop them
            push the scanned operator. (If we see a paranthesis while
            popping then stop and push scanned operator in the stack)

    4. If scanned character is an '(', push it to the stack.
    5. If the scanned character is an ')', pop the stack and output it until a
    '(' is encountered, and discard both the paranthesis.
    6. Repeat steps 2-6 until the whole infiz i.e. whole characters are scanne
    7. Print output
    8. Do the pop and output (print) until stack is not empty
*/


// Array based stack approach

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 20

char stack[MAX];
int top = -1;



int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX -1;
}


char peek() {
    return stack[top];
}


char pop() {
    if(isEmpty())
        return -1;

    char ch = stack[top];
    top--;
    return(ch);
}

void push(char oper){
    if(isFull())
        printf("\n\nOverflow!");

    else{
        top++;
        stack[top] = oper;
    }
}

//Check whether given character is operand
int chackIfOperand(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}


//Function to compare precendence
int precedence(char ch){
    switch (ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}


//Driver function for infix to postfix conversion

int convertInfixToPostfix(char *expression){

    int i,j;

    for (i=0, j=-1; expression[i]; ++i){
        if(chackIfOperand(expression[i]))
            expression[++j] = expression[i];

        else if (expression[i] == '(')
            push(expression[i]);

        else if (expression[i] == ')'){
            while (!isEmpty() && peek()!= '(')
                expression[++j] = pop();
            if (!isEmpty() && peek() != '(')
                return -1;
            else
                pop();
        }

        else{ //if an operator
            while(!isEmpty() && precedence(expression[i]) <= precedence(peek()))
                expression[++j] = pop();
            push(expression[i]);
        }

    }

    // Once all inital expression characters are traversed
    // adding all left elements from stack to exp
    while (!isEmpty()) 
        expression[++j] = pop(); 

    expression[++j] = '\0'; 
    printf( "%s", expression); 
}



int main(){
char expression[] = "((a+(b*c))-d)"; 
    convertInfixToPostfix(expression); 
    return 0; 
}