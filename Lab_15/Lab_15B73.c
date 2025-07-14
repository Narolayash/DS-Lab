// 73. WAP to delete alternate nodes of a doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node* createNode(int x) {
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    if(!newNode) return NULL;

    newNode->info = x;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    return newNode;
}

void insertANodeAtLast(int x, struct node **first) {
    struct node *newNode = createNode(x);

    if(*first == NULL) {
        *first = newNode;
        return;
    }

    struct node *save = *first;
    while(save->rptr != NULL) {
        save = save->rptr;
    }

    newNode->lptr = save;
    save->rptr = newNode;
}

void display(struct node *first) {
    if(first == NULL) {
        printf("List is Empty \n");
        return;
    }

    struct node *save = first;
    while(save != NULL) {
        printf("%d -> ", save->info);
        save = save->rptr;
    }

    printf("NULL");
}

void deleteAlternateNode(struct node **first) {
    if(*first == NULL) return;

    int x;
    printf("Enter 1 for odd nodes \n");
    printf("Enter 2 for even nodes \n");
    scanf("%d", &x);

    struct node *save = *first, *pre = NULL, *next = NULL, *temp;
    int posi = 1;

    while (save != NULL ){
        if((x == 1 && posi % 2 != 0) || (x == 2 && posi % 2 == 0)) {
            temp = save;
            
            if(save->lptr != NULL) {
                save->lptr->rptr = save->rptr;
            }
            else {
                *first = save->rptr;
            }
            if(save->rptr != NULL) {
                save->rptr->lptr = save->lptr;
            }
            save = save->rptr;
            free(temp);
        }
        else {
            save = save->rptr;
        }
        posi++;
    }
        
}