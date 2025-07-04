#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

void insertAtFirst(struct node **first, int x) {
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;

    if(*first == NULL) {
        newNode = *first;
        return;
    }

    
}


int main() {

    struct node *first = NULL;
    insertAtFirst(first, 10);

    return 0;
}