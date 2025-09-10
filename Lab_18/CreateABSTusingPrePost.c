// Write a program to construct a binary tree from given Postorder and Preorder 
// traversal sequence. 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *left;
    struct node *right;
};

// create a new node 
struct node *createNode(int num) {
    struct node *newNode = (struct node*) malloc (sizeof(struct node));

    newNode->num = num;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// searching index from postorder 
int search(int post[], int el, int l, int h) {
    for(int i=l; i<=h; i++) {
        if(post[i] == el) {
            return i;
        }
    }

    return -1;
}

// construct a binary tree
struct node *createBST(int pre[], int post[], int *preIdx, int l, int h, int size) {
    if(*preIdx >= size || l>h) 
        return NULL;;
    
    struct node *root = createNode(pre[*preIdx]);
    (*preIdx)++;
    
    if(l == h || *preIdx >= size) 
        return root;
    
    int i = search(post, pre[*preIdx], l, h);

    if(i != -1) {
        root->left = createBST(pre, post, preIdx, l, i, size);
        root->right = createBST(pre, post,  preIdx, i+1, h-1, size);
    }

    return root;
}

void inorder(struct node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->num);
    inorder(root->right);
}

int main() {
    int pre[] = {4, 5, 2, 6, 7, 3, 1};
    int post[] = {1 ,2, 4 , 5, 3, 6, 7};
    int preIdx = 0;
    int size = 7;
    int l = 0;
    int h = size;

    struct node *root;
    root = createBST(pre, post, &preIdx, l, h, size);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");


    return 0;
}
