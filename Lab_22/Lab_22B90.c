// 90. Write a program to implement Selection Sort using Array. 

#include <stdio.h>

void selectionSort(int array[], int size){
    for(int i=0; i<size-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<size; j++) {
            if(array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp; 
       }
    }
}


int main() {
    int array[50], size;

    printf("How many numbers you want to store: ");
    scanf("%d", &size);

    // Insert elements into the array
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Call selection sort
    selectionSort(array, size);

    // Print sorted array
    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}