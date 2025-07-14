// 69. Write a menu driven program to implement following operations on the circular 
// linked list. 
// • Insert a node at the front of the linked list. 
// • Delete a node from specified position. 
// • Insert a node at the end of the linked list. 
// • Display all nodes.  

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

// create a New Node 
struct node* createANewNode(int x) {
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    if(!newNode) return NULL;

    newNode->info = x;
    newNode->link = NULL;

    return newNode;
}

// Insert a node at the front of the linked list. 
void insertAtFitstCircularList(int x, struct node **first, struct node **last) {
    struct node *newNode = createANewNode(x);

    if(*first == NULL) {
        newNode->link = newNode;
        *first = *last = newNode;
        return;
    }
    
    newNode->link = *first;
    (*last)->link = newNode;
    *first = newNode;
}

// Delete a node from specified position. 
void deleteAtFirstCircularList(int posi, struct node **first, struct node **last) { 
    if(*first == NULL) {
        printf("List Is Empty \n");
        return ;
    }

    struct node *save = *first;
    int count = 0;
    do {
        count++;
        save = save->link;
    }
    while (save != *last);

    if(posi <= 0 && posi > count) {
        printf("Out of the range \n");
        return;
    }

    save = *first;
    if(posi == 1) {
        if(*first == *last) {
            free(*first);
            *first = *last = NULL;
            return;
        }

        (*last)->link = (*first)->link;
        free(*first);
        *first = (*last)->link;
        return;
    }

    for(int i=2; i<posi; i++) {
        save = save->link;
    }

    struct node *temp = save->link;
    save->link = temp->link;
    if(temp == *last) {
        *last = save;
    }
    free(temp);

    printf("Node Deleted \n");
}

// Insert a node at the end of the circular linked list.
void insertAtLastCircularList(int x, struct node **first, struct node **last) {
    struct node *newNode = createANewNode(x);

    if(*first == NULL) {
        newNode->link = newNode;
        *first = *last = newNode;
        return;
    }

    newNode->link = *first;
    (*last)->link = newNode;
    *last = newNode;
}

// Display all nodes
void display(struct node *first, struct node *last) {
    if(first == NULL) {
        printf("List is Empty \n");
        return;
    }

    struct node *save = first;
    do {
        printf("%d -> ", save->info);
        save = save->link;
    }
    while (save != last);

    printf("... (circular)\n");
}

//  Insrert a node in order circular linked list
void insertAtOrderCircularList(int x, struct node **first, struct node **last) {
    struct node *newNode = createANewNode(x);

    if(newNode->info <= (*first)->info) {
        newNode->link = *first;
        (*last)->link = newNode;
        *first = newNode; 
        return;
    }

    struct node *save = *first;
    while(save != *last && newNode->info > save->link->info) {
        save = save->link;
    }

    newNode->link = save->link;
    save->link = newNode;

    if(save == *last) {
        *last = newNode;
    }
}

int main() {
    struct node *first = NULL, *last = NULL;
    int choice, value, pos;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Position\n");
        printf("4. Display All Nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertAtFitstCircularList(value, &first, &last);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtLastCircularList(value, &first, &last);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtFirstCircularList(pos, &first, &last);
                break;
            case 4:
                printf("Circular Linked List: ");
                display(first, last);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again!\n");
        }
    }

    return 0;
}