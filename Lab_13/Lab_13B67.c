// 67. WAP to perform given operation in the linked list. There exist a Linked List. Add 
// a node that contains the GCD of that two nodes between every pair adjacent 
// node of Linked List. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

int gcd (int a, int b) {
    int ans=0;


    return ans;
}

struct node *addGCD (struct node *first) {
    if(first == NULL) {
        prinft("List is Empty \n");
        return first; 
    }

    struct node *save = first, *next = NULL;
    while (save->link != NULL) {
        next = save->link;
        struct node *newNode = (struct node*) malloc (sizeof(struct node));
        newNode->info = gcd(save->info, next->info);
    }
} 