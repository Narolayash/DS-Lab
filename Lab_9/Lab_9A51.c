// 51. WAP to calculate the sum of n numbers using Pointer. 

#include <stdio.h>
#include <stdlib.h>

int main() {
    // input size of array
    int sizeOfAry ;
    printf("Enter the size of array : ");
    scanf("%d", &sizeOfAry);

    // initialition of poiter array
    int* iptr = (int* ) malloc( sizeOfAry * sizeof(int ) );

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

    // sum of all array elements
    int sum = 0;
    for(int i=0; i<sizeOfAry; i++) {
        sum += *(iptr + i);
    }

    // print sum
    printf("\n Sum of all element = %d", sum);

    free(iptr);
    return 0;
}