#include <stdio.h>

void init(int hashSet[], int size) {
    for(int i=0; i<size; i++)
        hashSet[i] = -1;
}

void add(int hashSet[], int size, int value) {
    int index = value % size;
    
    if(hashSet[index] == -1) {
        hashSet[index] = value;
        return;
    }
    
    else if(hashSet[index] == value) {
        printf("Key already exists. \n");
        return;
    }
    
    else {
        for(int prob=1; prob<size; prob++) {
            int i = (index + prob) % size;

            if(hashSet[i] == -1) {
                hashSet[i] = value;
                return;
             }

            else if(hashSet[i] == value) {
                printf("Key already exists. \n");
                return;
            }
        }
    }
}

int main() {
    int hashSet[10];
    int size = 10;
    init(hashSet, size);

    add(hashSet, size, 5);
    add(hashSet, size, 15);
    add(hashSet, size, 25);
    add(hashSet, size, 35);
    
    // display();/

    return 0;
}
