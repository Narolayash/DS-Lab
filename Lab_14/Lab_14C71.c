// 71. Write a program to perform addition of two polynomial equations using 
// appropriate data structure.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int coefficient;
    int exponent;
    struct node *link;
};

struct node* createPolyNode(int coefficient, int exponent) {
    struct node *newNode = (struct node*) malloc (sizeof(struct node));
    if(!newNode) return NULL;

    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->link = NULL;

    return newNode;
}

void insertAtLast(int coefficient, int exponent, struct node **first) {
    struct node *newNode = createPolyNode(coefficient, exponent);

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

void addRemainingNodes(struct node **fisrt) {
    int maxExponent = (*fisrt)->exponent;
    struct node *save = *fisrt, *pre = NULL;

    for(int i=maxExponent-1; i>=0; i--) {
        pre = save;
        save = save->link;
        if(save->exponent != i || i != 0) {
            struct node *newNode = createPolyNode(0, i);
            newNode->link = pre->link;
            pre->link = newNode;
            save = newNode;
        }
    }
}

void readyToDisply(struct node **first) {
    if(*first == NULL) {
        printf("List is empty \n");
        return;
    }

    for(struct node *i = *first; i->link != NULL; i = i->link){
        for(struct node *j = i->link; j != NULL; j = j->link) {
            if(i->exponent > j->exponent) {
                int temp1 = i->coefficient;
                int temp2 = i->exponent;

                i->coefficient = j->coefficient;
                i->exponent = j->exponent;

                j->coefficient = temp1;
                j->exponent = temp2;
            }
        }
    }

    addRemainingNodes(first);
}

void displayAllNodes(struct node *first) {
    if(first == NULL) {
        printf("The Linked List is empty \n");
        return;
    }

    struct node *save;
    save = first;
    while (save != NULL) {
        printf("%d X^%d -> ", save->coefficient, save->exponent);
        save = save->link;
    }
    printf("NULL \n");
}

struct node *additionOfPoly(struct node *first1, struct node *first2) {
    if(first1 == NULL && first2 == NULL) {
        printf("Poly is not found");
        return NULL;
    }

    if(!first1) return first2;
    if(!first2) return first1;

    struct node *save1 = first1, *save2 = first2, *newPoly = NULL, *newSave= NULL;
    while(save1 != NULL && save2 != NULL) {
        struct node *newNode = NULL;
        if(save1->exponent == save2->exponent) {
            newNode = createPolyNode((save1->coefficient + save2->coefficient), save1->exponent);
            save1 = save1->link;
            save2 = save2->link;
        }
        else if(save1->exponent > save2->exponent) {
            newNode = createPolyNode((save1->coefficient), save1->exponent);
            save1 = save1->link;
        }
        else {
            newNode = createPolyNode((save2->coefficient), save2->exponent);
            save2 = save2->link;
        }

        if(newPoly == NULL) {
            newPoly = newNode;
            newSave = newPoly;
        }
        else {
            newSave->link = newNode;
            newSave = newNode;
        }
    } 

    while (save1 != NULL) {
        struct node *newNode = createPolyNode(save1->coefficient, save1->exponent);
        newSave->link = newNode;
        newSave = newNode;
        save1 = save1->link;
    }
    while (save2 != NULL) {
        struct node *newNode = createPolyNode(save2->coefficient, save2->exponent);
        newSave->link = newNode;
        newSave = newNode;
        save2 = save2->link;
    }

    return newPoly;
}

int main() {
    struct node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    // Sample input for Poly1: 5x^2 + 4x^1 + 2
    insertAtLast(5, 2, &poly1);
    insertAtLast(4, 1, &poly1);
    insertAtLast(2, 0, &poly1);

    // Sample input for Poly2: 3x^3 + 2x^2 + 7x^1
    insertAtLast(3, 3, &poly2);
    insertAtLast(2, 2, &poly2);
    insertAtLast(7, 1, &poly2);

    printf("Polynomial 1:\n");
    displayAllNodes(poly1);

    printf("Polynomial 2:\n");
    displayAllNodes(poly2);

    result = additionOfPoly(poly1, poly2);

    printf("Resultant Polynomial (Sum):\n");
    displayAllNodes(result);

    return 0;
}