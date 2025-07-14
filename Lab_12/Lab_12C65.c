// 65. WAP to swap Kth node from beginning with Kth node from end in a singly linked 
// list. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node* createNode(int x) {
    struct node *newNode = (struct node*) malloc (sizeof(struct node));
    if(!newNode) return NULL;

    newNode->info = x;
    newNode->link = NULL;

    return newNode;
}

void insertAtLast(int x, struct node **first) {
    struct node *newNode = createNode(x);

    if(*first == NULL) {
        *first = newNode;
        return;
    }
    
    struct node *save;
    save = *first;
    while (save->link != NULL) {
        save = save->link;
    }
    save->link = newNode;

    printf("Node inserted at the end successfully.\n");
}

void display(struct node *first) {
    if(first == NULL) {
        printf("The Linked List is empty \n");
        return;
    }

    struct node *save;
    save = first;
    while (save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL \n");
}

void findnodes(struct node **save, struct node **pre, int k) {
    for(int i=1; i<k; i++) {
        *pre = *save;
        *save = (*save)->link;
    }
}

void kthSwapBothSideOfLinkedList(int k, struct node **first) {
    if(*first == NULL) {
        printf("linked list is Empty \n");
        return;
    }
    
    int count = 0;
    struct node *save = *first; 
    while (save != NULL) {
        count ++;
        save = save->link;
    }

    if (k <= 0 || k > count) {
        printf("Invalid k. Must be between 1 and %d.\n", count);
        return;
    }

    save = *first;
    struct node* save1 = *first, *pre1 = NULL;
    struct node* save2 = *first, *pre2 = NULL;

    // find first kth node and last kth node
    findnodes(&save1, &pre1, k);
    findnodes(&save2, &pre2, count-k+1);

    struct node *temp = save1->link;
    if (pre1 != NULL)
        pre1->link = save2;
    else
        *first = save2;

    save1->link = save2->link;
    save2->link = temp;
    
    if (pre2 != NULL)
        pre2->link = save1;
    else
        *first = save1;

    printf("Nodes swapped: position %d from start and end.\n", k);
}  

int main() {
    struct node *head = NULL;
    insertAtLast(10, &head);
    insertAtLast(20, &head);
    insertAtLast(30, &head);
    insertAtLast(40, &head);
    insertAtLast(50, &head);

    printf("Before swap:\n");
    display(head);

    kthSwapBothSideOfLinkedList(3, &head);

    printf("After swap:\n");
    display(head);
    return 0;
}