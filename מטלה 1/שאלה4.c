// שאלה4.c
// Lior Roife	
// ID: 206257826
// 11/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
This program gets as input three number that equals to an octal (8 Base) number that build from this numbers and returns the Base 3 value of the number.
*/
void main()
{
	int firstnum, dig1, dig2, dig3, dig4, dig5, dig6, fonum, num10;
	printf("Please Enter Three Digits of a Number In Octal Base \n");
	scanf("%d %d %d", &dig1, &dig2, &dig3);
	dig2 = dig2 * 8;
	dig1 = dig1 * 8 * 8;
	num10 = dig1 + dig2 + dig3;
	//printf("The Decimal Value Of The Number: %d\n", num10);// // From 8Base To 10Base //
	dig6 = num10 % 3;
	dig5 = (num10 / 3) % 3;
	dig4 = ((num10 / 3) / 3) % 3;
	dig3 = (((num10 / 3) / 3) / 3) % 3;
	dig2 = ((((num10 / 3) / 3) / 3) / 3) % 3;
	dig1 = (((((num10 / 3) / 3) / 3) / 3) / 3) % 3;
	printf("The Value Of The Number In 3 Base is: ");
	printf("%d%d%d%d%d%d\n", dig1, dig2, dig3, dig4, dig5, dig6);
}