// שאלה1.c
// Name: Lior Roife
// ID: 206257826
// 18/12/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>


void RealDivisors(int n, int* NumOfDivs, int* SumOfDivs);  // This Function gets as input a number and two int pointers.
														   // The function returns(updates) the number of Real dividers the number has and their sum.

bool isPerfect(int n);                                     // This Function gets as input a number and returns 'true' if the number is perfect or 'false' if its not perfect.
														   // A number is perfect if it is equal to the sum of it's divisors.

bool isFriendly(int num1, int num2);         //This function checks if the sum of the divisors of num1 equal to num2, and
											 //if the sum of the divisors of num2 equal to num1. returns 'true' if yes and 'false' if not.
											 //Example: For the numbers 220 , 284 the function will return 'true'.
											 //because 1+2+4+5+10+11+20+22+44+55+110 =284 and 1+2+4+71+142 =220 .

void main()                                  //This program gets as input a number (M) and prints all the "Perfect" numbers and the "Friendly" pairs of numbers, between 2 to M.
{
	int M, countDivs, SumDivs, i;
	scanf("%d", &M);
	for (i = 2; i <= M; i++)
	{
		if (isPerfect(i))
			printf("%d ", i);
	}
	printf("\n");
	for (i = 2; i <= M; i++)
	{
		RealDivisors(i, &countDivs, &SumDivs);
		if (isFriendly(i, SumDivs) && i > SumDivs)
			printf("%d %d\n", SumDivs, i);
	}
}

void RealDivisors(int n, int* NumOfDivs, int* SumOfDivs)
{
	int  i, count = 0, sum = 0;
	for (i = 1; i < n / i; i++)
		if (n % i == 0)
		{
			if (n / i == n)
			{
				count++;
				sum += i;
			}
			else
			{
				count += 2;
				sum += i + n / i;
			}
		}
	*NumOfDivs = count;
	*SumOfDivs = sum;
}

bool isPerfect(int n)
{
	int sDivs, cDivs;
	RealDivisors(n, &cDivs, &sDivs);
	if (sDivs == n)
		return true;
	else
		return false;
}
bool isFriendly(int num1, int num2)
{
	int sDivs, cDivs, savesDivs1;
	RealDivisors(num1, &cDivs, &sDivs);
	savesDivs1 = sDivs;
	RealDivisors(num2, &cDivs, &sDivs);
	if (savesDivs1 == num2 && sDivs == num1)
		return true;
	else
		return false;
}