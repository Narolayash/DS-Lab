#include<stdio.h>
int main() {
    int n;
    int a = 1;
    printf("Enter the number :");
    scanf("%d", &n);
    for (int i = 0; i<n ; i++) {
        for(int j = 0; j<=i ; j++) {
            printf("%d ", a++);
        }
        printf("\n");
    }
    return 0;
}