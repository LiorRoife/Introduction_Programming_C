// שאלה4.c
// Name: Lior Roife
// ID: 206257826
// 18/12/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>


int numWays(int n); // This function gets as input a number that reprecents the ladder Height.
					// The function outputs the number of ways its posible to reach the end of the ladder.

int main()
{
	int ladderHeight, waysNumber;
	scanf("%d", &ladderHeight);
	waysNumber = numWays(ladderHeight);
	printf("%d", waysNumber);
	return 0;
}

int numWays(int n)
{
	if (n < 4 && n >= 1)
		return n;
	else
		return(numWays(n - 1) + numWays(n - 2));
}