// שאלה3.c
// Name: Lior Roife
// ID: 206257826
// 18/12/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool isEven(int num, int dig); // This function gets as input a number and a digit.
							   // The function outputs 'true' if the number has even appearances of the digit and 'false' if not.
void main()
{
	int num, dig;
	bool result;

	scanf("%d%d", &num, &dig);

	// you need to implement this function according to the question
	result = isEven(num, dig);
	printf("%s", result ? "true" : "false");
}

bool isEven(int num, int dig)
{
	// Base case, single digit
	// If num % 10 == dig on this last digit, we've got 1 match (odd, so return false)
	bool result;
	if (num < 10)
		if (num % 10 != dig)
			return true;
	result = isEven(num / 10, dig);
	if (num % 10 == dig) // This digit matches, count one more/flip the result
		result = !result;
	return result;
}