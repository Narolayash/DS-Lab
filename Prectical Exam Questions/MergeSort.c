#include <stdio.h>

void merge(int array[], int low, int mid, int high) {
    int h=low, i=low, j=mid+1, k;
    int b[high+1];

    while(h <= mid && j <= high) {
        if(array[h] <= array[j]) {
            b[i] = array[h];
            h++;
        }
        else {
            b[i] = array[j];
            j++;
        }
        i++;
    }

    if(h > mid) {
        for(int k=j; k<=high; k++) {
            b[i] = array[k];
            i++;
        }
    }
    else {
        for(int k=h; h<=mid; k++) {
            b[i] = array[k];
            i++;
        }
    }

    for(int i=0; i<=high; i++) {
        array[i] = b[i];
    }
}

void mergeSort(int array[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid+1, high);
        merge(array, low, mid, high);
    }
}