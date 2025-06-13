//  WAP to find the sum of 1 + (1+2) + (1+2+3) + (1+2+3+4)+ …+(1+2+3+4+….+n). 
#include <stdio.h>

int main() {
    // input step
    int n, ans = 0;
    printf("Enter the Number : ");
    scanf("%d", &n);

    //loop for sum step
    for(int i=1; i<=n; i++) {
        int sum = 0;
        // loop for sum inner sums
        for(int j=1; j<=i; j++) {
            sum += j;
        }
        ans += sum;
    }
    printf("%d", ans);

    return 0;
 
}