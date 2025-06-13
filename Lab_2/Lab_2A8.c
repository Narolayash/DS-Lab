// WAP to find factorial of a number. (Using loop & recursion)
#include <stdio.h>

// int main() {    
//     // input number
//     int n, ans;
//     printf("Enter the Number: ");
//     scanf("%d", &n);

//     // to find factorial using loop
//     if(n == 0 || n == 1) {
//         ans = 1;
//     }
//     else {
//         ans = 1;
//         for(int i = 2; i<=n ; i++) {
//             ans = ans * i;
//         }
//     }
//     printf("Factorial of your number is = %d", ans);
//     return 0;
// }

int factorial (int);
int main() {
    // input number
    int n, ans;
    printf("Enter the number :");
    scanf("%d", &n);

    // call function
    ans = factorial(n);
    printf("Answer is = %d", ans);

    return 0;
}

//function to find factorial
int factorial (int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}