// 65. WAP to swap Kth node from beginning with Kth node from end in a singly linked 
// list. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;

void kthSwapBothSideOfListedList(struct node *fisrt) {
    if(fisrt == NULL) {
        printf("List is Empty \n");
        return first;
    }
    
    int k, count = 0;
    printf("Enter k : for swap kth elemente from beginning with kth node from end : ");
    scanf("%d", &k);
    
    struct node *save = fisrt; 
    while (save != NULL) {
        count ++;
        save = save->link;
    }

    struct node *save = first, *pre = NULL, *tempSave = NULL, *tempPre = NULL;

    for(int i=1; i<count-(k-1); i++) {
        if(i == k) {
            tempSave = save;
            tempPre = save;
        }
        pre = save;
        save = save->link;
    }
} 