// שאלה4.c
// Name: Lior Roife
// 29/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/*********************************************************************************************************************************
This program gets as input a number and outputs the reversed number.
Example: for the input number 123 the output will be 321.
In addition the program Prints "true" if the number is Polindromic and "false" if its not.
**********************************************************************************************************************************/
int ReversedNum(int num);
bool isPolindromic(int num);
void main()
{
	int num, newnum = 0;
	scanf("%d", &num);
	newnum = ReversedNum(num);
	printf("%d\n", newnum);
	if (isPolindromic(num))
		printf("true\n");
	else
		printf("false\n");
}

int NumberOfDigits(int num) // This function return the number of digits the number (input) has.
{
	int count = 0;
	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return count;
}

int ReversedNum(int num)
{
	int index, newnum = 0, i;
	index = NumberOfDigits(num);
	for (i = 1; i <= index; i++)
	{
		newnum += (num % 10) * pow(10, (index - i));
		num /= 10;
	}
	return newnum;
}
bool isPolindromic(int num)
{
	if (num == ReversedNum(num))
		return true;
	else
		return false;
}

