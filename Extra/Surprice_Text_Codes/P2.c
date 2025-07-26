#include <stdio.h>

void print_factors (int  n) {
    for(int i=1; i<=n/2; i++) {
        if(n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("%d.", n);

}
int main() {
    int n;
    printf("Enter the number :");
    scanf("%d", &n);

    print_factors(n);
    
    return 0;
}