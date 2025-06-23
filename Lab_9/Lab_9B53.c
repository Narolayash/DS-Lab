// 53. WAP to sort the array elements using Pointer. 

#include <stdio.h>
#include <stdlib.h>

int main() {
    // input size of array
    int sizeOfAry ;
    printf("Enter the size of array : ");
    scanf("%d", &sizeOfAry);
    int orgSize = sizeOfAry;

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

    // to find largest number
    for(int i=0; i<sizeOfAry-1; i++) {
        for(int j=0; j<sizeOfAry; j++) {
            if(*(iptr+j) > *(iptr+j+1)) {
                int temp = *(iptr+j);
                *(iptr+j) = *(iptr+j+1);
                *(iptr+j+1) = temp;
            }
        }
        sizeOfAry--;
    }

    // pirnt array after sortint array
    printf("\n --- Your Array after sorting  --->>> \n");
    for(int i=0; i<orgSize; i++) {
        printf("%d ", *(iptr+i));
    }

    free(iptr);

    return 0;
}