// 60. Write a program to implement stack using singly linked list. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

int push (struct node **top, int x) {
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    if (newNode == NULL) return 0;

    newNode->info = x;
    newNode->link = *top;
    *top = newNode;

    return 1;
}

int pop (struct node **top) {
    if(*top == NULL) return -1; 

    struct node *temp = *top;
    int info = temp->info;
    *top = temp->link;
    free(temp);

    return info;
}

int peek (struct node *top) {
    if(top == NULL) return -1;

    return top->info;
}

void display (struct node *top) {
    if(top == NULL) {
        printf("Stack is empty \n");
        return;
    }

    printf("Stack Element --- \n ");
    struct node *save = top;
    while(save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }

    printf("NULL \n ");
}

int main () {
    struct node *top = NULL;

    // push 
    push(&top, 10);
    push(&top, 20);
    display(top);

    // pop
    int info = pop(&top);
    printf("%d \n", info);

    //peek
    printf("%d \n", peek(top));

    //display
    display(top);

    return 0;
}