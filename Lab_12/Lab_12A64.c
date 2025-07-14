// 64. Write a program to reverse a linked list. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node* createNode(int x) {
    struct node *newNode = (struct node*) malloc (sizeof(struct node));
    if(!newNode) return NULL;

    newNode->info = x;
    newNode->link = NULL;

    return newNode;
}

void insertAtLast(int x, struct node **first) {
    struct node *newNode = createNode(x);

    if(*first == NULL) {
        *first = newNode;
        return;
    }
    
    struct node *save;
    save = *first;
    while (save->link != NULL) {
        save = save->link;
    }
    save->link = newNode;

    printf("Node inserted at the end successfully.\n");
}

void display(struct node *first) {
    if(first == NULL) {
        printf("The Linked List is empty \n");
        return;
    }

    struct node *save;
    save = first;
    while (save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL \n");
}

struct node* reverseLinkedList(struct node *first) {
    if(first == NULL) {
        printf("list is empty \n");
        return first;
    }

    struct node *save = first, *next = NULL, *pre = NULL;
    while (save != NULL) {
        next = save->link;
        save->link = pre;
        pre = save;
        save = next;
    }
    first = pre;

    return first;
}

int main() {
    struct node *first = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert value\n");
        printf("2. Display list\n");
        printf("3. Reverse list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtLast(value, &first);
                break;

            case 2:
                printf("Current list: ");
                display(first);
                break;

            case 3:
                first = reverseLinkedList(first);
                printf("List reversed successfully.\n");
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
