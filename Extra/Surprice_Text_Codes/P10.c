// write a program that should decode the given pattern and print the resulting expanded string.
// Input: 2a3bc4dE5F2G7H
// Output : aabbbcddddEFFFFFGGHHHHHHH

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[20], new[100];
    printf("Enter the strnig :");
    scanf("%s", str);

    int i=0, k=0;
    char next = str[i++];
    while(next != '\0') {
        int digit = 1;
        if(isdigit(next)) {
            digit = next - '0';
            next = str[i++];
            for(int j=0; j<digit; j++) {
                new[k++] = next; 
            }
        }
        else {
            new[k++] = next;
        }
        next = str[i++];
    }

    new[k] = '\0';

    printf("%s \n", str);
    printf("%s \n", new);
    return 0;
}