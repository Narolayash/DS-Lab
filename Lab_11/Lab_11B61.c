// 61. Write a program to implement queue using singly linked list. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

int enqueue(struct node** first, struct node** last, int x) {
    struct node* newNode = (struct node*) malloc (sizeof(struct node));
    if(!newNode) return -1;

    newNode->info = x;
    newNode->link = NULL;

    if(*first == NULL) {
        *first = newNode;
        *last = newNode;
        return 1;
    }
    
    (*last)->link = newNode;
    *last = newNode;
    return 1;
}

int dequeue(struct node** first, struct node** last) {
    if(*first == NULL) {
        printf("Queue underflow \n");
        return -1;
    }

    struct node* temp = *first;
    int info = temp->info;

    if(*first == *last) {
        *first = NULL;
        *last = NULL;
    }
    else {
        *first = temp->link;
    }
    free(temp);
    return info;
}