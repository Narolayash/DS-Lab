// 1. WAP to calculate area of a Circle (A = πr2). 
#include<stdio.h>

double areaOfCircle (double );

int main () {
    // enter radius
    double r, area;
    printf("Enter the Radius ");
    scanf("%f" , &r);

    area = areaOfCircle(r);
    printf("Area of Circle is %f ", area);

    return 0;
}

// function for calculate area
double areaOfCircle (double r) {
    return 3.14*r*r;
}