// 37. Valid Parenthesis Problem 
// Chef has a string which contains only the characters '{', '}', '[', ']', '(' and ')'.  
// Now Chef wants to know if the given string is balanced or not.  
// If is balanced then print 1, otherwise print 0.  
// A balanced parenthesis string is defined as follows: 
// • The empty string is balanced 
// • If P is balanced then (P), {P}, [P] is also balanced 
// • if P and Q are balanced PQ is also balanced 
// • "([])", "({})[()]" are balanced parenthesis strings  
// • "([{]})", "())" are not balanced. 
 
// Input Format:  
// The first line of the input contains a single integer T denoting the number of 
// test cases. The description of T test cases follows. The first and only line of 
// each test case contains a single string 
 
// Output Format:  
// For each test case, print a single line containing the answer. 

// Sample Example: 
// Input:  
// 4 
// () 
// ([)] 
// ([{}()])[{}] 
// [{{}] 
 
//  Output: 
// 1 
// 0 
// 1 
// 0 

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

int chefStr(char str[]) {
    char stack[50];
    int top = -1;
    int size = sizeof(stack) / sizeof(stack[0]);

    int i = 0; 
    while (str[i] != '\0') {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') 
            push(stack, size, &top, str[i++]);
        
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if(top == -1) return 0;
            
            char last = pop(stack, &top);
            if((last == '(' && str[i] != ')') || 
                (last == '{' && str[i] != '}') ||
                (last == '[' && str[i] != ']')) {
                return 0;
            }
            i++;
        }
        else {
            printf("Another characters are ouure... \n");
            return 0;
        }
    }

    return (top == -1); 
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        char str[50];
        scanf("%s", str);
        printf("%d\n", chefStr(str));
    }

    return 0;
}