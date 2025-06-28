#include <stdio.h>
#include <stdlib.h>

// node structure
struct node {
    int info;
    struct node *link;
};

// pointer for first node
struct node *first = NULL;
struct node *newFirst = NULL;

// insert at first position
void insertAtFirst() {
    struct node *newNode = (struct node*) malloc (sizeof( struct node  ));

    printf("Enter the value which is you want to insert at first position of linked list : ");
    scanf("%d", &newNode->info);

    newNode -> link = first;

    first = newNode;
}


void insertAtLast () {
    struct node *newNode = (struct node*) malloc (sizeof(struct node));
    printf("Enter the value which is you want to insert at last position of linked list : ");
    scanf("%d", &newNode->info);
    newNode -> link = NULL;

    if(first == NULL) {
        first = newNode;
        return;
    }
    
    struct node *save;
    save = first;

    while (save -> link != NULL) {
        save = save->link;
    }

    save -> link = newNode;
}

void copyList () {
    if (first == NULL) {
        return;
    }
    else {
        struct node *save;
        save = first;
        struct node *temp = NULL;
        
        while (save != NULL) {
            struct node *newNode = (struct node*) malloc (sizeof(struct node));
            newNode->info = save->info;
            newNode->link = NULL;
            if(newFirst == NULL) {
                newFirst = newNode;
                temp = newFirst;
            }
            else {
                temp->link = newNode;
                temp = newNode;
            }
            save = save -> link;
        }
    }
}

int main() {

}