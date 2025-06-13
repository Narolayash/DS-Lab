// 21. Read n numbers in an array then read two different numbers, replace 1st 
// number with 2nd number in an array and print its index and final array. 
#include <stdio.h>

int main () {
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

    // for replace numbers input oldnumber and newnumber
    int oldNumber, newNumber;
    printf("Enter the old number ");
    scanf("%d", &oldNumber);
    printf("Enter the new number ");
    scanf("%d", &newNumber);

    printf("index :");
    for(int i=0; i<size; i++) {
        if(array[i] == oldNumber) {
            array[i] = newNumber;
            printf("%d, ", i);
        }
    }

    printf("\n");

    // final array --->
    printf("--- Your final Array is --- \n");
    for(int i=0; i<size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}