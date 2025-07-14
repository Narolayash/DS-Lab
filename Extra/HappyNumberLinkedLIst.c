// Done ... 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

// Creation of Node                                                                 (0.) Done
struct node* createNode(int x) { 
    // memory allocation                                                   
    struct node *newNode = (struct node*) malloc (sizeof(struct node));
    // memory allocation done or not
    if(newNode == NULL) {
        printf("Memory allocation failed /n");
        return NULL;
    }

    // initialazation
    newNode->info = x;
    newNode->link = NULL;

    return newNode;
}

// insert at last
void insertAtLastPosition(int x, struct node **first) {
    struct node *newNode = createNode(x);

    if(*first == NULL) {
        *first = newNode;
        return;
    }

    struct node *save = *first;
    while (save->link != NULL) {
        save = save->link;
    }
    save->link = newNode;
    // printf("Insert at last position successful \n");
}

int sumOfSqureOfDigit(int x) {
    int sum = 0;
    while(x != 0) {
        sum += (x%10) * (x%10);
        x /= 10;
    }
    return sum;
}

int traversInList(int x, struct node *first) {
    if(first == NULL) return 0;

    struct node *save = first;
    while (save != NULL) {
        if(save->info == x) {
            return 1;
        } 
        save = save->link;
    }
    return 0;
}

void happyNumber(int x, struct node *first) {
    insertAtLastPosition(x, &first);
    while (x != 1) {
        x = sumOfSqureOfDigit(x);
        int check = traversInList(x, first);
        if(check) break;
        insertAtLastPosition(x, &first);
    }

    if(x == 1) {
        printf("Number is Very Happy");
    }
    else {
        printf("Number is not happy");
    }
}

int main() {
    struct node *first = NULL;
    happyNumber(19, first);
    return 0;
}