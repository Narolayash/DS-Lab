// 17. Write a program to calculate sum of numbers from m to n.
#include <stdio.h>

int main() {
    // input first number and last number
    int start, end, sum = 0;
    printf("Enter the starting number : ");
    scanf("%d", &start);
    printf("Enter the ending nubmer : ");
    scanf("%d", &end);

    // sum of first number to last number 
    for(int i = start; i <= end; i++) {
        sum += i;
    }
    printf("Answer = %d", sum);

    return 0;
}

// int main() {
//     int size;
//     printf("Enter the Size of Array :");
//     scanf("%d", &size);

//     int array[size];

//     // read array --->
//     printf("--- Enter The Element of Array --- \n");
//     for(int i=0; i<size; i++) {
//         printf("Enter %d number (index %d) :", (i+1), i);
//         scanf("%d", &array[i]);
//     }

//     // display array --->
//     printf("--- Your Array is --- \n");
//     for(int i=0; i<size; i++) {
//         printf("%d ", array[i]);
//     }

//     printf("\n");
    
//     // for sum --->
//     int m, n, sum=0;
//     printf("Note: Index Start from 0 \n");
//     printf("for sum enter start index :");
//     scanf("%d", &m);

//     printf("for sum enter end index :");
//     scanf("%d", &n);

//     for(int i=m; i<=n; i++) {
//         sum += array[i];
//     }

//     printf("Ans = %d", sum);

//     return 0;
// }