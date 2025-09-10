// 75. Write a menu driven program to implement Binary Search Tree (BST) & perform 
// following operations:  
// • Insert a node 
// • Delete a node 
// • Search a node 
// • Preorder Traversal 
// • Postorder Traversal 
// • Inorder Traversal 

#include <stdio.h>

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
        
    if(root->info > value)
        return search(root->lptr, value);
    
        
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
