#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

// Check if full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Insert at front
void insertFront(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + SIZE) % SIZE;
    }
    deque[front] = x;
}

// Insert at rear
void insertRear(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    deque[rear] = x;
}

// Delete front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Delete rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + SIZE) % SIZE;
    }
}

// Get front element
int getFront() {
    if (isEmpty()) return -1;
    return deque[front];
}

// Get rear element
int getRear() {
    if (isEmpty()) return -1;
    return deque[rear];
}

// Display deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    printf("Deque elements: ");
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertRear(30);
    display();

    deleteFront();
    display();

    deleteRear();
    display();

    return 0;
}
