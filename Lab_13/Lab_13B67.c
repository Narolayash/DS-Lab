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
    int sm, lg;
    if( a < b ) {
        sm = a;
        lg = b;
    }
    else {
        sm = b;
        lg = a;
    }

    while (1) {
        int rem = lg % sm;
        if(rem != 0) {
            lg = sm;
            sm = rem;
        }
        else {
            break;
        }
    }

    return sm;
}

struct node *addGCD (struct node *first) {
    if(first == NULL) {
        printf("List is Empty \n");
        return first; 
    }

    struct node *save = first, *next = NULL;
    while (save->link != NULL) {
        next = save->link;
        struct node *newNode = (struct node*) malloc (sizeof(struct node));
        newNode->info = gcd(save->info, next->info);
        newNode->link = save->link;
        save->link = newNode;
        save = next;
    }

    return first;
} 

void printList(struct node *first) {
    while (first != NULL) {
        printf("%d -> ", first->info);
        first = first->link;
    }
    printf("NULL\n");
}

struct node* insertAtLast(struct node* first, int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;

    if (first == NULL) {
        return newNode;
    }

    struct node* temp = first;
    while (temp->link != NULL) {
        temp = temp->link;
    }

    temp->link = newNode;
    return first;
}

int main() {
    struct node* first = NULL;

    // Create initial list: 12 → 15 → 21
    first = insertAtLast(first, 12);
    first = insertAtLast(first, 15);
    first = insertAtLast(first, 21);

    printf("Original List:\n");
    printList(first);

    first = addGCD(first);

    printf("List After GCD Insertions:\n");
    printList(first);

    return 0;

}