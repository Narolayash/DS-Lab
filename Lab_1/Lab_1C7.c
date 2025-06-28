// WAP to convert number of days into year, week & days [e.g. 375 days mean 1 
// year, 1 week and 3 days]. 
#include <stdio.h>

int main() {
    //input days
    int day, week, year;
    printf("Enter the DAYS :");
    scanf("%d" , &day);

    // days ==> year, week, day
    year = day / 365;
    day %= 365;
    week = day / 7;
    day %= 7;
    printf("%d year, %d week, %d days", year, week, day);

    return 0;
}