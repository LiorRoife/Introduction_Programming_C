// שאלה1.c
// Name: Lior Roife
// 17/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*****************************************************************************************
The program gets as input a , b and Y of the Linear Function "y=ax+b" and outputs the value of X.
******************************************************************************************/

void main()
{
	double a, b, y, x;
	printf("Enter a , b and Y of a Linear function \n");
	scanf("%lf %lf %lf", &a, &b, &y);             // y=ax +b --> x=(y-b)/a
	x = (y - b) / a;
	if (y == a * x + b)
		printf("The solution is: %lf\n", x);
	else if (y - b != 0 && a == 0)
		printf("There is no solution\n");
	else if (y - b == 0 && a == 0)
		printf("There is an infinite amount of solutions\n");
}