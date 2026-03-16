// 38. Removing starts from a string Problem 
// You are given a string s, which contains stars *. In one operation, you can: 
// Choose a star in s. Remove the closest non-star character to its left, as well as 
// remove the star itself. Return the string after all stars have been removed. 

// Note :  
// • The input will be generated such that the operation is always possible. 
// • It can be shown that the resulting string will always be unique. 

// Sample Example-1: 
// Input: s = "leet**cod*e".             
// Output: "lecoe" 

// Sample Example-2: 
// Input: s = "erase*****"     
// Output: "" 

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

void removingStar(char str[]) {
    char stack[50];
    int top = -1;
    int size = sizeof(stack) / sizeof(stack[0]);

    for(int i=0; str[i] != '\0'; i++) {
        if(str[i] == '*') 
            pop(stack, &top);
        else 
            push(stack, size, &top, str[i]);
    }

    for(int i=0; i<=top; i++) {
        printf("%c", stack[i]);
    }
}

int main() {
    char str[50];
    printf("Enter the string : ");
    scanf("%s", str);

    removingStar(str);
    return 0;
}
