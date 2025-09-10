// 88. Write a program to implement a Binary Search using Array. (Iterative & 
// recursive) 

#include <stdio.h>

int binarySearch(int array[], int size, int key) {
    int first = 0, last = size-1;
    
    while(first <= last) {
        int mid = (first + last) / 2;
        
        if(array[mid] == key) return mid;
        else if(array[mid] > key) last = mid-1;
        else first = mid+1;
    }

    return -1;
}

int binarySearchRec(int array[], int first, int last, int key) {
    if(first <= last) {
        int mid = (first + last) / 2;

        if(array[mid] == key) 
            return mid;
        else if(array[mid] > key) 
            return binarySearchRec(array, first, mid-1, key);
        else 
            return binarySearchRec(array, mid+1, last, key);    
    }
    return -1;  
}


int main() {
    int array[50], size;
    printf("How many numbers you want to store (sorted array): ");
    scanf("%d", &size);

    // insert element into the array
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("\n");

    int key;
    printf("Enter the number you want to find: ");
    scanf("%d", &key);

    int result1 = binarySearch(array, size, key);
    if (result1 != -1)
        printf("[Iterative] Element %d found at position %d\n", key, result1 + 1);
    else
        printf("[Iterative] Element %d not found in the array\n", key);

    int result2 = binarySearchRec(array, 0, size - 1, key);
    if (result2 != -1)
        printf("[Recursive] Element %d found at position %d\n", key, result2 + 1);
    else
        printf("[Recursive] Element %d not found in the array\n", key);

    return 0;
}
