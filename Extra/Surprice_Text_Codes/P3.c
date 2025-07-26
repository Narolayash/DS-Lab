#include <stdio.h>

void fibonacci(int n) {
    int first=0, last=1, sum=0;
    for(int i=0; i<n; i++) {
        printf("%d ", first);
        sum = first + last;
        first = last;
        last = sum;
    }
}

int main() {
    int n;
    printf("Enter the number of steps : ");
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}