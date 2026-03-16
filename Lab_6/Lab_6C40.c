// 40. Vowel Anxiety Problem
// Utkarsh has recently started taking English-language classes to improve his
// reading and writing skills. However, he is still struggling to learn English. His
// teacher gave him the following problem to improve his vowel-identification
// skills:

// There is a string S of length N consisting of lowercase English letters only.
// Utkarsh has to start from the first letter of the string.
// Each time he encounters a vowel; he has to reverse the entire substring that
// came before the vowel.
// Utkarsh needs help verifying his answer. Can you print the final string after
// performing all the operations for him?

// Input Format:
// • First line will contain T, number of test cases. Then T test cases follow.
// • The first line of each test case contains N, the length of the string.
// • The second line contains S, the string itself.

// Output Format:
// For each test case, output in a single line the final string after traversing S from
// left to right and performing the necessary reversals.

#include <stdio.h>
#include <string.h>

int isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void reverse(char s[], int l, int r){
    while (l < r)
    {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
}

int main(){

    int T;
    scanf("%d", &T);

    while (T--)
    {

        int n;
        char s[1000];

        scanf("%d", &n);
        scanf("%s", s);

        for (int i = 0; i < n; i++)
        {

            if (isVowel(s[i]))
            {
                reverse(s, 0, i - 1);
            }
        }

        printf("%s\n", s);
    }
}
