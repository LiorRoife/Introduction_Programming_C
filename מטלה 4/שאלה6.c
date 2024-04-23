// שאלה6.c
// Name: Lior Roife
// ID: 206257826
// 18/12/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>


void printPrimeFactors(int num);   // This function gets as input a number and outputs all of his Prime factors.

int main()
{
	int number;
	scanf("%d", &number);
	printPrimeFactors(number);
	return 0;
}

void printPrimeFactors(int num)
{
	int i = 2;
	if (num < 2)
		return;
	if (num == 2)
		printf("2 ");
	while (num % i != 0)
		i++;
	printf("%d ", i);
	printPrimeFactors(num / i);
}

