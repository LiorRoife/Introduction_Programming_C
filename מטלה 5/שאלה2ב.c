// שאלה2ב.c
// Name: Lior Roife
// ID: 206257826
// 28/12/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void splitParity(int arr[], int size);  // This function gets as input an array and it's size
										// The function sorts the array by puting it's even numbers in the beginning and odd in the end.
void printArr(int arr[], int size);
void swapInARR(int arr[], int place1, int place2);

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

	splitParity(arr, size);

	printArr(arr, size);
}

void splitParity(int arr[], int size)
{
	int i, write = 0, read = size - 1;
	for (i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			swapInARR(arr, i, write);
			write++;
		}
	}
}

void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

// This function gets as input an array and 2 places(indexes) in the array and swap between the numbers in the array according to the places.
void swapInARR(int arr[], int place1, int place2)
{
	int temp = 0;
	temp = arr[place1];
	arr[place1] = arr[place2];
	arr[place2] = temp;
}