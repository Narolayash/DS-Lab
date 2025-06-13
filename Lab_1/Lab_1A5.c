// 5. WAP to check for the leap year. 
#include<stdio.h>
int main() {
    //input year
    int year;
    printf("Enter the YEAR :");
    scanf("%d" , &year);

    //logic to check year is leap year or not
    if( year % 4 == 0) {
        if( year % 100 == 0 ) {
            if( year % 400 == 0 ) {
                printf("Year %d is Leap year" , year);
            }
            else {
                printf("Year %d is Not Leap year" , year );
            }
        }
        else {
            printf("Year %d is Leap year" , year);
        }
    }
    else {
        printf("Year %d is Not Leap year" , year );
    }

    return 0;
}