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

struct node *first = NULL;

void swapTwoConsecutiveNode() {
    if(first == NULL) {
        printf("First is null");
        return;
    }

    struct node *pre, *save, *temp = NULL;
    pre = first;
    save = first->link;

    while (save != NULL) {
        if(pre == first) {
            temp = pre;
            pre->link = save;
            save->link = temp;
        }
        else {
            
        }
    }
}