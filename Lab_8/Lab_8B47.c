// 47. Write a menu driven program to implement following operations on a circular 
// queue using an Array 
// • Insert 
// • Delete 
// • Display all elements of the queue

#include <stdio.h>

void enQueueCircular(int queue[], int size, int* first, int* rear, int val) {
    if((*first) == ((*rear) + 1) % size) {
        printf("Queue overflow \n");
        return;
    }

    if((*first) == -1) 
        (*first) = (*rear) = 0;
    else 
        (*rear) = ((*rear) + 1) % size;

    queue[(*rear)] = val;
}

int deQueueCircular(int queue[], int size, int* first, int* rear) {
    if((*first) == -1) {
        printf("Queue underflow \n");
        return -1;
    }

    int val = queue[(*first)];
    if((*first) == (*rear)) 
        (*first) = (*rear) = -1;
    else 
        (*first) = ((*first) + 1) % size;

    return val;
}

void display(int queue[], int size, int first, int rear) {
    if(first == -1) {
        printf("Queue is empty \n");
        return;
    }

    printf("Queue elements : ");
    int i = first;
    while (1) {
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter size of circular queue: ");
    scanf("%d", &size);

    int queue[size];
    int first = -1, rear = -1;
    int choice, val;

    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                enQueueCircular(queue, size, &first, &rear, val);
                break;
            case 2:
                val = deQueueCircular(queue, size, &first, &rear);
                if(val != -1)
                    printf("Deleted: %d\n", val);
                break;
            case 3:
                display(queue, size, first, rear);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 4);

    return 0;
}
