// שאלה4.c
// Name: Lior Roife
// 17/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/****************************************************************************************************************
This program gets as input X and Y of two different points and outputs the Euclidean Distance between the points.
****************************************************************************************************************/
struct POINT
{
	float X;
	float Y;
};
void main()
{
	struct POINT p1, p2;
	float Eucdistance;
	printf("Please enter X , Y of Two Different Points (X,Y ,X,Y) \n");
	scanf("%f %f %f %f", &p1.X, &p1.Y, &p2.X, &p2.Y);
	Eucdistance = sqrt((p2.X - p1.X) * (p2.X - p1.X) + (p2.Y - p1.Y) * (p2.Y - p1.Y));
	printf("The Euclidean Distance between then points is: %f \n ", Eucdistance);
}