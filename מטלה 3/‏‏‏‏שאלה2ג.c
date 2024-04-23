// שאלה2ב.c
// Name: Lior Roife
// 29/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*********************************************************************************************************************************
This program gets as input "s" integer numbers (s = number of the numbers in the seria)
and prints their "Algebric Average" and their "Geometric Average" if there is one.
**********************************************************************************************************************************/
void main()
{
	int x, count1 = 0, count2 = 0;
	double avg1 = 0, avg2 = 0, sum1 = 0, sum2 = 1;
	scanf("%d", &x);
	while (x != -1)
	{
		sum1 += x;
		if (x > 0)
		{
			count1++;
			sum2 *= (double)x;
		}
		count2++;
		scanf("%d", &x);
	}
	avg1 = (double)sum1 / count2;
	if (count1 != 0)
		avg2 = (double)pow(sum2, (1.0 / count1));
	if (sum1 == 0)
	{
		if (count1 == 0 && count2 != 0)
			printf(" 0.0000 No positive numbers, hence no geometric mean\n");

		else
			printf("Empty set of number, hence no arithmetic average\nNo positive numbers, hence no geometric mean\n");
	}
	else
	{
		printf("The Algebraic average is: %lf\n", avg1);
		printf("The Geometric average is: %lf\n", avg2);
	}
}