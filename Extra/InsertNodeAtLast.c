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

int main () {
    int n;
    do {
        printf("Enter the number :");
        scanf("%d", &n);

        if(n) {
            int x;
            printf("Enter the value to insert at the end : ");
            scanf("%d", &x);
            insertAtLast(x);
        }
        else {
            displayElements();
            break;
        }
    }
    while (n);

    return 0;
}