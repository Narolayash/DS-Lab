// 65. WAP to swap Kth node from beginning with Kth node from end in a singly linked 
// list. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

void kthSwapBothSideOfLinkedList(struct node *first) {
    if(first == NULL) {
        printf("List is Empty \n");
        return;
    }
    
    int k, count = 0;
    printf("Enter k : for swap kth element from beginning with kth node from end : ");
    scanf("%d", &k);
    
    struct node *save = first; 
    while (save != NULL) {
        count ++;
        save = save->link;
    }

    if (k <= 0 || k > count) {
        printf("Invalid k. Must be between 1 and %d.\n", count);
        return;
    }

    save = first;
    struct node* temp1 = NULL;
    struct node* temp2 = NULL;
    for(int i=1; i<=count ; i++) {
        if(i == k) {
            temp1 = save;
        }
        if(i == (count-k+1)) {
            temp2 = save;
        }
        save = save->link;
    }

    int temp = temp1->info;
    temp1->info = temp2->info;
    temp2->info = temp;

    printf("Nodes swapped: position %d from start and end.\n", k);
} 