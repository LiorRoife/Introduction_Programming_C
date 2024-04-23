// שאלה3.c
// Name: Lior Roife
// ID: 206257826
// 28/12/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int findChange(int arr[], int n);

// The function returns the any index where the number is Even and the following number is Odd
void main()
{
	int size, ans;
	scanf("%d", &size);
	int* arr = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	// You need to write this function according to question.
	ans = findChange(arr, size);
	printf("%d", ans);
}

int findChange(int arr[], int n) // This function gets as input an array and it's size.
								 // The function returns any index where the number is Even and the following number is Odd
								 // If there no such case the function will return.
{
	int start = 0, end = n - 1, mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if ((arr[mid] % 2 == 0) && (arr[mid + 1] % 2 != 0))
			return (mid);
		else if ((arr[mid] % 2 == 0) && (arr[mid + 1] % 2 == 0))
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (-1);
}