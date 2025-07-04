// 59. Write a program to remove the duplicates nodes from given sorted Linked List. 
// • Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27 
// • Output: 1 → 6 → 13 → 27 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;

void insertAtLast (int x) {
    struct node *newNode = (struct node*) malloc (sizeof(struct node));
    newNode -> info = x;
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

void displayElements () {
    struct node *save;
    save = first;
    while (save != NULL) {
        printf("%d ", save -> info);
        save = save -> link;
    }
}

void removeDuplicate() {
    if (first == NULL) {
        printf("List is empty \n");
        return;
    }

    struct node *save = first, *temp;

    while (save != NULL  && save->link != NULL) {
        if(save->info == save->link->info) {
            temp = save->link;
            save->link = temp->link;
            free(temp);
        }
        else {
            save = save->link;
        }
    } 
}

int main () {
    int n;
    do {
        printf("Enter the number :");
        scanf("%d", &n);

        if(n == 1) {
            int x;
            printf("Enter the value to insert at the end : ");
            scanf("%d", &x);
            insertAtLast(x);
        }
        else if(n == 2) {
            removeDuplicate();
            printf("Remove all duplicates \n");
        }
        else {
            displayElements();
            break;
        }
    }
    while (n != 0);

    return 0;
}