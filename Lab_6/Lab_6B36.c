// 36. Write a program to determine if an input character string is of the form aibi 
// where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’.

#include <stdio.h>

void push(char stack[], int size, int* top, char val) {
    if(*top >= size - 1) {
        printf("Stack overflow \n");
        return;
    }
    stack[++(*top)] = val;
}

char pop(char stack[], int* top) {
    if(*top < 0) {
        printf("Stack underflow \n");
        return '\0';
    }
    return stack[(*top)--];
}

void aibi(char str[]) {
    char stack[50];
    int top = -1;
    int size = sizeof(stack) / sizeof(stack[0]);

    int i = 0;
    while(str[i] != '\0') {
        if(str[i] == 'a' || str[i] == 'b') {
            if(top < 0 || stack[top] == str[i])
                push(stack, size, &top, str[i++]);
            else {
                pop(stack, &top);
                i++;
            }
        }
        else  {
            printf("Invalid string \n");
            return;
        }
    }

    if(top < 0) 
        printf("Valid string \n");
    else 
        printf("number of a != number of b");
}

int main() {
    char str[50];
    printf("Enter the string : ");
    scanf("%s", str);

    aibi (str);
    return 0;
}
