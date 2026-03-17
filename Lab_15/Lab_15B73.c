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
    while(save->rptr != NULL) 
        save = save->rptr;

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

    printf("NULL \n");
}

void deleteAlternateNode(struct node **first) {
    if(*first == NULL) return;

    int choise;
    printf("Enter 1 for odd nodes \n");
    printf("Enter 2 for even nodes \n");
    scanf("%d", &choise);

    struct node *save = *first, *temp;
    int posi = 1;

    while (save != NULL ){
        if((choise == 1 && posi % 2 != 0) || (choise == 2 && posi % 2 == 0)) {
            temp = save;
            
            if(save->lptr != NULL) 
                save->lptr->rptr = save->rptr;
            else 
                *first = save->rptr;
            
            if(save->rptr != NULL) 
                save->rptr->lptr = save->lptr;
            
            save = save->rptr;
            free(temp);
        }
        else {
            save = save->rptr;
            posi++;
        }
    }
}

int main() {
    struct node *first = NULL;
    int choice, val;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert a node at end\n");
        printf("2. Display list\n");
        printf("3. Delete alternate nodes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertANodeAtLast(val, &first);
                break;

            case 2:
                display(first);
                break;

            case 3:
                deleteAlternateNode(&first);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
