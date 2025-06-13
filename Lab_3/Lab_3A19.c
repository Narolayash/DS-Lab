// 19. Write a program to find position of the smallest number & the largest number 
// from given n numbers.
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
    //to find the smallest number 
    int smallest = array[0];
    for(int i=1; i<size; i++) {
        if(smallest > array[i]) {
            smallest = array[i];
        }
    }
    printf("Smallers number = %d \n", smallest);

    // to find the largest number 
    int largest = array[0];
    for(int i=1; i<size; i++) {
        if(largest < array[i]) {
            largest = array[i];
        }
    }
    printf("Smallers number = %d \n", largest);

    return 0;
}