#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first1 = NULL;
struct node *first2 = NULL;

void insertAtLast (int x) {
    struct node *newNode = (struct node*) malloc (sizeof(struct node));
    newNode -> info = x;
    newNode -> link = NULL;

    if(first1 == NULL) {
        first1 = newNode;
        return;
    }
    
    struct node *save;
    save = first1;

    while (save -> link != NULL) {
        save = save->link;
    }

    save -> link = newNode;
}

void displayElements () {

    printf("Display : \n");
    struct node *save;

    save = first1;

    while (save != NULL) {
        printf("%d ", save -> info);
        save = save -> link;
    }
}

void copyList () {
    if (first1 == NULL) {
        return;
    }
    else {
        struct node *save;
        save = first1;
        struct node *temp = NULL;
        
        while (save != NULL) {
            struct node *newNode = (struct node*) malloc (sizeof(struct node));
            newNode->info = save->info;
            newNode->link = NULL;

            if(first2 == NULL) {
                first2 = newNode;
                temp = first2;
            }
            else {
                temp->link = newNode;
                temp = newNode;
            }
            
            save = save -> link;
        }
    }
}

void displayElements1 () {
    printf("Display-1 : \n");

    struct node *save;

    save = first2;

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
            printf("Enter the value which insert at last : ");
            scanf("%d", &x);
            insertAtLast(x);
        }
        else {
            copyList();
            displayElements();
            printf("\n");
            displayElements1();
            break;
        }
    }
    while (n);

    return 0;
}