#include <stdio.h>
#include <string.h>

struct pair {
    char key[5];
    int value;
};

int findIndex(char key[]) {
    int sum = 0;
    for(int i=0; i<strlen(key); i++) {
        sum += key[i];
    }

    return sum;
}

void add(struct pair hashMap[], int size, char key[], int value) {
    int index = findIndex(key) % size;

    if(hashMap[index].key[0] == "\0") {
        strcpy(hashMap[index].key, key);
        hashMap[index].value = value;
        return;
    }
    else if(strcmp(hashMap[index].key, key) == 0) {
        hashMap[index].value = value;
        return;
    }
    else {
        for(int prob=1; prob<size; prob++) {
            int i = (index + prob) % size;

            if(hashMap[i].key[0] == '\0') {
                strcpy(hashMap[i].key, key);
                hashMap[i].value = value;
                return;
            }
            else if(strcmp(hashMap[i].key, key) == 0) {
                hashMap[i].value = value;
                return;
            }
        }
    }
}

void display(struct pair hashMap[], int size) {
    for(int i=0; i<size; i++) {
        if(hashMap[i].key[0] != '\0')
            printf("[%d] %s -> %d\n", i, hashMap[i].key, hashMap[i].value);
        else
            printf("[%d] empty\n", i);
    }
}


int main() {
    int size = 10;
    struct pair hashMap[10];

    // Initialize
    for(int i=0; i<size; i++) {
        hashMap[i].key[0] = '\0';
    }

    // Insert some values
    add(hashMap, size, "cat", 10);
    add(hashMap, size, "dog", 20);
    add(hashMap, size, "bat", 30);

    display(hashMap, size);


    return 0;
}