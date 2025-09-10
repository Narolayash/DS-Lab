#include <stdio.h>
#include <stdlib.h>

// structure for each node of the tree
struct node { 
    int val;
    struct node* left;
    struct node* right;
};

// function which create a new node and return new node
struct node* createNode(int val) {
    struct node* newNode = (struct node*) malloc (sizeof(struct node));
    newNode->val = val;
    newNode->left = newNode->right = NULL;

    return newNode;
}

