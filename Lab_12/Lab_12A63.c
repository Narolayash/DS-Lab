// 63. Write a program to copy a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first1 = NULL;
struct node *first2 = NULL;

void copyLinkList() {

    if(first1 == NULL) {
        printf("Linklist is empty");
        return;
    }

    struct node *save1 = first1;
    struct node *save2 = NULL;

    while (save1 != NULL) {
        struct node *newNode = (struct node *) malloc (sizeof(struct node));
        if(newNode == NULL) {
            printf("memory allocation failed \n");
            return;
        }
        newNode->info = save1->info;
        newNode->link = NULL;
        if(first2 == NULL) {
            first2 = newNode;
            save2 = newNode;
        }
        else {
            save2->link = newNode;
            save2 = save2->link;
        }
        save1 = save1->link;
    }
}

void displayLinkList(struct node* temp) {
    if(temp == NULL) {
        printf("LinkList is Empty \n");
        return ;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("Null \n");
}

struct node* insertAtLast(struct node* temp) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("memory allocation failed ");
        return temp;
    }
    
    printf("Enter the value of element which insert at last of the linked list :");
    scanf("%d", &newNode->info);
    newNode->link = NULL;
    
    if(temp == NULL) {
        temp = newNode;
        return temp;
    }
    
    struct node *save;
    save = temp;
    while (save->link != NULL) {
        save = save->link;
    }
    save->link = newNode;

    printf("Node inserted at the end successfully.\n");
    return temp;
}

int main() {
    int n;
    do{ 
        printf("Enter 1: insert value \n");
        printf("Enter 2: display linklist \n");
        printf("Enter 3: CopyList \n");
        printf("Enter 4: display copy linklist \n");
        printf("Enter 0: Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &n);


        switch(n) {
            case 1: first1 = insertAtLast(first1);
                break;
            case 2: displayLinkList(first1);
                break;
            case 3: copyLinkList();
                break;
            case 4: displayLinkList(first2);
                break;
            case 0: printf("Exit --- ");
                break;
            default: printf("Invalid Input\n");
        }
    }while (n != 0);

    return 0;
}