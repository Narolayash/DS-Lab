// 57. Write a menu driven program to implement following operations on the singly 
// linked list. 

// • Insert a node at the front of the linked list. (done)
// • Display all nodes. (done)
// • Delete a first node of the linked list. (done)
// • Insert a node at the end of the linked list. (done)
// • Delete a last node of the linked list. 
// • Delete a node from specified position. 
// • count the number of nodes

#include <stdio.h>
#include <stdlib.h>

// define Node --- >
struct node {
    int info;
    struct node *link;
};

// first always pointer to first node
struct node *first = NULL;

// Insert a node at the front of the linked list (1)
void insertAtFirst() {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL) {
        printf("memory allocation failed ");
        return;
    }

    printf("Enter the value of new node which insert at the front of the linked list :");
    scanf("%d", &newNode->info);
    newNode->link = first;
    first = newNode;

    printf("Node inserted successfully at the beginning.\n");
}

// Display all nodes. (2)
void displayAllNodes() {
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
    printf("NUll \n");
}

// Delete a first node of the linked list (3)
void deleteAtFirst() {
    if(first == NULL) {
        printf("The Linked List is empty \n");
        return;
    }
    struct node *save;
    save = first;
    first = first->link;
    free(save);
    printf("First node deleted successfully.\n");
}

// Insert a node at the end of the linked list (4)
void insertAtLast() {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("memory allocation failed ");
        return;
    }
    
    printf("Enter the value of element which insert at last of the linked list :");
    scanf("%d", &newNode->info);
    
    if(first == NULL) {
        newNode->link = NULL;
        first = newNode;
        return;
    }
    
    struct node *save;
    save = first;
    while (save->link != NULL) {
        save = save->link;
    }
    save->link = newNode;
    newNode->link = NULL;

    printf("Node inserted at the end successfully.\n");
}

// Delete a last node of the linked list (5)
void deleteAtlast() {
    if(first == NULL) {
        printf("The Linked List is empty /n");
        return;
    }

    if(first->link == NULL) {
        free(first);
        first = NULL;
        printf("Last node deleted successfully \n");
        return;
    }

    struct node *save, *pre = NULL;
    save = first;
    while (save->link != NULL) {
        pre = save;
        save = save->link;
    }
    pre->link = NULL;
    free(save);
    printf("Last node deleted successfully \n");
}

// Delete a node from specified position (6)

// count the number of nodes (7)
void countAllNodes() {
    if (first == NULL) {
        printf("The linked list is empty. Total nodes: 0\n");
        return;
    }

    int count = 0;
    struct node *save;
    save = first;
    while (save != NULL) {
        count++;
        save = save->link;
    }

    printf("Total number of node : %d", count);
}

int main() {
    int number;
    do {
        printf("\nNumber 1 : Insert a node at the front of the linked list \n");
        printf("Number 2 : Display all nodes \n");
        printf("Number 3 : Delete a first node of the linked list \n");
        printf("Numbwer 4 : Insert a node at the end of the linked list \n");
        printf("Numbwer 5 : Delete a last node of the linked list \n");
        printf("Numbwer 6 : Delete a node from specified position \n");
        printf("Numbwer 7 : count the number of nodes \n");

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

        case 5: deleteAtlast();
            break;

        case 6: insertAtLast();
            break;

        case 7: countAllNodes();
            break;

        case 0: printf("Exit\n");
            break;
        
        default: printf("Invalid Input");
            break;
        }
    }
    while (number != 0);
}