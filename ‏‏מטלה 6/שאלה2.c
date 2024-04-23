// שאלה2.c
// Name: Lior Roife
// ID: 206257826
// 09/01/20

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSymetric(int* arr, int size);  // This recursive function gets as niput an array, it's size,.
									  // The function returns true if the array is Polindrom.
									  //The function returns false if its not Polindrom.
void main()
{
	int* arr;
	int size, i;
	bool result;

	scanf("%d", &size);
	arr = (int*)calloc(size, sizeof(int));

	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	result = isSymetric(arr, size);
	printf("%s", result ? "true" : "false");
}

bool isSymetric(int* arr, int size)
{
	if (size <= 1)
		return true;
	else
	{
		if (arr[0] != arr[size - 1])
			return false;
		size--;
		return isSymetric(arr + 1, size - 1);
	}
}