// 12. WAP to check whether a number is prime or not. 
#include <stdio.h>

int main() {
    // input number
    int n, flag = 0;
    printf("Enter the Number :");
    scanf("%d", &n);

    // logic to find number is prime or not
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        printf("Number is prime");
    }

    else {
        printf("Number is Not Prime");
    }

    return 0; 
}