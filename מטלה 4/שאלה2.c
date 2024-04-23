// שאלה2.c
// Name: Lior Roife
// ID: 206257826
// 18/12/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool isDecreasingSequence(int num);  // This function get as input a number and outputs 'true' if the digits of the number (left to right) sorted in a Decreasing Sequence and 'false if not.
									 // One digit numbers considered as "DecreasingSequence" numbers.
void main()
{
	int num;
	bool result;

	scanf("%d", &num);

	// you need to implement this function according to the question
	result = isDecreasingSequence(num);
	printf("%s", result ? "true" : "false");
}

bool isDecreasingSequence(int num)
{
	int  Firstdig, Seconddig;
	Firstdig = num % 10;
	Seconddig = (num / 10) % 10;
	if (num < 10)
		return true;
	if (Seconddig > Firstdig)
		return (isDecreasingSequence(num / 10));
	return false;
}