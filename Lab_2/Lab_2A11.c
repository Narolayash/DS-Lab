// WAP to find factors of a given number.
#include <stdio.h>

int main() {
    // input number
    int n;
    printf("Enter the number :");
    scanf("%d", &n);

    //find factors
    printf("Factors of nubmer %d : ", n);
    for (int i=1; i <= n; i++) {
        if(n % i == 0) {
            printf("%d, ", i);
        }
    }
    
    return 0;
}