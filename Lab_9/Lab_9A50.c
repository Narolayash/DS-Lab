// 50. WAP to get and print the array elements using Pointer. 

#include <stdio.h>
#include <stdlib.h>

void input_array( int * , int );
void print_array( int * , int );

int main() {
    // input size of array
    int sizeOfAry;
    printf("Enter the size of array : ");

    // Allocate memory...
    scanf("%d", &sizeOfAry); 
    int *iptr = (int *) malloc( sizeOfAry * sizeof(int ) );

    // check memory allocation was done or not
    if(iptr == NULL) {
        printf("Allocation is failed ");
        return 1;
    }
    
    //input arrays values
    input_array(iptr, sizeOfAry);

    //print arrays elements
    print_array(iptr, sizeOfAry);

    free(iptr);

    return 0;
}

// input array elements 
void input_array( int * ptr, int sizeOfAry){
    for(int i=0; i<sizeOfAry; i++) {
        printf("Enter %dth element of array : ", (i+1));
        // scanf("%d", &iptr[i]);      //valid
        scanf("%d", (ptr + i));    //valid
    }
}

// print array elements
void print_array( int * ptr, int sizeOfAry) {
    printf("--- Your Array Is --->>> \n");
    for(int i=0; i<sizeOfAry; i++) {
        // printf("%d ", iptr[i]);         //valid
        printf("%d ", *(ptr + i));      //valid
    }
}