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

void mergeIntervals(struct interval inter[], int size) {
    if (size <= 0) 
        return; 

    
}

int main() {
    // interval inputs...
    struct interval inter[] = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};
    int size = sizeof(inter) / sizeof(inter[0]);

    mergeIntervals(inter, size);

    return 0;
}

// // push method for interval stack
// void push(struct interval stack[], int size, int* top, int start, int end) {
//     if(*top >= size - 1) {
//         printf("stack overflow \n");
//         return;
//     }

//     ++(*top);
//     stack[(*top)].start = start;
//     stack[(*top)].end = end;
// }

// // pop method for interval stack
// struct interval pop(struct interval stack[], int* top) {
//     if(*top <= -1) {
//         printf("stack underflow \n");
//         return;
//     }

//     return (stack[(*top)--]);
// }
// void mergeIntervals(struct interval inter[], int sizeOfInter) {
//     // interval stack
//     struct interval stack[50];
//     int top = -1;
//     int size = sizeof(stack) / sizeof(stack[0]);

//     for(int i=0; i<sizeOfInter-1; i++) {
//         for(int j=i+1; j<sizeOfInter; j++) {
//             if(compare(inter[i].start, inter[j].start)) {

//             }
//         }
//     }

//     // insert fisrt element in stack
//     push(stack, size, &top, inter[0].start, inter[0].end);

//     for(int i=1; i<sizeOfInter; i++){

//             if(stack[top].end > inter[i].start) {
//                 if(stack[top].end < inter[i].end)
//                     stack[top].end = inter[i].end;
//             }
//             else
//                 push(stack, size, &top, inter[i++].start, inter[i++].end);
//     }
// }


// ------------------------- solution --------------------------
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int start;
//     int end;
// } Interval;

// int compare(const void* a, const void* b) {
//     return ((Interval*)a)->start - ((Interval*)b)->start;
// }

// void mergeIntervals(Interval arr[], int n) {

//     if(n <= 0) return;

//     qsort(arr, n, sizeof(Interval), compare);

//     Interval result[n];
//     int index = 0;

//     result[index] = arr[0];

//     for(int i = 1; i < n; i++) {

//         if(arr[i].start <= result[index].end) {

//             if(arr[i].end > result[index].end)
//                 result[index].end = arr[i].end;
//         }
//         else {

//             index++;
//             result[index] = arr[i];
//         }
//     }

//     printf("Merged intervals:\n");
//     for(int i = 0; i <= index; i++)
//         printf("{%d,%d} ", result[i].start, result[i].end);
// }

// int main() {

//     Interval arr[] = {{1,3},{2,4},{6,8},{9,10}};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     mergeIntervals(arr, n);

//     return 0;
// }