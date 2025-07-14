    // 59. Write a program to remove the duplicates nodes from given sorted Linked List. 
    // • Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27 
    // • Output: 1 → 6 → 13 → 27 

    #include <stdio.h>
    #include <stdlib.h>

    // define Node --- >
    struct node {
        int info;
        struct node *link;
    };

    // create a new node function
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

    void displayAllNodes(struct node *first) {
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

    void removeDuplicate(struct node **first) {
        if (*first == NULL) {
            printf("List is empty \n");
            return;
        }

        struct node *save = *first, *temp;

        while (save != NULL  && save->link != NULL) {
            if(save->info == save->link->info) {
                temp = save->link;
                save->link = temp->link;
                free(temp);
            }
            else {
                save = save->link;
            }
        } 
    }

    int main() {
    struct node *first = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert value\n");
        printf("2. Display list\n");
        printf("3. Remove duplicates\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtLast(value, &first);
                break;

            case 2:
                printf("Current Linked List: ");
                displayAllNodes(first);
                break;

            case 3:
                removeDuplicate(&first);
                printf("Duplicate values removed.\n");
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice != 0);

    return 0;
}