// 33. Design anagram game using array.  
// • Allow a user to enter N words and store it in an array.  
// • Generate a random number between 0 to N-1.  
// • Based on the random number generated display the word stored at that 
// index of an array and allow user to enter its anagram.  
// • Check whether the word entered by the user is an anagram of displayed 
// number or not and display an appropriate message.  
// • Given a word A and word B. B is said to be an anagram of A if and only if 
// the characters present in B is same as characters present in A, 
// irrespective of their sequence. For ex: “LISTEN” == “SILENT” 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void anagarm(char str1[20], char str2[20]);

int main() {
    // create char array
    int n;
    printf("How many number you want to enter : ");
    scanf("%d", &n);
    char words[n][20];

    // initialization of char array
    printf("--- Enter Names --- \n");
    for(int i=0; i<n; i++) {
        scanf("%s", words[i]);
    }

    // generated random number
    int randomNum = rand() % n;

    // print random string 
    printf("Random generated name = %s \n", words[randomNum]);

    // user input string
    char userStr[20];
    printf("Enter Your String : ");
    scanf("%s", userStr);

    anagarm(words[randomNum], userStr);

    return 0;
}

// check anagram or not
void anagarm(char str1[20], char str2[20]) {
    for(int i=0; i<str1[i]!='\0'; i++) {
        for(int j=0; j<str1[j]!='\0'; j++) {
            if(str1[i] < str1[j]) {
                char temp = str1[i];
                str1[i] = str1[j];
                str1[j] = temp;
            }
        }
    }
    for(int i=0; i<str2[i]!='\0'; i++) {
        for(int j=0; j<str2[j]!='\0'; j++) {
            if(str2[i] < str2[j]) {
                char temp = str2[i];
                str2[i] = str2[j];
                str2[j] = temp;
            }
        }
    }

    if (strcmp(str1, str2) == 0) {
        printf("Strings are equal\n");
    } else {
        printf("Strings are not equal\n");
    }

    return 0;
}
