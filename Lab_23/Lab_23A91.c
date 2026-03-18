// 91. Write a program to implement Insertion Sort using Array. 

#include <stdio.h>

void insertionSort(int array[], int size) {
    for(int i=1; i<size; i++) {
        int j = i - 1, key = array[i];
        while(j>=0 && array[j]>key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}
