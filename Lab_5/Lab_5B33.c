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

    // baki

    return 0;
}