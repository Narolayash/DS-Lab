// 29. Write a program to merge two unsorted arrays.

#include <stdio.h>

int main() {
    int ary1[25], ary2[25], merge[50];

    // initialation of array-1
    int in_1;
    printf("How many number you want to enter (in array-1) :");
    scanf("%d", &in_1);

    printf("--- Enter the element for Array-1 ---> \n");
    for(int i=0; i<in_1; i++) {
        printf("Enter the %d number :", (i+1));
        scanf("%d", &ary1[i]);
    }

    // initialation of array-2
    int in_2;
    printf("How many number you want to enter (in array-2) :");
    scanf("%d", &in_2);

    printf("--- Enter the element for Array-2 ---> \n");
    for(int i=0; i<in_2; i++) {
        printf("Enter the %d number :", (i+1));
        scanf("%d", &ary2[i]);
    }

    //merged array
    int i, j;
    for(i=0; i<in_1; i++) {
        merge[i] = ary1[i];
    }
    for(j=0; j<in_2; j++) {
        merge[i+j] = ary2[j];
    }

    //print final array
    for(int i=0; i<(in_1 + in_2); i++) {
        printf("%d ", merge[i]);
    }

    return 0;
}