// שאלה5.c
// Name: Lior Roife
// 29/11/19


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*********************************************************************************************************************************
This program gets as input two numbers and outputs true if the first number contains the second number.
**********************************************************************************************************************************/

int digit(int num);
void isContained(int bn, int n);

void main()
{
	int num, bignum;
	scanf("%d %d", &bignum, &num);
	isContained(bignum, num);
}

void isContained(int bn, int n)          // This function checks if the first number contains the second number.
{
	int digitn1 = digit(n), f = 0;
	if (n == 0)
	{
		if (bn == 0)
			printf("true\n");
		else
			printf("false\n");
	}
	else
	{
		while (bn > 0)
		{
			if (bn % (int)pow(10, digitn1) == n)
			{
				printf("true\n");
				bn = 0;
				f = 1;
			}
			bn /= 10;
		}
		if (f == 0)
			printf("false\n");
	}
}

int digit(int num)                    // This function checks how many digits a number have.
{
	int count = 0;
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	return count;
}