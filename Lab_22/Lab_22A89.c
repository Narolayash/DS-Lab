// 89. Write a program to implement Bubble using Array. 

#include <stdio.h>

void bubbleSort(int array[], int size) {
    for(int i=0; i<size-1; i++) {
        int flag = 1;
        for(int j=0; j<size-1-i; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = 0;
            }
        }
        if(flag) 
            return;
    }
}

int main() {
    int array[50], size;

    printf("How many numbers you want to store: ");
    scanf("%d", &size);

    // insert elements into the array
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // call bubble sort
    bubbleSort(array, size);

    // print sorted array
    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
