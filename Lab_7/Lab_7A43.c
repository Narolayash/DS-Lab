// 43. Write a program for evaluation of postfix Expression using Stack.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void push(int stack[], int size, int* top, int val) {
    if(*top >= size - 1) {
        printf("stack overflow \n");
        exit(1);
    }
    
    stack[++(*top)] = val;
}

int pop(int stack[], int *top) {
    if(*top <= -1) {
        printf("stack underflow \n");
        exit(1);
    }

    return stack[(*top)--];
}

int perform_operation(int operand1, int operand2, char opration) {
    if(opration == '+')
        return operand1 + operand2;
    else if(opration == '-')
        return operand1 - operand2;
    else if(opration == '*')
        return operand1 * operand2;
    else if(opration == '/') {
        if(operand2 != 0)
            return operand1 / operand2;
        else {
            printf("Division by zero! \n");
            exit(1);
        }
    }
    else {
        printf("Invalid operation %c \n", opration);
        exit(1);
    }
}

void evaluation(char postfix[]) {
    int stack[50];
    int top = -1;
    int ans = 0;

    for(int i=0; i<strlen(postfix); i++) {
        char temp = postfix[i];
        if(isdigit(temp))
            push(stack, 50, &top, temp - '0');
        else {
            int operand2 = pop(stack, &top);
            int operand1 = pop(stack, &top);
            ans = perform_operation(operand1, operand2, temp);
            push(stack, 50 , &top, ans);
        }
    }

    printf("ans = %d", pop(stack, &top));
}

int main() {
    char postfix[50];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    evaluation(postfix);
    return 0;
}