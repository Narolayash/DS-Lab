// write a program that determines if a given number is happy number or not.

#include <stdio.h>

int squares(int n) {
    int sum = 0;
        while(n > 0) {
            sum += (n%10) * (n%10);
            n /= 10;
        }
    return sum;
}

void happyNumber(int n) {
    int slow = n, fast = n;

    do{
        slow = squares(slow);
        fast = squares(squares(fast));    
    }   while (slow != fast);

    if(slow == 1)
        printf("the given number is happy number \n");
    else 
        printf("the given number is not happy number \n");
}

int main() {
    int n;
    printf("Enter the nunber :");
    scanf("%d", &n);

    happyNumber(n);
    return 0;
}