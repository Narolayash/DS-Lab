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

// create a new node function
struct node* createNode(int x) {
    struct node *newNode = (struct node*) malloc (sizeof(struct node));
    if(!newNode) return NULL;

    newNode->info = x;
    newNode->link = NULL;

    return newNode;
}

// Insert a node at the front of the linked list (1)
void insertAtFirst(int x, struct node **first) {
    struct node *newNode = createNode(x);

    newNode->link = *first;
    *first = newNode;

    printf("Node inserted successfully at the beginning.\n");
}

// Display all nodes. (2)
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

// Delete a first node of the linked list (3)
void deleteAtFirst(struct node **first) {
    if(*first == NULL) {
        printf("The Linked List is empty \n");
        return;
    }

    struct node *save;
    save = *first;
    *first = (*first)->link;
    free(save);

    printf("First node deleted successfully.\n");
}

// Insert a node at the end of the linked list (4)
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

// Delete a last node of the linked list (5)
void deleteAtlast(struct node **first) {
    if(*first == NULL) {
        printf("The Linked List is empty \n");
        return;
    }

    if((*first)->link == NULL) {
        free(*first);
        *first = NULL;
        printf("Last node deleted successfully \n");
        return;
    }

    struct node *save, *pre = NULL;
    save = *first;
    while (save->link != NULL) {
        pre = save;
        save = save->link;
    }
    pre->link = NULL;
    free(save);

    printf("Last node deleted successfully \n");
}

// Delete a node from specified position (6)
void deleteAtSpecifiedPosition(int posi, struct node **first) {
    if(*first == NULL) {
        printf("List is empty \n");
        return;
    }

    if (posi <= 0) {
        printf("Invalid position. Must be >= 1.\n");
        return;
    }

    struct node *save = *first;
    if(posi == 1) {
        *first = (*first)->link;
        free(save);
        printf("Node at position 1 deleted.\n");
        return;
    }

    struct node *pre = NULL;
    for(int i=1; (i<posi && save != NULL); i++) {
        pre = save;
        save = save->link;
    }

    if (save == NULL) {
        printf("Position out of range.\n");
        return;
    }

    pre->link = save->link;
    printf("Node at position %d deleted.\n", posi);
    free(save);
}


// count the number of nodes (7)
void countAllNodes(struct node *first) {
    if (first == NULL) {
        printf("The linked list is empty. Total nodes: 0\n");
        return;
    }

    int count = 0;
    struct node *save = first;
    while (save != NULL) {
        count++;
        save = save->link;
    }

    printf("Total number of node : %d\n", count);
}

int main() {
    struct node *first = NULL;
    int choice, value, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Delete from specified position\n");
        printf("6. Display all nodes\n");
        printf("7. Count nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtFirst(value, &first);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtLast(value, &first);
                break;

            case 3:
                deleteAtFirst(&first);
                break;

            case 4:
                deleteAtlast(&first);
                break;

            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtSpecifiedPosition(position, &first);
                break;

            case 6:
                displayAllNodes(first);
                break;

            case 7:
                countAllNodes(first);
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 8);
    return 0;
}