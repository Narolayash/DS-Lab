// 60. Write a program to implement stack using singly linked list. 

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

int push (int x, struct node **top) {
    struct node *newNode = createNode(x);

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

int main() {
    struct node *top = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value, &top);
                printf("%d pushed onto the stack.\n", value);
                break;

            case 2:
                value = pop(&top);
                if(value == -1)
                    printf("Stack Underflow: Nothing to pop.\n");
                else
                    printf("Popped value: %d\n", value);
                break;

            case 3:
                value = peek(top);
                if(value == -1)
                    printf("Stack is empty.\n");
                else
                    printf("Top value: %d\n", value);
                break;

            case 4:
                display(top);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 0);

    return 0;
}