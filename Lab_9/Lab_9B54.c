// 54. WAP to check whether the string is Palindrome or not using Pointer. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void checkStringPalindrome(char *);

int main() {
    //input size of string 
    int sizeOfStr;
    printf("Enter the size of String : ");
    scanf("%d", &sizeOfStr);

    //create memory for string 
    char *str = (char *) malloc( (sizeOfStr+1) * sizeof(char) );

    //if memory is not allocted 
    if(str == NULL) {
        printf("Memory allocation failed!\n ");
        return 1;
    }

    // input string 
    printf("Enter the String : ");
    scanf("%s", str);
    // gets(str);

    checkStringPalindrome(str);

    return 0;
}

void checkStringPalindrome(char *str) {
    char *start = str;
    char *end = str + (strlen(str) - 1);

    int flag = 0;
    while(start < end) {
        if(*start != *end) {
            flag = 1;
            break;
        }
        start++;
        end--;
    }

    if(flag) {
        printf("Not Palindrome");
    }
    else {
        printf("Palindrome");
    }
}