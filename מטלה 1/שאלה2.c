// שאלה2.c
// Lior Roife
// ID: 206257826
// 11/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
This program gets as input a , b , x and returns the Y value of the function,
Then the program gets as input new Y and prints the X value of the function (using the a and b values from the strarting).
*/
void main()
{
	double a, b, x, y, x1, y1;
	printf("Please Enter a and b of a liniary function and the X ");
	scanf("%lf %lf %lf", &a, &b, &x);
	y = a * x + b;
	printf("The Y is: %lf ", y);

	printf("\nNow Please Enter a Y\n");
	scanf("%lf", &y1);
	x1 = (y1 - b) / a;
	printf("The X is: %lf ", x1);
}