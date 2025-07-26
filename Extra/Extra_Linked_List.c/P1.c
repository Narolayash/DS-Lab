// 1. Reverse Nodes in k-Group  
// Problem: 
// • Given the head of a linked list, reverse the nodes of the list k at a time, and return 
// the modified list. 
// • Only nodes themselves may be changed; node values must remain unaltered.  
// • If the number of nodes is not a multiple of k, the remaining nodes at the end 
// remain as-is. 
// Examples: 
// • Input: head = [1,2,3,4,5], k = 2 
// • Output: [2,1,4,3,5] 
// • Input: head = [1,2,3,4,5], k = 3 
// • Output: [3,2,1,4,5]

// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int info;
//     struct node *link;
// }

// void revNodeInK_Group(struct node **first);