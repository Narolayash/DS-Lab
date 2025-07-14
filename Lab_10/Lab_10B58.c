// 58. WAP to check whether 2 singly linked lists are same or not.

#include <stdio.h>
#include <stdlib.h>

// define Node --- >
struct node
{
    int info;
    struct node *link;
};

// create a new node function
struct node *createNode(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode)
        return NULL;

    newNode->info = x;
    newNode->link = NULL;

    return newNode;
}
void compareTwoLinklist(struct node *first1, struct node *first2)
{
    if (first1 == NULL && first2 == NULL)
    {
        printf("Both linklist is null, so they are same \n");
        return;
    }
    if (first1 == NULL)
    {
        printf("first linklist is null \n");
        return;
    }
    if (first2 == NULL)
    {
        printf("second linklist is null \n");
        return;
    }

    struct node *temp1 = first1, *temp2 = first2;
    int flag = 1;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->info != temp2->info)
        {
            flag = 0;
            break;
        }
        temp1 = temp1->link;
        temp2 = temp2->link;
    }

    if (temp1 != NULL || temp2 != NULL)
    {
        flag = 0;
    }

    if (flag)
    {
        printf("Linked List are the same \n");
    }
    else
    {
        printf("Linked list are not the same \n");
    }
}

void displayAllNodes(struct node *first)
{
    if (first == NULL)
    {
        printf("The Linked List is empty \n");
        return;
    }

    struct node *save;
    save = first;
    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL \n");
}

void insertAtLast(int x, struct node **first)
{
    struct node *newNode = createNode(x);

    if (*first == NULL)
    {
        *first = newNode;
        return;
    }

    struct node *save;
    save = *first;
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = newNode;

    printf("Node inserted at the end successfully.\n");
}

int main()
{
    struct node *first1 = NULL;
    struct node *first2 = NULL;
    int choice, value;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert in first linked list\n");
        printf("2. Insert in second linked list\n");
        printf("3. Display first linked list\n");
        printf("4. Display second linked list\n");
        printf("5. Compare both linked lists\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert in first list: ");
            scanf("%d", &value);
            insertAtLast(value, &first1);
            break;

        case 2:
            printf("Enter value to insert in second list: ");
            scanf("%d", &value);
            insertAtLast(value, &first2);
            break;

        case 3:
            printf("First linked list: ");
            displayAllNodes(first1);
            break;

        case 4:
            printf("Second linked list: ");
            displayAllNodes(first2);
            break;

        case 5:
            compareTwoLinklist(first1, first2);
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}