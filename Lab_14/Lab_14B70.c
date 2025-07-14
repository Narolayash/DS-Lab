// 70. WAP to split a circular linked list into two halves. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node* createANewNode(int x) {
    struct node *newNode = (struct node *) malloc (sizeof(struct node)); 
    if(!newNode) return NULL;

    newNode->info = x;
    newNode->link = NULL;

    return newNode;
}

void insertAtLastCircularList(int x, struct node **first, struct node **last) {
    struct node *newNode = createANewNode(x);

    if(*first == NULL) {
        newNode->link = newNode;
        *first = *last = newNode; 
        return;
    }

    newNode->link = *first;
    (*last)->link = newNode;
    *last = newNode;
}

void splitACircularLinkedList(struct node *first, struct node **first1, struct node **first2) {
    if(first == NULL || first->link == first ) {
        return;
    }

    struct node *save1 = first, *save2 = first;
    while (save1->link != first && save1->link->link != first) {
        save1 = save1->link->link;
        save2 = save2->link;
    }

    *first1 = first;
    *first2 = save2->link;    
    save2->link = *first1;

    struct node *temp = *first2;
    while(temp->link != first) {
        temp = temp->link;
    }
    temp->link = *first2;
}

void display(struct node *first) {
    if(first == NULL) {
        printf("List is Empty \n");
        return;
    }

    struct node *save = first;
    do {
        printf("%d -> ", save->info);
        save = save->link;
    }
    while (save != first);

    printf("... (circular)\n");
}

int main() {
    struct node *first = NULL, *last = NULL;
    insertAtLastCircularList(10, &first, &last);
    insertAtLastCircularList(20, &first, &last);
    insertAtLastCircularList(30, &first, &last);
    insertAtLastCircularList(40, &first, &last);
    insertAtLastCircularList(50, &first, &last);

    struct node *first1 = NULL, *first2 = NULL;
    splitACircularLinkedList(first, &first1, &first2);

    printf("First half:\n");
    display(first1);
    
    printf("Second half:\n");
    display(first2);

    return 0;
}