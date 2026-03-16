// 75. Write a menu driven program to implement Binary Search Tree (BST) & perform 
// following operations:  
// • Insert a node 
// • Delete a node 
// • Search a node 
// • Preorder Traversal 
// • Postorder Traversal 
// • Inorder Traversal 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *lptr;
    struct node *rptr;
};

// create node 
struct node* createNode(int value) {
    struct node* newNode = (struct node*) malloc (sizeof(struct node));
    if(!newNode) return NULL;

    newNode->info = value;
    newNode->lptr = newNode->rptr = NULL;

    return newNode;
}

// Insert a node 
struct node* insertNode(struct node* root, int value) {
    if(root == NULL) 
        return createNode(value);

    if(root->info == value) return root;
    
    if(value < root->info) 
        root->lptr = insertNode(root->lptr, value);
    else
        root->rptr = insertNode(root->rptr, value);
    
    return root;
}

// delete a node
struct node *getSuccessor(struct node *root) {
    root = root->rptr;

    while(root != NULL && root->lptr != NULL) 
        root = root->lptr;
    
    return root;
}
struct node *deleteNode(struct node *root, int value) {
    if(root == NULL) return root;

    if(root->info > value) 
        root->lptr = deleteNode(root->lptr, value);
    
    else if(root->info < value) 
        root->rptr = deleteNode(root->rptr, value);

    else {

        if(root->lptr == NULL) {
            struct node *temp = root->rptr;
            free(root);
            return temp;
        }

        if(root->rptr == NULL) {
            struct node *temp = root->lptr;
            free(root);
            return temp;
        }

        struct node *succ = getSuccessor(root);
        root->info = succ->info;
        root->rptr = deleteNode(root->rptr, succ->info);
    }

    return root;
}

// search node from bst
struct node *search(struct node *root, int value) {
    if(root == NULL || root->info == value) 
        return root;
        
    if(value < root->info)
        return search(root->lptr, value);
    
    return search(root->rptr, value);
}

// Inorder Traversal
void inorder(struct node *root) {
    if(root == NULL) return;

    inorder(root->lptr);
    printf("%d ", root->info);
    inorder(root->rptr);
}

// Postorder Traversal
void postorder(struct node *root) {
    if(root == NULL) return;

    postorder(root->lptr);
    postorder(root->rptr);
    printf("%d ", root->info);
}

// Preorder Traversal
void preorder(struct node *root) {
    if(root == NULL) return;
    
    printf("%d ", root->info);
    preorder(root->lptr);   
    preorder(root->rptr);
}

int main() {
    struct node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- BST MENU ---\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search a node\n");
        printf("4. Preorder Traversal\n");
        printf("5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("%d found in BST\n", value);
                else
                    printf("%d not found in BST\n", value);
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

