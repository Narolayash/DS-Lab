#include <stdio.h>

// iterative approach
// int binarySearch(int array[], int size, int key) {
//     int left = 0, right = size - 1;

//     while (left <= right) {
//         int mid = (left + right) / 2; 

//         if(array[mid] == key) return mid;
//         else if(array[mid] > key) left = mid - 1;
//         else right = mid + 1;
//     }

//     return -1;
// }

// recursive approach
int binarySearch(int array[], int left, int right, int key) {
    if(left <= right) {
        int mid = (left + right) / 2;

        if(array[mid] == key) 
            return mid;
        else if(array[mid] > key) 
            return binarySearch(array, left, mid-1, key);
        else 
            return binarySearch(array, mid+1, right, key);
    }

    return -1;
}
