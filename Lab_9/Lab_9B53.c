// 53. WAP to sort the array elements using Pointer. 

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *iptr, int sizeOfAry) {
    for(int i=0; i<sizeOfAry-1; i++) {
        for(int j=0; j<sizeOfAry-1-i; j++) {
            if(*(iptr+j) > *(iptr+j+1)) {
                int temp = *(iptr+j);
                *(iptr+j) = *(iptr+j+1);
                *(iptr+j+1) = temp;
            }
        }
    }
}

int main() {
    // input size of array
    int sizeOfAry ;
    printf("Enter the size of array : ");
    scanf("%d", &sizeOfAry);

    // initialition of poiter array
    int* iptr = (int* ) malloc( sizeOfAry * sizeof(int ) );
    if (!iptr) {
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
    bubbleSort(iptr, sizeOfAry);


    // pirnt array after sortint array
    printf("\n --- Your Array after sorting  --->>> \n");
    for(int i=0; i<sizeOfAry; i++) {
        printf("%d ", *(iptr+i));
    }

    free(iptr);

    return 0;
}