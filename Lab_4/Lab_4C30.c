// 30. WAP to replace lowercase characters by uppercase & vice-versa in a user 
// specified string. 

#include <stdio.h>

int main() {
    char str[50];

    printf("Enter the String : ");
    scanf("%s", str);

    for(int i=0; str[i] != '\0'; i++) {
        if(str[i] >= 'a' && str[i] <='z') {
            str[i] -= 32;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }

    printf("--- Final String --- \n");
    printf("%s", str);

    return 0;
}