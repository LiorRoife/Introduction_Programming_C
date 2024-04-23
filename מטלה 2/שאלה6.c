// שאלה6.c
// Name: Lior Roife
// 17/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*********************************************************************************************
This program gets as input a Number and an Index and outputs the the digit in the index place.
**********************************************************************************************/
void main()
{
	int index, number, n, i, count = 0, dig;
	// printf("Please Enter a number and an index\n"); // deleted because Automatic evaluation
	scanf("%d %d", &number, &index);
	n = number;
	while (n != 0)                                  // Check how many digis the number contain
	{
		n /= 10;
		count++;
	}
	if (index <= 0 || index > count)                  // Check if the index is valid
		printf("-1\n");
	else
	{
		for (i = 1; i < index; i++)
			number /= 10;
		dig = number % 10;
		if (number < 0)
			//	printf("The Result is: %d\n", -1 * (dig));      // deleted because Automatic evaluation
			printf("%d", -1 * (dig));
		else
			//	printf("The Result is: %d\n", dig);             // deleted because Automatic evaluation
			printf("%d", dig);
	}
}