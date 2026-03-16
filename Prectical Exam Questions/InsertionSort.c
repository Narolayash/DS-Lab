#include <stdio.h>

void insertionSort(int array[], int size) {
    int i = 1; 
    while (i < size) {
        int key = array[i];
        int j = i-1;
            while (j >= 0 && array[j] > key) {
                array[j+1] = array[j];
                j--;
            }
        array[j+1] = key;
        i++;  
    } 
}