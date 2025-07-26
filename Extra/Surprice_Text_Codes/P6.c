// write a program that merges a two sorted array into third sorted array.
#include <stdio.h>

int main() {
    int size1, size2;

    printf("Array - 1 \n");
    printf("print enter the size of ary1 : ");
    scanf("%d", &size1);

    int ary1[size1];
    for(int i=0; i<size1; i++) {
        printf("ary1[%d] : ", (i+1));
        scanf("%d", &ary1[i]);
    }

    printf("Array - 2 \n");
    printf("print enter the size of ary2 : ");
    scanf("%d", &size2);

    int ary2[size2];
    for(int i=0; i<size2; i++) {
        printf("ary2[%d] : ", (i+1));
        scanf("%d", &ary2[i]);
    }

    // new third array
    int ary[size1 + size2];
    int i=0, j=0, k=0;
    
    while (i < size1 && j < size2) {
        if (ary1[i] < ary2[j])
            ary[k++] = ary1[i++];
        else
            ary[k++] = ary2[j++];
    }

    while (i < size1) {
        ary[k++] = ary1[i++];
    }

    while (j < size2) {
        ary[k++] = ary2[j++];
    }

    for(int i=0; i<size1+size2; i++) {
        printf("%d ", ary[i]);
    }

    return 0;
}