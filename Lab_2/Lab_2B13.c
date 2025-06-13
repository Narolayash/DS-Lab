// 13. WAP to print prime numbers between given interval. 
#include <stdio.h>

int main(){
    //input interval 
    int a, b;
    printf("Enter the Interval :");
    scanf("%d %d", &a, &b);

    // loop to find prime numbers between given interval
    for (int k = a; k <= b; k++) {
        int flag = 0;
        if (k == 1) {
            flag = 1;
        }
        else {
            for (int i = 2; i * i <= k; i++) {
                if (k % i == 0) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0) {
            printf("%d  ", k);
        }
    }
    
    return 0;
}