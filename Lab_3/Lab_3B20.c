// 20. Write a program to find whether the array contains a duplicate number or not. 
#include <stdio.h>

int main() {
    // input size of ary
    int size;
    printf("Enter the Size of Array :");
    scanf("%d", &size);

    // make ary
    int array[size];

    // read array --->
    printf("--- Enter The Element of Array --- \n");
    for(int i=0; i<size; i++) {
        printf("Enter %d number (index %d) :", (i+1), i);
        scanf("%d", &array[i]);
    }

    // display array --->
    printf("--- Your Array is --- \n");
    for(int i=0; i<size; i++) {
        printf("%d ", array[i]);
    }

    
    printf("\n");
    //check : array containes duplicate or not
    int bool = 0;
    for(int i=0; i<(size-1); i++) {
        for(int j=(i+1); j<size; j++) {
            if(array[i] == array[j]){
                bool++;
                break;
            }
        }
    }
    if (bool != 0) {
        printf("Yes, There are duplicates ");
    }
    else {
        printf("No, There are no duplicates ");
    }

    return 0;
}