// שאלה2א.c
// Name: Lior Roife
// ID: 206257826
// 28/12/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void removeOdd(int arr[], int* size);
void printArr(int arr[], int size);
void main()
{
	int size, i;
	int* arr;

	scanf("%d", &size);
	arr = (int*)malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	removeOdd(arr, &size);
	printArr(arr, size);
	printf("%d ", size);
}

void removeOdd(int arr[], int* size) // This function gets an array and a pointer to the size of the array.
									 //  The function removes all the odd numbers from the array and changes the size to the new array's size.
{
	int i, write = 0;
	for (i = 0; i < *size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			arr[write] = arr[i];
			write++;
		}
	}
	*size = write;
}

void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}