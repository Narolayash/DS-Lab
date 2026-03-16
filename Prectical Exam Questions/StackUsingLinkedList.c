#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node* link;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc (sizeof(struct node));
    if(!newNode) {
        printf("Heap Overflow \n"); 
    }
    
    newNode->data = data;
    newNode->link = NULL;

    return newNode;
}

void push(struct node** top, int data) {
    struct node* newNode = createNode(data);

    newNode->link = *top;
    *top = newNode;
    printf("%d push to stack \n", data);
}

int pop(struct node** top) {
    if(*top == NULL) return -1;

    struct node* temp = *top;
    int data = temp->data;
    *top = temp->link;
    free(temp);

    return data;
}


