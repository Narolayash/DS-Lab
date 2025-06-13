// 18. Write a program to calculate average of first n numbers.
#include <stdio.h>

int main() {
    // input number 
    int n, sum=0;
    printf("Enter the Number :");
    scanf("%d", &n);

    // sum of first number
    for(int i=1; i<=n; i++) {
        sum += i;
    }

    // calculate avg 
    double avg = (double)sum / n;
    printf("Answer is = %f", avg);

    return 0;
}