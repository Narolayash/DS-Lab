// 35. How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a 
// program to solve the above problem. 

#include <stdio.h>

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

void recognize(char str[]) {
    char stack[50];
    int size = sizeof(stack) / sizeof(stack[0]);
    int top = -1;

    int i = 0;
    while(str[i] != 'c') {
        push(stack, size, &top, str[i++]);
    }

    int flag = 1;
    while (str[++i] == '\0') {
        if(pop(stack, &top) != str[i]) {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("valid \n");
    else 
        printf("Invalid \n");
}

int main() {
    char str[20];
    printf("Enter the string : ");
    scanf("%s", str);

    recognize(str);

    return 0;
}