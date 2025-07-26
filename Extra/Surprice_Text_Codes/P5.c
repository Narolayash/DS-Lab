// calculate X^Y without using a power function 
// 1. with the help of multiplication
// 2. without multiplication

#include <stdio.h>

int power(int x, int y) {
    if(y == 0) return 1;
    
    return x * power(x, (y-1));
}

int main() {
    int x, y;
    printf("Enter the base value : ");
    scanf("%d", &x);
    printf("Enter the power : ");
    scanf("%d", &y);

    int ans = power(x, y);
    printf("%d ^ %d = %d", x, y, ans);

    return 0;
}


// with the help of multiplication
// int main() {
//     int x, y;
//     printf("Enter the base value : ");
//     scanf("%d", &x);
//     printf("Enter the power : ");
//     scanf("%d", &y);

//     int ans = 1;
//     for(int i=0; i<y; i++) {
//         ans *= x;
//     }

//     printf("%d ^ %d = %d", x, y, ans);

//     return 0;
// }