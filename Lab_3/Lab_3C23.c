//  WAP to sort the N names in an alphabetical order. 

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number how many names you want to enter : ");
    scanf("%d", &n);

    // make char ary
    char names[n][20], temp[20];

    // input names
    printf("--- Input Names --- \n");
    for(int i=0; i<n; i++) {
        printf("Entre name %d : " , (i+1));
        scanf("%s", names[i]);
    }

    // print before sorting in alphabetical order
    printf("--- print all names before sortnig  --- \n");
    for(int i=0; i<n; i++) {
        printf("%d Name : %s \n", (i+1), names[i]);
    }

    // logic for sorting names
    for(int i=0; i<(n-1); i++) {
        for(int j=(i+1); j<n; j++) {
            if(strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    // print after sorting in alphabetical order
    printf("--- print all names after sortnig  --- \n");
    for(int i=0; i<n; i++) {
        printf("%d Name : %s \n", (i+1), names[i]);
    }

    return 0;
}