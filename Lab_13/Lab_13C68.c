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

struct node* swapTwoConsecutiveNode(struct node *first) {
    if(first == NULL || first->link == NULL) {
        printf("Not enough elements are available\n");
        return first;
    }

    struct node *save1 = first, *save2 = NULL,*next = NULL, *pre = NULL;
    first = save1->link;
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

    return first;
}