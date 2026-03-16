// 48. Write a menu driven program to implement following operations on the 
// Doubled Ended Queue using an Array 
// • Insert at front end, Insert at rear end 
// • Delete from front end, Delete from rear end 
// • Display all elements of the queue 

#include <stdio.h>

void insertFront(int x, int *front, int *rear, int ary[], int size) {
    if((*front) == ((*rear) + 1) % size) {
        printf("Queue overflow \n");
        return;
    }

    if((*front) == -1) {
        *front = *rear = 0;
    }
    else  {
        (*front) = ((*front) - 1 + size) % size;
    }

    ary[(*front)] = x;
}

void insertRear(int x, int *front, int *rear, int ary[], int size) {
    if((*front) == ((*rear) + 1) % size) {
        printf("Queue overflow \n");
        return;
    }

    if((*front) == -1) 
        *front = *rear = 0;
    else 
        (*rear) = ((*rear) + 1) % size; 
    

    ary[(*rear)] = x;
}

int deleteFront(int *front, int *rear, int ary[], int size) {
    if((*front) == -1) {
        printf("Queure is Empty \n");
        return (*front);
    }

    int x;
    x = ary[(*front)];
    if((*front) == (*rear)) 
        (*front) = (*rear) = -1;
    else 
        (*front) = ((*front) + 1) % size;

    return x;
}

int deleteRear(int *front, int *rear, int ary[], int size) {
    if((*front) == -1) {
        printf("Queue is Empty \n");
        return (*front);
    }

    int x = ary[(*rear)];
    if((*front) == (*rear))
        (*front) = (*rear) = -1;
    else 
        (*rear) = ((*rear) - 1 + size) % size;

    return x;
}

void display(int ary[], int front, int rear, int size) {
    if(front == -1) {
        printf("Queue is Empty \n");
        return;
    }

    if(front == rear) 
        printf("%d ", ary[front]);
    else {
        while (front != rear) {
            printf("%d ", ary[front]);
            front = (front + 1) % size; 
        }
    }
}
