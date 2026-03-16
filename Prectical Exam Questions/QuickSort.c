#include <stdio.h>

void quickSort(int array[], int low, int high) {
    int flag = 1;
    if (low < high) {
        int i = low;
        int j = high + 1;
        int key = array[low];

        while (flag) {
            i++;
            while(array[i] < key)
                i++;
            j--;
            while(array[j] > key)
                j--;
            
            if(i<j) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            else flag = 0;
        }
        
        int temp = array[low];
        array[low] = array[j];
        array[j] = temp;

        quickSort(array, low, j-1);
        quickSort(array, j+1, high);
    }
}