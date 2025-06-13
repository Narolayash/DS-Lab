#include<stdio.h>


int intInsert(int );
int main() {
    int ary[50];
    // initialation of array
    int in;
    printf("How many number you want to enter :");
    scanf("%d", &in);

    printf("--- ---- ---0Note: Enter Numbers in Ascending Order --- --- ---\n");
    printf("--- Enter the element for Array ---> \n");
    for(int i=0; i<in; i++) {
        printf("Enter the %d number :", (i+1));
        scanf("%d", &ary[i]);
    }

    //intpur nnumber which one insert in array
    int n;
    printf("Enter the number which one you want to insert in array :");
    scanf("%d", &n);

    //logic to insert number in shorted array
    for(int j=0; j<=in; j++) {
        if(n < ary[j]) {
            int temp = ary[j];
            ary[j] = n;
            n =  temp;
        }
    }

    //print final array
    for(int i=0; i<=in; i++) {
        printf("%d ", ary[i]);
    }

    return 0;
}