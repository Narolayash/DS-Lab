// 28. Write a program to delete duplicate numbers from an array.
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

    // remove duplicate from array
    for(int i=0; i<(in-1); i++) {
        for(int j=(i+1); j<in; j++) {
            if(ary[i] == ary[j]) {
                for(int k=j; k<in; k++) {
                    ary[k] = ary[k+1];
                }
                j--;
                in--;
            }
        }
    }

    //print final array
    for(int i=0; i<in; i++) {
        printf("%d ", ary[i]);
    }

    return 0;
}