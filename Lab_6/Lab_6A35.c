// 35. How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a 
// program to solve the above problem. 
#include <stdio.h>

// PUSH
void push(char stack[], int size, int* top, char val) {
    if(*top >= size) {
        printf("stack overflow \n");
        return;
    }

    stack[++(*top)] = val;
}

// POP
char pop(int stack[], int*top) {
    if (*top <= -1) {
        printf("stack underflow\n");
        return '\0'; // return a sentinel char
    }
    else
        return (stack[(*top)--]);
}

void recognize(char str[]) {
    int stack[50], top = -1;
    int size = sizeof(stack) / sizeof(stack[0]);

    int i = 0;
    char next = str[i];
    while (next != 'c') {
        push(stack, size, &top, next);
        next = str[i++];
    }

    next = str[++i];
    int flag = 1;
    while(next != '\0') {
        if(next != pop(stack, &top)) {
            printf("String is invalid \n");
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("string is valid \n");

    else 
        printf("string is not valid \n");
}

int main() {
    char test1[] = "aca";
    char test2[] = "abcba";
    char test3[] = "abbcbba";

    recognize(test1);  // valid
    recognize(test2);  // invalid (for your logic)
    recognize(test3);  // invalid

    return 0;
}