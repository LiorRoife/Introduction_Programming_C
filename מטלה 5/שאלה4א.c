// שאלה4א.c
// Name: Lior Roife
// ID: 206257826
// 28/12/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

void minMax(int arr[], int left, int right, int* min, int* max);

void main() // This function gets as input a pointer to a start of an array, two integers (left, right) and two pointers to min and max values of the array values.
{
	int min = 0, max = 0, size, left, right;

	scanf("%d", &left);
	scanf("%d", &right);
	scanf("%d", &size);
	int* arr = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		scanf("%d ", &arr[i]);
	}

	// You need to write this functions according to question.
	minMax(arr, left, right, &min, &max);
	printf("%d ", min);
	printf("%d ", max);
}

void minMax(int arr[], int left, int right, int* min, int* max)
{
	if (right == left)
	{
		*min = arr[right];
		*max = arr[right];
		return;
	}
	else
	{
		minMax(arr, left, right - 1, &*min, &*max);
		if (right > 0)
		{
			if (arr[right] > arr[right - 1])
			{
				if (arr[right] > * max)
					*max = arr[right];
				if (arr[right - 1] < *min)
					*min = arr[right - 1];
				return;
			}
			else
			{
				if (arr[right] < *min)
					*min = arr[right];
				if (arr[right - 1] > * max)
					*max = arr[right - 1];
				return;
			}
		}
		return;
	}
}