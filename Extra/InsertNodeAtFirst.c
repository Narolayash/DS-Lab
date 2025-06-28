// to insert a node at first location

#include <stdio.h>
#include <stdlib.h>

// node structure
struct node {
    int info;
    struct node *link;
};

// first is globle pointer which is point to the first element of list
struct node *first = NULL;

// insert at first position
void insertAtFirst(int x) {
    struct node *newNode = (struct node*) malloc (sizeof(struct node));

    newNode -> info = x;
    newNode -> link = first;

    first = newNode;
}


// display all the elements
void displayElements () {
    struct node *save = (struct node*) malloc (sizeof(struct node));

    save = first;

    while (save != NULL) {
        printf("%d ", save -> info);
        save = save -> link;
    }
    free(save);
}

int main() {
    while(1) {
        int i;
        printf("do you want to insert node at first position (if yes = 1 and no = 0) : ");
        scanf("%d", &i);

        if(i) {
            int x;
            printf("Enter value which one you want to insert at first position : ");
            scanf("%d", &x);
            insertAtFirst(x);
        }
        else {
            displayElements();
            break;
        }
    }

    return 0;
}