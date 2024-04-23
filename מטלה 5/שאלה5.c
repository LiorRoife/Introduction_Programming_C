// שאלה5.c
// Name: Lior Roife
// ID: 206257826
// 28/12/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<stdbool.h>


int ScanArray(int arr2[], int size, int num);// This function gets as input an array, it's size, and a number.
											 // The function checks if the number is in the array and returns the index if yes, else it returns -1.

int swapInArr(int arr[], int place1, int place2); //function to swap places of values between 2 arrays.

bool haveSameElems(int arr1[], int arr2[], int size); //This function gets as input 2 arrays and their size.
													  //The function returns true if the arrays have the same elements and false if not.
void main()
{
	int size;

	scanf("%d", &size);
	int* arr1 = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr1[i]);
	}
	int* arr2 = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr2[i]);
	}

	// You need to write this function according to question.
	bool ans = haveSameElems(arr1, arr2, size);

	printf("%s", ans ? "true" : "false");
}

bool haveSameElems(int arr1[], int arr2[], int size)
{
	int ScanArray2;
	//simple case - if only 2 elements in the array, and they are equal return True.
	if (size <= 1 && arr1[0] == arr2[0])
		return true;
	else
	{
		//scans array 1 last cell with all of array 2 cells, if it finds
		//equal values, it swaps them to be in the most right place of array 2
		//if no equal values are found it returns false.
		ScanArray2 = ScanArray(arr2, size, arr1[size - 1]);
		if (ScanArray2 == -1)
			return false;
		else
		{
			swapInArr(arr2, size - 1, ScanArray2);
			haveSameElems(arr1, arr2, size - 1);
		}
	}
}
int swapInArr(int arr[], int place1, int place2)
{
	int temp = 0;
	temp = arr[place1];
	arr[place1] = arr[place2];
	arr[place2] = temp;
}
int ScanArray(int arr2[], int size, int num)
{
	for (int i = 0; i < size; i++)
		if (arr2[i] == num)
			return i;
	return -1;
}