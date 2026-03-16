// 41. Write a program to convert infix notation to postfix notation using stack. 

#include <stdio.h>
#include <string.h>

void push(char stack[], int size, int* top, char val) {
    if(*top >= size - 1) {
        printf("stack overflow \n");
        return;
    }
    
    stack[++(*top)] = val;
}

char pop(char stack[], int* top) {
    if(*top <= -1) {
        printf("stack underflow \n");
        return '\0';
    }

    return stack[(*top)--];
}

// stack precedence
int g(char ch) {
    if(ch == '+' || ch == '-') return 2;
    else if(ch == '*' || ch == '/') return 4;
    else if(ch == '^') return 5;
    else if(ch == '(') return 0;
    else return 8;
}

// input precedence
int f(char ch) {
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 3;
    else if(ch == '^') return 6;
    else if(ch == '(') return 9;
    else if(ch == ')') return 0;
    else return 7;
}

// rank function 
int r(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') return -1;
    else return 1;
}

void revpol(char infix[]) {
    // stack, top of stack, size of stack
    char stack[50];
    int top = -1;

    // push '(' as first element of stack
    push(stack, 50, &top, '(');

    // polish string and their travrsing variable j
    char polish[50];
    int j = 0;

    // rank of 
    int rank = 0;

    // loop for travers infix string 
    int i = 0;
    while(i != strlen(infix)) {
        char next = infix[i];
        if(top < 0) {
            printf("Invalid string \n");
            return;
        }

        while(g(stack[top]) > f(next)) {
            char temp = pop(stack, &top);
            polish[j++] = temp;
            rank += r(temp);
            if(rank < 1) {
                printf("Invalid string \n");
                return;
            }
        }

        if(g(stack[top]) != f(next))
            push(stack, 50, &top, next);
        else 
            pop(stack, &top);

        i++;
    }

    if(top != -1 || rank != 1) 
        printf("Invalid string \n");
    else {
        polish[j] = '\0';
        printf("Postfix expression: %s\n", polish);
    }
}

int main() {
    char infix[50];
    printf("Enter the string :");
    scanf("%s", infix);
    strcat(infix,")");
    revpol(infix);

    return 0;
}
