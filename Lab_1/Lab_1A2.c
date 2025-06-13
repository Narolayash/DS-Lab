// 2. WAP to find whether a number is odd or even
#include<stdio.h>

int main () {
    //input number
    int n;
    printf("Enter the Number ");
    scanf("%d", &n);

    //logic to find number is even or odd
    if (n % 2 == 0) {
        printf("Number is even ");
    }
    else {
        printf("Number is odd");
    }
    
    return 0;
}