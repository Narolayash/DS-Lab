#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter the three numbers (add space beteen numbers) : \n");
    scanf("%d %d %d", &a, &b, &c);

    if(a > b && a > c)
        printf("%d is largest number from given 3 numbers \n", a);

    else if (b > a && b > c)
        printf("%d is largest number from given 3 numbers \n", b);

    else 
        printf("%d is largest number from given 3 numbers \n", c);

    return 0;
}