// 32. Read two matrices, first 3x2 and second 2x3, perform multiplication operation 
// and store result in third matrix and print it. 

#include <stdio.h>
int main() {
    int ary1[3][2], ary2[2][3], multi[3][3];

    // initialation of array-1
    printf("--- Enter the element of Array-1 (3 cross 2 ) ---> \n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<2; j++) {
            printf("Enter the %d, %d number :", (i+1), (j+1));
            scanf("%d", &ary1[i][j]);   
        }
    }

    // initialation of array-2
    printf("--- Enter the element of Array-2 (2 cross 3 ) ---> \n");
    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            printf("Enter the %d, %d number :", (i+1), (j+1));
            scanf("%d", &ary2[i][j]);   
        }
    }

    // multiplication operation
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            int temp = 0;
            for(int k=0; k<2; k++) {
                temp += ary1[i][k] * ary2[k][j] ;
            }
            multi[i][j] = temp;
        }
    }

    // mutiplication of array is
    printf("Multiplication of given array is --- > \n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ",multi[i][j]);
        }
        printf("\n");
    }

    return 0;
}