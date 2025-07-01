#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;

// insert at first position of linked list (1.)
struct node* insertAtFirstPosition(struct node *first){
    struct node *newNode = (struct node*) malloc (sizeof(struct node));
    if(newNode == NULL) {
        printf("Memory allocation failed \n");
        return first;
    }

    printf("Enter the value to insert at the first position of the linked list : ");
    scanf("%d", &newNode->info);

    newNode->link = first;
    first = newNode;

    printf("Insert at first position successful \n");
    return first;
}


// insert at last position of linked list (2.)
struct node* insertAtLastPosition(struct node *first) {
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    if(newNode == NULL) {
        printf("Memory allocation failed \n");
        return first;
    }

    printf("Enter the value to insert at the last position of the linked list : ");
    scanf("%d", &newNode->info);
    newNode->link = NULL;

    if(first == NULL) {
        first = newNode;
        return first;
    }

    struct node *save = first;
    while (save->link != NULL) {
        save = save->link;
    }
    save->link = newNode;

    printf("Insert at last position successful \n");
    return first;
}


// --- > Merge Two Sorted Lists
//  You are given the heads of two sorted linked lists list1 and list2.
//  Merge the two lists in a one-sorted list. The list should be made by
//  splicing together the nodes of the first two lists
struct node* mergeTwoSortedLists(struct node *list1, struct node *list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    struct node *save1 = list1;
    struct node *save2 = list2;
    struct node *newfirst = NULL, *newSave = NULL;

    if(newfirst == NULL) {
        if(list1->info < list2->info) {
            newfirst = list1;
            save1 = save1->link;
        }
        else {
            newfirst = list2;
            save2 = save2->link;
        }
    }

    newSave = newfirst;

    while(save1 != NULL && save2 !=NULL) {
        if(save1->info < save2->info) {
            newSave->link = save1;
            save1 = save1->link;
        }
        else {
            newSave->link = save2;
            save2 = save2->link;
        }
        newSave = newSave->link;
    }

    if(save1 == NULL) {
        newSave->link = save2;
    }
    else {
        newSave->link = save1;
    }

    printf("Merge two sorted list successful \n");
    return newfirst;
}


// any info count how many times info appear in list
void anyInfoCount(struct node *first) {
    if(first == NULL) {
        printf("List is empty \n");
        return;
    }

    struct node *save = first, *next = NULL, *pre = NULL;

    while (save != NULL) {
        int count = 1;
        next = save->link;
        pre = save;
        while (next != NULL) {
            if(save->info == next->info) {
                struct node *temp = next;
                pre->link = next->link;
                next = next->link;
                free(temp);
                count++;
            }else {
                pre = next;
                next = next->link;
            }
        }
        printf("%d number -> %d times \n", save->info, count);
        save = save->link;
    }
}


// create two linklist (1. which contains Odd Numbers ) & (2. which contains Even number )
struct node *oddHead = NULL, *evenHead = NULL;
void OddEvenNumver(struct node *first) {
    if(first == NULL) {
        printf("List is NULL \n");
        return;
    }

    struct node *save = first,*oddSave = NULL, *evenSave = NULL;

    while(save != NULL) {
        if(save->info % 2 != 0) {
            //odd
            struct node *newNode = (struct node*) malloc (sizeof(struct node));
            newNode->info = save->info;
            newNode->link = NULL;

            if(oddHead == NULL) {
                oddHead = newNode;
                oddSave = oddHead;
            }
            else {
                oddSave->link = newNode;
                oddSave = newNode;
            }
        } else {
            //even
            struct node *newNode = (struct node*) malloc (sizeof(struct node));
            newNode->info = save->info;
            newNode->link = NULL;

            if(evenHead == NULL) {
                evenHead = newNode;
                evenSave = evenHead;
            }
            else {
                evenSave->link = newNode;
                evenSave = newNode;
            }
        }
        save = save->link;
    }
}