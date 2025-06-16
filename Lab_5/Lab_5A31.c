// 31. Read two 2x2 matrices and perform addition of matrices into third matrix and 
// print it

#include <Stdio.h>

int main() {
    int ary1[2][2], ary2[2][2], sum[2][2];

    // initialation of array-1
    printf("--- Enter the element of Array-1 (2 cross 2 ) ---> \n");
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            printf("Enter the %d, %d number :", (i+1), (j+1));
            scanf("%d", &ary1[i][j]);   
        }
    }

    // initialation of array-2
    printf("--- Enter the element of Array-2 (2 cross 2 ) ---> \n");
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            printf("Enter the %d, %d number :", (i+1), (j+1));
            scanf("%d", &ary2[i][j]);   
        }
    }

    // for sum of array-1 and array-2
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            sum[i][j] = ary1[i][j] + ary2[i][j]; 
        }
    }

    // total array
    printf("Sum of given array is --- > \n");
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}