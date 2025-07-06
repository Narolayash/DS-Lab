// 66. Write a program to sort elements of a linked list.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};


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