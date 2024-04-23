// שאלה1.c
// ID: 206257826
// Lior Roife	
// 11/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
This program gets as input the Radius value of a circle and outputs the Area and the Scope of the circle. 
*/
const double PI = 3.14;
void main()
{
	double radius, area, scope;
	printf("Please Enter The Radius Of The Circle\n");
	scanf("%lf", &radius);
	scope = radius * 2 * PI;
	area = radius * radius * PI;
	printf("The Area Of The Circle Is: %f \n And The Scope Of The Circle Is: %f \n", area, scope);
}