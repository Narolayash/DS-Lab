// 55. WAP to define a C structure named Student (roll_no, name, branch and 
// batch_no) and also to access the structure members using Pointer. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[20];
    char branch[20];
    int batch_no;
};

int main() {
    struct Student *ptr = (struct Student*) malloc (sizeof(struct Student));

    ptr->roll_no = 224;
    strcpy(ptr->name, "Narola Yash N");
    strcpy(ptr->branch, "B. Tech CSE");
    ptr->batch_no = 7;

    printf("Student Details : \n");
    printf("%d \n", ptr->roll_no);
    printf("%s \n", ptr->name);
    printf("%s \n", ptr->branch);
    printf("%d \n", ptr->batch_no);

    free(ptr);
    return 0;
}