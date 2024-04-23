// שאלה3.c
// Name: Lior Roife
// 29/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*********************************************************************************************************************************
This program gets as input a seria of numbers as "chars", converts every number to int and outputs the Octal value of the number.
The program stop to get inputs when the input is "\n" (ENTER).
**********************************************************************************************************************************/

void main()
{
	int num, sum = 0;
	char ch;
	scanf("%c", &ch);
	while (ch != '\n')
	{
		num = (int)(ch - 48);
		sum *= 8;
		sum += num;
		scanf("%c", &ch);
	}
	printf("%d", sum);
}