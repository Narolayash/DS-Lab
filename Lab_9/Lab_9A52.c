// 52. WAP to find the largest element in the array using Pointer. 

#include <stdio.h>
#include <stdlib.h>

int main() {
    // input size of array
    int sizeOfAry ;
    printf("Enter the size of array : ");
    scanf("%d", &sizeOfAry);

    // initialition of poiter array
    int* iptr = (int* ) malloc( sizeOfAry * sizeof(int));
    if (iptr == 0) {
        printf("Memory allocation failed\n");
        return 1;
    } 

    // input array values
    for(int i=0; i<sizeOfAry; i++) {
        printf("Enter %dth of array : ", (i+1));
        scanf("%d", (iptr+i) );
    }

    // pirnt array elements
    printf("--- Your Array Is --->>> \n");
    for(int i=0; i<sizeOfAry; i++) {
        printf("%d ", *(iptr+i));
    }

    // to find largest number
    int max = iptr[0];
    for(int i=1; i<sizeOfAry; i++) {
        if(max < iptr[i]) {
            max = iptr[i];
        }
    }

    //print largest number
    printf("\nLargest number is = %d", max);

    free(iptr);

    return 0;
}