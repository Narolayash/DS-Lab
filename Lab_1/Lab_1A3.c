// 3. WAP to determine whether the entered character is vowel or not.
#include<stdio.h>

int main () {
    //input character
    char c;
    printf("Enter the Character :");
    scanf("%c" , &c);

    //logic to find vowel
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e'  || c == 'i' || c == 'o' || c == 'u' ) {
        printf("Character is Vovel");
    }
    else {
        printf("Character is not Vovel");
    }

    return 0;
}