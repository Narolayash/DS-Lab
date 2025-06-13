// 22. WAP to print Pascal triangle. 
#include <stdio.h>

int combination(int, int);
int factorial(int);
int main() {
    //Number of Rows --->
    int row;
    printf("Enter the number of Rows :");
    scanf("%d", &row);

    // loop for print 
    for(int i=0; i<row ; i++) {
        for(int k=0; k<row-1-i; k++) {
            printf(" ");
        }

        for(int j=0; j<=i ; j++) {
            printf("%d ", combination(i, j));
        }
        printf("\n");
    }

    return 0;
}

// function to find factorial
int factorial(int a) {
    int facto = 1;
    for(int i=1; i<=a; i++) {
        facto *= i;
    }
    return facto;
}

// function to return n-C-r
int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

//     1
//    1 1
//   1 2 1
//  1 3 3 1
// 1 4 6 4 1 