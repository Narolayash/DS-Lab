// 63. Write a program to copy a linked list.

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

void copyLinkList(struct node *first, struct node **newFirst) {

    if(first == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct node *save1 = first;
    struct node *save2 = NULL;

    while (save1 != NULL) {
        struct node *newNode = createNode(save1->info);
        if(*newFirst == NULL) {
            *newFirst = newNode;
            save2 = newNode;
        }
        else {
            save2->link = newNode;
            save2 = save2->link;
        }
        save1 = save1->link;
    }
}

void displayAllNodes(struct node *first) {
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

int main() {
    struct node *original = NULL;
    struct node *copy = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert into original list\n");
        printf("2. Display original list\n");
        printf("3. Copy original list\n");
        printf("4. Display copied list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtLast(value, &original);
                break;

            case 2:
                printf("Original Linked List:\n");
                displayAllNodes(original);
                break;

            case 3:
                copyLinkList(original, &copy);
                printf("Copied Linked List successfully.\n");
                break;

            case 4:
                printf("Copied Linked List:\n");
                displayAllNodes(copy);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 0);

    return 0;
}