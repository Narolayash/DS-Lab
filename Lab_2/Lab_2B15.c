// 15. WAP to print Armstrong number from 1 to 1000. 
#include <stdio.h>

int main() {
    printf("--- Armstrong Numbers --->");
    for(int n=0; n<=1000; n++) {
        int org, digit=0, sum=0;

        org = n;
        // loop to find how many digit 
        while(org != 0) {
            digit++;
            org /= 10;
        }

        org = n;
        // loop to calculate sum
        while(org != 0) {
            int temp = 1;
            // loop for powers
            for(int i=0; i<digit; i++) {
                temp *= (org % 10);
            }
            sum += temp;
            org /= 10;
        }

        if(sum == n) {
            printf("%d ", n);
        }
    }

    return 0;
}