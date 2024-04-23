// שאלה3.c
// Name: Lior Roife
// 17/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/********************************************************************************************************************************
This program gets as input 4 numbers (m,n,a,b) and an operator , then it outputs the solution value as "SHEVER" and as "MAMASHI".
*********************************************************************************************************************************/
struct SHEVER                               // The Structure of "SHEVER" built from "mone" and "mehane".
{
	int mone;
	int mehane;
};
void main()
{
	struct SHEVER shever1, shever2;
	int m, n, a, b;
	char ch;
	printf("Please enter Four numbers and an Operator \n");
	scanf("%d %d %d %d %c", &m, &n, &a, &b, &ch);
	shever1.mone = m;
	shever1.mehane = n;
	shever2.mone = a;
	shever2.mehane = b;
	switch (ch)
	{
	case '+':
		printf("The Shever Solution Is: %d/%d \n ", shever1.mone * shever2.mehane + shever1.mehane * shever2.mone, shever1.mehane * shever2.mehane);
		printf("The Mamashi Solution Is %lf \n ", (double)shever1.mone / shever1.mehane + (double)shever2.mone / shever2.mehane);
		break;
	case '-':
		printf("The Shever Solution Is: %d/%d \n ", shever1.mone * shever2.mehane - shever1.mehane * shever2.mone, shever1.mehane * shever2.mehane);
		printf("The Mamashi Solution Is %lf \n ", (double)shever1.mone / shever1.mehane - (double)shever2.mone / shever2.mehane);
		break;
	case '*':
		printf("The Shever Solution Is: %d/%d \n ", shever1.mone * shever2.mone, shever1.mehane * shever2.mehane);
		printf("The Mamashi Solution Is %lf \n ", (double)shever1.mone / shever1.mehane * (double)shever2.mone / shever2.mehane);
		break;
	case '/':
		printf("The Shever Solution Is: %d/%d \n ", shever1.mone * shever2.mehane, shever1.mehane * shever2.mone);
		printf("The Mamashi Solution Is %lf \n ", ((double)shever1.mone / shever1.mehane) / ((double)shever2.mone / shever2.mehane));
		break;
	}
}