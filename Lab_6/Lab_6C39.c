// 39. Merge Intervals Problem 
// Given a set of time intervals in any order, our task is to merge all overlapping 
// intervals into one and output the result which should have only mutually 
// exclusive intervals. 
 
// Sample Example-1: 
// Input: Intervals = {{1,3},{2,4},{6,8},{9,10}} 
// Output: {{1, 4}, {6, 8}, {9, 10}} 
// Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping 
// intervals here,[1,3] and [2,4]. Therefore we will merge these two and return [1,4],[6,8], 
// [9,10] 
 
// Sample Example-2: 
// Input: Intervals = {{6,8},{1,9},{2,4},{4,7}} 
// Output: {{1, 9}}

#include <stdio.h>

struct interval {
    int start, end;
};

// push method for interval stack
void push(struct interval stack[], int size, int* top, int start, int end) {
    if(*top >= size) {
        printf("stack overflow \n");
        return;
    }

    stack[++(*top)].start = start;
    stack[++(*top)].end = end;
}

// pop method for interval stack
struct interval pop(struct interval stack[], int* top) {
    if(*top <= -1) {
        printf("stack underflow \n");
        return;
    }
    else return (stack[(*top)--]);
}

int compare(int s1, int s2) {
    if()
}


void mergeIntervals(struct interval inter[], int sizeOfInter) {
    // interval stack
    struct interval stack[50];
    int top = -1;
    int size = sizeof(stack) / sizeof(stack[0]);

    for(int i=0; i<sizeOfInter-1; i++) {
        for(int j=i+1; j<sizeOfInter; j++) {
            if(compare(inter[i].start, inter[j].start)) {

            }
        }
    }

    // insert fisrt element in stack
    push(stack, size, &top, inter[0].start, inter[0].end);

    for(int i=1; i<sizeOfInter; i++){

            if(stack[top].end > inter[i].start) {
                if(stack[top].end < inter[i].end)
                    stack[top].end = inter[i].end;
            }
            else 
                push(stack, size, &top, inter[i++].start, inter[i++].end);
    }
}

    
int main() {
    // interval inputs...
    struct interval inter[] = {{1,3},{2,4},{6,8},{9,10}};
    int size = sizeof(inter) / sizeof(inter[0]);

    return 0;
}