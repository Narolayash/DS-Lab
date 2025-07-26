// write a program to print non-duplicate element of an array
#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);

    int ary[size];

    for(int i=0; i<size; i++) {
        printf("Ary[%d] : ", (i+1));
        scanf("%d", &ary[i]);
    }

    printf("Non-duplicate element of an array : ");
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (ary[i] == ary[j])
                count++;
        }
        if (count == 1)
            printf("%d ", ary[i]);
    }

    return 0;
}