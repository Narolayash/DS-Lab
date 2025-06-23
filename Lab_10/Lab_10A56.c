// 56. Write a program to implement a node structure for singly linked list. Read the 
// data in a node, print the node.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

int main() {
    struct node *node1 = (struct node*)malloc(sizeof(struct node));
    node1 -> info = 25;
    node1 -> link = NULL;

    printf("%d", &node1->info);
    printf("%d", &node1->link);
}