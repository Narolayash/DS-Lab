// 2. WAP to find whether a number is odd or even
#include<stdio.h>

void oddOReven(int n) {
    //logic to find number is even or odd
    if (n % 2 == 0) {
        printf("Number is even ");
    }
    else {
        printf("Number is odd");
    }
}

int main () {
    //input number
    int n;
    printf("Enter the Number :");
    scanf("%d", &n);
    oddOReven(n);
    
    return 0;
}