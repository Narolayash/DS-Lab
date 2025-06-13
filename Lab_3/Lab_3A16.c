// 16. Write a program to read and display n numbers using an array.
#include <stdio.h>

int main() {
    // input size of array
    int n;
    printf("Enter the Size of Array :");
    scanf("%d", &n);

    // make array
    int array[n];

    // read array --->
    printf("--- Enter The Element of Array --- \n");
    for(int i=0; i<n; i++) {
        printf("Enter %d number :", (i+1));
        scanf("%d", &array[i]);
    }

    // display array --->
    printf("--- Your Array is --- \n");
    for(int i=0; i<n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}