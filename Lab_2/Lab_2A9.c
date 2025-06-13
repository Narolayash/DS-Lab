// 9. WAP to find power of a number using loop. 
#include <stdio.h>

int main() {
    // input number and it's power
    int a, n, ans;
    printf("Enter the Number :");
    scanf("%d", &a);
    printf("Enter Power :");
    scanf("%d", &n);

    if(n == 0) {
        ans = 1;
    }
    else {
        ans = 1;
        // to find power using loop
        for(int i = 0; i<n; i++) {
            ans *= a;
        }
    }
    printf("Answer = %d", ans );
    
    return 0;
}

// int power (int, int );
// int main() {
//     // input number and it's power
//     int a, n, ans;
//     printf("Enter the Number :");
//     scanf("%d", &a);
//     printf("Enter Power :");
//     scanf("%d", &n);

//     //call function
//     ans = power(a, n);
//     printf("Answer = %d", ans);
//     return 0;
// }

// // to find power using recursion
// int power (int a, int n) {
//     if(n == 0) {
//         return 1;
//     }
//     else {
//         return a * power(a, n - 1);
//     }
// }