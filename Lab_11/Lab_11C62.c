// 62. WAP to remove duplicate elements from a singly linked list. 

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

void removeDuplicate(struct node **first) {
    if(*first == NULL) {
        printf("Linked list is empty \n");
        return ;
    }
    
    struct node* save = *first; 
    while (save != NULL) {
        struct node* next = save;
        while(next->link != NULL) {
            if(save->info == next->link->info) {
                struct node* temp = next->link;
                next->link = temp->link;
                free(temp);
            }
            else {
                next = next->link;
            }
        }
        save = save->link;
    }

    printf("Duplicates removed successfully.\n");
}

int main() {
    struct node *first = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Remove Duplicates\n");
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
                display(first);
                break;

            case 3:
                removeDuplicate(&first);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
