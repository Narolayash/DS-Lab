// 64. Write a program to reverse a linked list. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;

struct node* reverseLinkedList(struct node *first) {
    if(first == NULL) {
        printf("list is empty \n");
        return first;
    }

    struct node *save = first, *next = NULL, *pre = NULL;
    while (save != NULL) {
        next = save->link;
        save->link = pre;
        pre = save;
        save = next;
    }
    first = pre;

    return first;
}

int main() {

}