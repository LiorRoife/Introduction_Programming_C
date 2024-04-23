// שאלה4ב.c
// Name: Lior Roife
// ID: 206257826
// 28/12/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void intToStr(unsigned int num, char s[]); // This function gets as input a Char array and a number and updates the array with the digits of the number.

int const maxSize = 128;

void main()
{
	unsigned int num;

	char* s = (char*)calloc(maxSize, sizeof(char));
	scanf("%d", &num);

	// You need to write this functions according to question.
	intToStr(num, s);
	printf("%s", s);
}

void intToStr(unsigned int num, char s[])
{
	int length;
	if (num == 0)
	{
		s[0] = '\0';
		return;
	}
	else
	{
		intToStr(num / 10, s);
		length = strlen(s);
		if (num < 10)
			s[length] = (char)('0' + num);
		else
			s[length] = (char)('0' + num % 10);
	}
}

