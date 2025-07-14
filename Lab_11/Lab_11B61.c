// 61. Write a program to implement queue using singly linked list. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

struct node* createNode(int x) {
    struct node *newNode = (struct node*) malloc (sizeof(struct node));
    if(!newNode) return NULL;

    newNode->info = x;
    newNode->link = NULL;

    return newNode;
}

int enqueue(int x, struct node** first, struct node** last) {
    struct node* newNode = createNode(x);

    if(*first == NULL) {
        *first = newNode;
        *last = newNode;
        return 1;
    }
    
    (*last)->link = newNode;
    *last = newNode;
    return 1;
}

int dequeue(struct node** first, struct node** last) {
    if(*first == NULL) {
        printf("Queue underflow \n");
        return -1;
    }

    struct node* temp = *first;
    int info = temp->info;

    if(*first == *last) {
        *first = NULL;
        *last = NULL;
    }
    else {
        *first = temp->link;
    }
    free(temp);
    return info;
}

void displayQueue(struct node *first) {
    if(first == NULL) {
        printf("Stack is empty \n");
        return;
    }

    printf("Stack Element --- \n ");
    struct node *save = first;
    while(save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }

    printf("NULL \n ");
}

int main() {
    struct node *first = NULL, *last = NULL;
    int choice, value;

    do {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value, &first, &last);
                printf("%d added to queue.\n", value);
                break;

            case 2:
                value = dequeue(&first, &last);
                if(value == -1)
                    printf("Queue is empty. Nothing to dequeue.\n");
                else
                    printf("Dequeued value: %d\n", value);
                break;

            case 3:
                displayQueue(first);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 0);

    return 0;
}