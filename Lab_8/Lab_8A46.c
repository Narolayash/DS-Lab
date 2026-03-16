// 46. Write a menu driven program to implement following operations on the Queue 
// using an Array 
// • ENQUEUE 
// • DEQUEUE 
// • DISPLAY 

#include <stdio.h>

void enQueue(int queue[], int sizeOfQueue, int* first, int* rear, int val) {
    if(*rear >= sizeOfQueue - 1) {
        printf("Queue overflow \n");
        return;
    }
    
    queue[++(*rear)] = val;
    if(*first == -1) (*first)++;
}

int deQueue(int queue[], int sizeOfQueue, int* first, int* rear) {
    if (*first == -1) {
        printf("Queue underflow \n");
        return -1;
    }

    int val = queue[(*first)];
    if(*first == *rear) 
        *first = *rear = -1;
    else 
        (*first)++;

    return val;
}

void displayQueue(int queue[], int fisrt, int rear) {
    if(fisrt == -1) {
        printf("underflow \n");
        return;
    }
    for(int i=fisrt; i<=rear; i++) {
        printf("%d, ", queue[i]);
    }
    printf("\n");
}

int main() {
    int Queue[10];
    int sizeOfQueue = sizeof(Queue) / sizeof(int);
    int first, rear;
    first = rear = -1;

    int choose, value;
    do {
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Display \n");
        printf(" -1 --> Exit \n");

        printf("Enter your choose :");
        scanf("%d", &choose);

        switch(choose) {
            case 1:
                printf("Enter the number :");
                scanf("%d", &value);
                enQueue(Queue, sizeOfQueue, &first, &rear, value);
                    break;
            case 2:
                deQueue(Queue, sizeOfQueue, &first, &rear);
                    break;
            case 3:
                displayQueue(Queue, first, rear);
        }
    }while (choose != -1);
}
