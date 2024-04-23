// שאלה4.c
// Name: Lior Roife
// ID: 206257826
// 09/01/20

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* findNelements(int n);                // This function gets as input an index (n);
										  // The function builds and returns a new array size of n that contains the seria numbers (i+arr[i]) while i<n.



void main()
{
	int n, i;
	int* arr;

	scanf("%d", &n);
	arr = findNelements(n);

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

int* findNelements(int n)
{
	int i;
	int* newarr;
	newarr = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		if (i == 0)
			newarr[0] = 1;
		else
			newarr[i] = i + newarr[i - 1];
	}
	return newarr;
}