// שאלה5.c
// Name: Lior Roife
// 17/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*************************************************************************
This program gets as input a number and outputs it's number of Odd digits.
**************************************************************************/
void main()
{
	int num, count = 0;
	printf("Please enter a number\n");
	scanf("%d", &num);
	if (num < 0)
		printf("You have entered an invalid number\n");
	else
	{
		while (num != 0)
		{
			if ((num % 10) % 2 == 1)
				count++;
			num /= 10;
		}
		printf("The number has: %d Odd digits \n ", count);
	}
}