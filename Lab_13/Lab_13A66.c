// 66. Write a program to sort elements of a linked list.
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

// check karva nu baki chhe ke aa funciton kamm kre chhe ke nay
struct node *sortEleOfLinkedList(struct node *first) {
    if(first == NULL) {
        printf("List is empty \n");
        return NULL;
    }

    for(struct node *i = first; i->link != NULL; i = i->link){
        for(struct node *j = i->link; j != NULL; j = j->link) {
            if(i->info > j->info) {
                int temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }

    return first;
}

int main() {
    struct node *head = NULL;
    insertAtLast(40, &head);
    insertAtLast(10, &head);
    insertAtLast(30, &head);
    insertAtLast(20, &head);
    insertAtLast(50, &head);

    printf("Before sorting:\n");
    display(head);

    head = sortEleOfLinkedList(head);

    printf("After sorting:\n");
    display(head);

    return 0;
}