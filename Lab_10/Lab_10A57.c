// 57. Write a menu driven program to implement following operations on the singly 
// linked list. 

// • Insert a node at the front of the linked list. 
// • Display all nodes. 
// • Delete a first node of the linked list. 
// • Insert a node at the end of the linked list. 
// • Delete a last node of the linked list. 
// • Delete a node from specified position. 
// • count the number of nodes

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;

// Insert a node at the front of the linked list (1)
void insertAtFirst() {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter the value of new node which insert at the front of the linked list :");
    scanf("%d", &newNode->info);
    newNode->link = first;
    first = newNode;

    free(newNode);
}

// Display all nodes. (2)
void displayAllNodes() {
    struct node *save = (struct node*)malloc(sizeof(struct node));

    save = first;
    while (save != NULL) {
        printf("%d\n", save->info);
        save = save->link;
    }

    free(save);
}

// Delete a first node of the linked list (3)
void deleteAtFirst() {
    struct node *save = (struct node*) malloc(sizeof(struct node));
    
    save = first;
    first = first->link;

    free(save);
}

// Insert a node at the end of the linked list (4)
void insertAtLast() {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *save = (struct node*) malloc(sizeof(struct node));

    printf("Enter the value of element which insert at last of the linked list :");
    scanf("%d", &newNode->info);

    save = first;
    while (save->link != NULL) {
        save = save->link;
    }

    save->link = newNode;
    newNode->link = NULL;
}
int main() {
    int number;
    do {
        printf("\nNumber 1 : Insert a node at the front of the linked list \n");
        printf("Number 2 : Display all nodes\n");
        printf("Number 3 : Delete a first node of the linked list\n");
        printf("Numbwer 4 : Insert a node at the end of the linked list\n");

        printf("Enter the Number : ");
        scanf("%d", &number);

        switch (number)
        {
        case 1: insertAtFirst();
            break;

        case 2: displayAllNodes();
            break;
        
        case 3: deleteAtFirst();
            break;

        case 4: insertAtLast();
            break;

        case 0: printf("Exit\n");
            break;
        
        default: printf("Invalid Input");
            break;
        }
    }
    while (number != 0);
}