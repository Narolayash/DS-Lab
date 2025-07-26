// Armstrong number
#include <stdio.h>

void isArmstrongNumber(int n) {
    int org = n;
    int digit=0;

    while (org != 0) {
        digit++;
        org /= 10;
    }

    org = n;
    int ans=0;
    while(org != 0) {
        int power=1;
        for(int i=0; i<digit; i++) {
            power *= (org%10); 
        }
        ans += power;
        org /= 10;
    }

    if(ans == n)
        printf("Number is an armstrong nubmer \n");
    else 
        printf("Number us not an armstrong number \n");
}


int main() {
    int n;
    printf("Enter the nubmer : ");
    scanf("%d", &n);

    isArmstrongNumber(n);

    return 0;
}