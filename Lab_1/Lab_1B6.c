// WAP to convert seconds into hours, minutes & seconds and print in HH:MM:SS 
// [e.g. 10000 seconds mean 2:46:40 (2 Hours, 46 Minutes, 40 Seconds)]. 
#include<stdio.h>

int main() {
    //input seconds
    int sec, min, hour ;
    printf("Enter the Seconds :");+
    scanf("%d" , &sec);

    //second ==> hour, minute, second
    hour = sec / 3600;
    sec %= 3600;
    min = sec / 60;
    sec %= 60;
    printf("%d : %d : %d ", hour, min, sec);
    
    return 0;
}