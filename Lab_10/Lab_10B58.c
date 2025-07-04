// 58. WAP to check whether 2 singly linked lists are same or not.

#include<stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *first1 = NULL;
struct node *first2 = NULL;

void compairTwoLinklist() {
    if(first1 == NULL && first2 == NULL) {
        printf("Both linklist is null, so they are same \n");
        return;
    }
    if(first1 == NULL) {
        printf("first linklist is null \n");
        return;
    }
    if(first2 == NULL) {
        printf("second linklist is null \n");
        return;
    }

    int flag = 1;
    while (first1 != NULL && first2 != NULL){
        if(first1->info != first2->info){
            flag = 0;
            break;
        }
        first1 = first1->link;
        first2 = first2->link;
    }

    if(first1 != NULL || first2 != NULL) {
        flag = 0;
    }

    if(flag) {
        printf("LinkLIst are same \n");
    }
    else {
        printf("LinkList are not same \n");
    }
} 

void displayAllNodesForFirst() {
    struct node *save ;

    save = first1;
    while (save != NULL) {
        printf("%d\n", save->info);
        save = save->link;
    }
}

void displayAllNodesForSecond() {
    struct node *save ;

    save = first2;
    while (save != NULL) {
        printf("%d\n", save->info);
        save = save->link;
    }

}

void insertAtLastInFirst() {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    struct node *save ;

    printf("Enter the value of element which insert at last of the linked list :");
    scanf("%d", &newNode->info);

    if(first1 == NULL) {
        newNode->link = NULL;
        first1 = newNode;
        return;
    }

    save = first1;
    while (save->link != NULL) {
        save = save->link;
    }

    save->link = newNode;
    newNode->link = NULL;

}

void insertAtLastInSecond() {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    struct node *save ;

    printf("Enter the value of element which insert at last of the linked list :");
    scanf("%d", &newNode->info);

    if(first2 == NULL) {
        newNode->link = NULL;
        first2 = newNode;
        return;
    }

    save = first2;
    while (save->link != NULL) {
        save = save->link;
    }

    save->link = newNode;
    newNode->link = NULL;

}

int main () {
        int n;
    do {
        printf(" 1: Insert the value at last position of first linklist \n");
        printf(" 2: Insert the value at last position of second linklist \n");
        printf(" 3: Display first linklist \n");
        printf(" 4: Display second linklist \n");
        printf(" 5: Compair first and second linklist \n");
        printf(" 0: Exit \n");
        scanf("%d", &n);

        switch (n) {
            case 1: insertAtLastInFirst();
                break;
            case 2: insertAtLastInSecond();
                break;
            case 3: displayAllNodesForFirst();
                break;
            case 4: displayAllNodesForSecond();
                break;
            case 5: compairTwoLinklist();
                break;
            default: printf("Invalid input ");
                break;
        }
    }
    while (n != 0);
    return 0;
}