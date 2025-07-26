#include <stdio.h>

int main() {
    int row;
    printf("Enter the number of rows you want : ");
    scanf("%d", &row);

    for(int i=0; i<row; i++) {
        for(int j=0; j<(2*i+1); j++) {
            if(j == 0 || j == i)  
                printf("%d ", (j+1));
            else if(j == 2*i)
                printf("1 ");
            else
                printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}