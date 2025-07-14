#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *lptr;
    struct node *rpte;
};

// create a new Node
struct node* createNode(int x) {
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    if(newNode == NULL) {
        printf("Memory allocation failed \n");
        return;
    }

    newNode->info = x;
    newNode->lptr = NULL;
    newNode->rpte = NULL;

    return newNode;
}

// task panding --->
// insertion, deletion, searching of a node and display of the list.
// concatenate two doubly linked list 
// print the node contents from fight to left
// insert a node at the specified position
// delete the node having value X 