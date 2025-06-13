// 4. WAP to find the largest among the given three numbers by user. 
#include<stdio.h>
int main() {
    //input three numbers
    int a,b,c;
    printf("Enter First Number :");
    scanf("%d" , &a);
    printf("Enter Second Number :");
    scanf("%d" , &b);
    printf("Enter Third Number :");
    scanf("%d" , &c);

    //logic to find largest number among three numbers
    if ( a > b && a > c ) {
        printf("First number %d is largest", a);
    }
    else if ( b > a && b > c ) {
        printf("Second number %d is largest", b);
    }
    else {
        printf("Third number %d is largest", c);
    }
    
    return 0;
}