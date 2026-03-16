#include <stdio.h>

void bubbleSort(int array[], int size) {
    int last = size-1;
    for(int i=0; i<size-1; i++) {
        int exchs = 0;
        for(int j=0; j<last; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                exchs++;
            }
        }
        if(exchs == 0) return;
        else last--;
    }
}