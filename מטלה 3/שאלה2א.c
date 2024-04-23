// שאלה2א.c
// Name: Lior Roife
// 29/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*********************************************************************************************************************************
This program gets as input Ten integer numbers and prints their "Algebric Average" and their "Geometric Average" if there is one.
**********************************************************************************************************************************/
void main()
{
	int x, i, count = 0;
	double avg1 = 0, avg2 = 0, sum1 = 0, sum2 = 1;

	for (i = 1; i <= 10; i++)
	{
		scanf("%d", &x);
		sum1 += x;
		if (x > 0)
		{
			count++;
			sum2 *= (double)x;
		}
		if (i == 10)
		{
			avg1 = (double)sum1 / 10.0;
			avg2 = (double)pow(sum2, (1.0 / count));
			printf("\n");
		}
	}
	if (sum1 == 0)
		printf("0.0000 No positive numbers, hence no geometric mean\n");
	else
	{
		printf("The Algebraic average is: %lf\n", avg1);
		printf("The Geometric average is: %lf\n", avg2);
	}
}