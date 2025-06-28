// 49. WAP to allocate and de-allocate memory for int, char and float variable at 
// runtime. 

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 1;

    int *iptr = (int *) malloc( n * sizeof(int));
    char *cptr = (char *) malloc( n * sizeof(char));
    float *fptr = (float *) malloc( n * sizeof(float));

    *iptr = 5;
    *cptr = 'a';
    *fptr = 10.5;

    if(*iptr && *cptr) {
        printf("%d", *iptr);
        printf("%c", *cptr);
        printf("%f", *fptr);

        free(iptr);
        free(cptr);
        free(fptr);
    }
    else {
        printf("Memory alloction failed");
    }
    
    return 0;
}