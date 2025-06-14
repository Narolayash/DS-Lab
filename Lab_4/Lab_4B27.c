// 27. Write a program to delete a number from an array that is already sorted in an 
// ascending order.
#include<stdio.h>

int main() {
    int ary[50];
    // initialation of array
    int in;
    printf("How many number you want to enter :");
    scanf("%d", &in);

    printf("--- ---- --- Note: Enter Numbers in Ascending Order --- --- ---\n");
    printf("--- Enter the element for Array ---> \n");
    for(int i=0; i<in; i++) {
        printf("Enter the %d number :", (i+1));
        scanf("%d", &ary[i]);
    }

    //intpur nnumber which one delete in array
    int n;
    printf("Enter the number which one you want to delete in array :");
    scanf("%d", &n);

    //logic to insert number in shorted array
    for(int j=0; j<in; j++) {
        if(n == ary[j]) {
            n = ary[j+1];
            ary[j] = n;
        }
    }

    //print final array
    for(int i=0; i<in-1; i++) {
        printf("%d ", ary[i]);
    }

    return 0;
}