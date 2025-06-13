// WAP to reverse a number.
#include <stdio.h>

int main() {
    // input number
    int n, ans = 0;
    printf("Enter the number :");
    scanf("%d", &n);

    //logic to reverse number
    while (n != 0) {
        ans = (ans * 10) + (n % 10);
        n /= 10;
    }

    printf("Answer is = %d", ans);

    return 0;
}