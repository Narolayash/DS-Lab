// 67. WAP to perform given operation in the linked list. There exist a Linked List. Add 
// a node that contains the GCD of that two nodes between every pair adjacent 
// node of Linked List. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

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

struct node *addGCD (struct node *first) {
    if(first == NULL) {
        printf("List is Empty \n");
        return first; 
    }

    struct node *save = first, *next = NULL;
    while (save->link != NULL) {
        next = save->link;
        struct node *newNode = (struct node*) malloc (sizeof(struct node));
        if(!newNode) return NULL;
        newNode->info = gcd(save->info, next->info);
        newNode->link = save->link;
        save->link = newNode;
        save = next;
    }

    return first;
} 


int main() {
    struct node *head = NULL;

    insertAtLast(18, &head);
    insertAtLast(24, &head);
    insertAtLast(36, &head);
    insertAtLast(60, &head);

    printf("Original List:\n");
    display(head);

    head = addGCD(head);

    printf("List After GCD Insertion:\n");
    display(head);

    return 0;
}