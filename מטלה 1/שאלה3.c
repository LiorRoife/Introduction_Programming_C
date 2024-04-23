// שאלה3.c
// Lior Roife	
// ID: 206257826
// 11/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
This program gets as input a number between 0-7 and returns the binary value of the number
*/
void main()
{
	int num, snum, tnum, fonum;
	const int firstnum = 0;
	printf("Please Enter a number between 0-7\n");
	scanf("%d", &num);
	fonum = num % 2;
	tnum = (num / 2) % 2;
	snum = ((num / 2) / 2) % 2;
	printf("The Binary Value of The Number is:\t");
	printf("%d%d%d%d\n", firstnum, snum, tnum, fonum);
}