// 42. Write a program to convert infix notation to prefix notation using stack.  

#include <stdio.h>
#include <string.h>

void push(char stack[], int size, int* top, char val) {
    if(*top >= size - 1) return;
    
    stack[++(*top)] = val;
}

char pop(char stack[], int* top) {
    if(*top <= -1) return '\0';

    return stack[(*top)--];
}

// stack precedence
int g(char ch) {
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 3;
    else if(ch == '^') return 6;
    else if(ch == '(') return 0;
    else return 8;
}

// input precedence
int f(char ch) {
    if(ch == '+' || ch == '-') return 2;
    else if(ch == '*' || ch == '/') return 4;
    else if(ch == '^') return 5;
    else if(ch == '(') return 9;
    else if(ch == ')') return 0;
    else return 7;
}

// rank function 
int r(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') 
        return -1;
    else 
        return 1;
}

void revInfix(char infix[], char newInfix[]) {
    int i;
    for(i=0; i<strlen(infix); i++) {
        char c = infix[strlen(infix)-1-i];
        if(c == '(') newInfix[i] = ')';
        else if(c == ')')newInfix[i] = '(';
        else newInfix[i] = c;
    }
    newInfix[i] = '\0';
}

void reverse(char str[]) {
    int n = strlen(str);
    for(int i=0; i<n/2; i++) {
        char temp = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = temp;
    }
}

void polish(char infix[]) {
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
        reverse(polish);
        printf("prefix expression: %s\n", polish);
    }
}

int main() {
    char infix[50];
    printf("Enter the string :");
    scanf("%s", infix);

    
    char newInfix[50];
    revInfix(infix, newInfix);
    
    strcat(newInfix, ")");
    polish(newInfix);

    return 0;
}