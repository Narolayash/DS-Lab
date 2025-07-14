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
        printf("MEmory allocation failed /n");
        return NULL;
    }

    // initialazation
    newNode->info = x;
    newNode->link = NULL;

    return newNode;
}

// insert at first position of linked list                                          (1.) Done
struct node* insertAtFirstPosition(int x, struct node *first){
    struct node *newNode = createNode(x);

    newNode->link = first;
    first = newNode;

    printf("Insert at first position successful \n");
    return first;
}


// insert at last position of linked list                                           (2.) Done
struct node* insertAtLastPosition(int x, struct node *first) {
    struct node *newNode = createNode(x);

    if(first == NULL) {
        first = newNode;
        return first;
    }

    struct node *save = first;
    while (save->link != NULL) {
        save = save->link;
    }
    save->link = newNode;

    printf("Insert at last position successful \n");
    return first;
}

// insert a node in ordered linked list                                             (6.) Done
struct node* insertInOrderedLinkedList(int x, struct node *first) {
    struct node *newNode = createNode(x);

    if(first == NULL) {
        first = newNode;
        return first;
    }

    if(newNode->info <= first->info) {
        newNode->link = first;
        return newNode;
    }
    
    struct node *save = first;

    while(save->link != NULL && (newNode->info > save->link->info)) {
        save = save->link;
    }
    newNode->link = save->link;
    save->link = newNode;

    return first;
}

// --- > Merge Two Sorted Lists                                                     (3.) Done
//  You are given the heads of two sorted linked lists list1 and list2.
//  Merge the two lists in a one-sorted list. The list should be made by
//  splicing together the nodes of the first two lists
struct node* mergeTwoSortedLists(struct node *list1, struct node *list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    struct node *save1 = list1;
    struct node *save2 = list2;
    struct node *newfirst = NULL, *newSave = NULL;

    if(newfirst == NULL) {
        if(list1->info <= list2->info) {
            newfirst = list1;
            save1 = save1->link;
        }
        else {
            newfirst = list2;
            save2 = save2->link;
        }
    }

    newSave = newfirst;

    while(save1 != NULL && save2 !=NULL) {
        if(save1->info <= save2->info) {
            newSave->link = save1;
            save1 = save1->link;
        }
        else {
            newSave->link = save2;
            save2 = save2->link;
        }
        newSave = newSave->link;
    }

    if(save1 == NULL) {
        newSave->link = save2;
    }
    else {
        newSave->link = save1;
    }

    printf("Merge two sorted list successful \n");
    
    // return first node address after new arengment
    return newfirst;
}


// any info count how many times info appear in list                                (4.) Done
void anyInfoCount(struct node *first) {
    if(first == NULL) {
        printf("List is empty \n");
        return;
    }

    struct node *save = first, *next = NULL, *pre = NULL;

    while (save != NULL) {
        int count = 1;
        next = save->link;
        pre = save;
        while (next != NULL) {
            if(save->info == next->info) {
                struct node *temp = next;
                pre->link = next->link;
                next = next->link;
                free(temp);
                count++;
            }else {
                pre = next;
                next = next->link;
            }
        }
        printf("%d number -> %d times \n", save->info, count);
        save = save->link;
    }
}

// Ek function je ne tame value aapo to te first value jeni sathe match thay tenu address return kre 


// create two linklist (1. which contains Odd Numbers ) & (2. which contains Even number )   (5.) Done
struct node *oddHead = NULL, *evenHead = NULL;
void OddEvenNumver(struct node *first) {
    if(first == NULL) {
        printf("List is NULL \n");
        return;
    }

    struct node *save = first,*oddSave = NULL, *evenSave = NULL;

    while(save != NULL) {
        if(save->info % 2 != 0) {
            //odd
            struct node *newNode = (struct node*) malloc (sizeof(struct node));
            newNode->info = save->info;
            newNode->link = NULL;

            if(oddHead == NULL) {
                oddHead = newNode;
                oddSave = oddHead;
            }
            else {
                oddSave->link = newNode;
                oddSave = newNode;
            }
        } else {
            //even
            struct node *newNode = (struct node*) malloc (sizeof(struct node));
            newNode->info = save->info;
            newNode->link = NULL;

            if(evenHead == NULL) {
                evenHead = newNode;
                evenSave = evenHead;
            }
            else {
                evenSave->link = newNode;
                evenSave = newNode;
            }
        }
        save = save->link;
    }
}

// delete a node whose address is given by variable x                               (4.)
void deleteAtAddress(struct node *first, struct node *x) {
    if(first == NULL) {
        pritnf("Linked list is empty \n");
        return;
    }

    if(first == x) {
        first = first->link;
        free(x);
        return;
    }

    struct node *save = first, *pre = NULL;
    while (save != NULL && save !=x) {
        pre = save;
        save = save->link;
    }
    if(save == NULL) {
        printf("Node not found \n");
        return;
    }
    pre->link = x->link;
    free(x);
    printf("Node deleted \n");
}

// Tasks panding --- >
// recursive routine to erase a linked list (delete all node from the lined list) 

int main() {
    
    // 1... struct node* insertAtFirstPosition(int x, struct node *first)
    // 2... struct node* insertAtLastPosition(struct node *first)
    // 3... struct node* mergeTwoSortedLists(struct node *list1, struct node *list2)
    // 4... void anyInfoCount(struct node *first)
    // 5... void OddEvenNumver(struct node *first)
    // 6... struct node* insertInOrderedLinkedList(int x, struct node *first)

    struct node *first1 = NULL;
    struct node *first2 = NULL;

    first1 = insertAtFirstPosition(10, first1);
    first1 = insertAtFirstPosition(20, first1);
    first1 = insertAtFirstPosition(30, first1);
    anyInfoCount(first1);


    // first1 = insertAtLastPosition(20, first1);
    // first1 = insertAtLastPosition(30, first1);
    // first1 = insertAtLastPosition(40, first1);
    // anyInfoCount(first1);

    // first2 = insertAtFirstPosition(15, first2);
    // first2 = insertAtLastPosition(25, first2);
    // first2 = insertAtLastPosition(35, first2);
    // first2 = insertAtLastPosition(45, first2);
    // first2 = insertAtLastPosition(55, first2);
    // anyInfoCount(first2);

    // struct node *temp = mergeTwoSortedLists(first1, first2);
    // anyInfoCount(temp);

    // first1 = insertInOrderedLinkedList(25, first1);
    // anyInfoCount(first1);


    // OddEvenNumver(first1);
    // anyInfoCount(oddHead);
    // anyInfoCount(evenHead);

    return 0;
}