// 62. WAP to remove duplicate elements from a singly linked list. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

struct node* removeDuplicate(struct node* first) {
    if(first == NULL) {
        printf("Linked list is empty \n");
        return NULL;
    }
    
    struct node* save = first; 
    while (save != NULL) {
        struct node* next = save;
        while(next->link != NULL) {
            if(save->info == next->link->info) {
                struct node* temp = next->link;
                next->link = temp->link;
                free(temp);
            }
            else {
                next = next->link;
            }
        }
        save = save->link;
    }

    return first;
}