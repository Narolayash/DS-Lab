// 68. Write a program to swap two consecutive nodes in the linked list. Don’t change 
// the values of nodes,  changing the link of thimplement bye nodes. 
// • Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 
// • Output: 2 → 1 → 4 → 3 → 6 → 5 → 8 → 7 

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

void swapTwoConsecutiveNode(struct node **first) {
    if(*first == NULL || (*first)->link == NULL) {
        printf("Not enough elements are available\n");
        return;
    }

    struct node *save1 = *first, *save2 = NULL,*next = NULL, *pre = NULL;
    *first = save1->link;
    while (save1 != NULL && save1->link != NULL) {
        save2 = save1->link;
        next = save2->link;

        save1->link = next;
        save2->link = save1;
        
        if(pre != NULL) {
            pre->link = save2;
        }

        pre = save1;
        save1 = next;
    }
}

int main() {
    struct node *head = NULL;

    // Create input list: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
    for(int i = 1; i <= 8; i++) {
        insertAtLast(i, &head);
    }

    printf("Original List:\n");
    display(head);

    swapTwoConsecutiveNode(&head);

    printf("List After Swapping Consecutive Nodes:\n");
    display(head);

    return 0;
}