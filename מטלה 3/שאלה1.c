// שאלה1.c
// Name: Lior Roife
// 29/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*********************************************************************************************
This program gets as input two positive variables y, x positive integers (first x and then y) which define
The length and width of a rectangle. The program will print a rectangular frame consisting of X pixels long and Y pixels wide.
**********************************************************************************************/
void main()
{
	int x, y, i = 0, j = 0, s = 0;
	scanf("%d %d", &x, &y);
	if (x > 0 && y > 0)
	{
		for (i = 1; i <= y; i++)
		{
			if (i == 1 || i == y)
			{
				for (s = 1; s <= x; s++)
				{
					printf("*");
				}
				printf("\n");
			}
			if (i > 1 && i < y)
			{
				if (x != 1)
				{
					printf("*");
					for (j = 1; j < (x - 1); j++)
					{
						printf(" ");
					}
				}
				printf("*");
				printf("\n");
			}
		}
	}
	else
		printf("You have entered invalid number");
}