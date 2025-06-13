#include <stdio.h>

int main() {
    int ary[50];
    // initialation of array
    int in;
    printf("How many number you want to enter :");
    scanf("%d", &in);

    printf("--- Enter the element for Array ---> \n");
    for(int i=0; i<in; i++) {
        printf("Enter the %d number :", (i+1));
        scanf("%d", &ary[i]);
    }

    // Enter locatoin which one your want to delete
    int loc;
    printf("at which location you want to delete number :");
    scanf("%d", &loc);

    //logic for deleting element 
    for(int i=loc; i<in; i++) {
        ary[i] = ary[i+1];
    }

    //print final array
    for(int i=0; i<in-1; i++) {
        printf("%d ", ary[i]);
    }
    return 0;
}