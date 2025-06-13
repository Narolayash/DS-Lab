// 24. Write a program to insert a number at a given location in an array.
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

    // number for insert
    int n;
    printf("Enter the number which one you want to insert : ");
    scanf("%d", &n);

    // index location
    int loc;
    printf("at which location :");
    scanf("%d", &loc);

    // logic for inserting 
    for(int i=loc; i<=in ; i++) {
        int temp = ary[i];
        ary[i] = n;
        n =  temp;
    }

    //print final array
    for(int i=0; i<=in; i++) {
        printf("%d ", ary[i]);
    }


    return 0;
}