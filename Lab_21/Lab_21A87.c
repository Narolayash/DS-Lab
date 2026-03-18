// 87. Write a program to implement a Linear Search using Array.   

#include <stdio.h>

int linearSearch(int array[], int size, int key) {
    for(int i=0; i<size; i++) {
        if(array[i] == key) return i;
    }

    return -1;
}

int main() {
    int array[50], size;
    printf("How many number you want to store : ");
    scanf("%d", &size);

    // insert elemment into the array
    for(int i=0; i<size; i++) {
        printf("Enter the elemene %d :", i+1);
        scanf("%d", &array[i]);
    }
    printf("\n");

    int key;
    printf("Enter the nubmer u want to find :");
    scanf("%d", &key);

    int flag = linearSearch(array, size, key);

    if (flag != -1)
        printf("Element %d found at position %d\n", key, flag + 1);
    else
        printf("Element %d not found in the array\n", key);

    return 0;
}
