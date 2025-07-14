// 72. Write a menu driven program to implement following operations on the doubly 
// linked list. 
// • Insert a node at the front of the linked list. 
// • Delete a node from specified position. 
// • Insert a node at the end of the linked list. (Home Work) 
// • Display all nodes. (Home Work) 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *lptr;
    struct node *rptr;
};

// create a node for doubly liked list
struct node* createNode(int x) {
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    if(!newNode) return NULL;

    newNode->info = x;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    return newNode;
}

// Insert a node at the front of the linked list.
void insertANodeAtFirst(int x, struct node **first) {
    struct node *newNode = createNode(x);

    if(*first == NULL) {
        *first = newNode;
        return;
    }

    newNode->rptr = *first;
    (*first)->lptr = newNode;

    *first = newNode;
}

// Delete a node from specified position. 
void deleteNodeSpeciPosi(int posi, struct node **first) {
    if(*first == NULL) {
        printf("List is Empty");
        return;
    }

    int count;
    struct node *save = *first, *pre = NULL, *next = (*first)->rptr;
    for(count = 1; (save != NULL) && (count < posi); count++) {
        pre = save;
        next = next->rptr;
        save = save->rptr;
    }

    if(posi > count) {
        printf("Out of the range \n");
    }

    if(pre == NULL) {
        *first = save->rptr;
        (*first)->lptr = NULL;
        free(save);
        return;
    }

    pre->rptr = next;
    next->lptr = pre;
    free(save);
}

// Insert a node at the end of the linked list. (Home Work)
void insertANodeAtLast(int x, struct node **first) {
    struct node *newNode = createNode(x);

    if(*first == NULL) {
        *first = newNode;
        return;
    }

    struct node *save = *first;
    while(save->rptr != NULL) {
        save = save->rptr;
    }

    newNode->lptr = save;
    save->rptr = newNode;
}

// Display all nodes. (Home Work) 
void display(struct node *first) {
    if(first == NULL) {
        printf("List is Empty \n");
        return;
    }

    struct node *save = first;
    while(save != NULL) {
        printf("%d -> ", save->info);
        save = save->rptr;
    }

    printf("NULL");
}

int main() {
    struct node *first = NULL;
    int choice, value, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Specific Position\n");
        printf("4. Display All Nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertANodeAtFirst(value, &first);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertANodeAtLast(value, &first);
                break;

            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNodeSpeciPosi(position, &first);
                break;

            case 4:
                display(first);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 5);

    return 0;
}