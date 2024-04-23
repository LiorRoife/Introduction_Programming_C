// שאלה5.c
// Name: Lior Roife
// ID: 206257826
// 09/01/20

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




struct cell
{
	int val;
	int place;
};

typedef struct cell CELL;

CELL* findRuling(int nums[], int size, int* resSizePtr);  // This function gets as input an array of numbers, it's size and a pointer to integer.
                                                          // The function builds and returns a new CELLS's array that contain all the "ruling" numbers from the input array.
                                                          // A number considered "a ruling numner" must be bigger than all the numbers left to it in the original array.

bool isMax(int n[], int index);                           // This function gets as input an int array and and index/size
                                                          // The function returns true if the number in the index is bigger than all the numbers left to it and false if not.

void main()
{
	int* arr;
	int size, i;
	int resSizePtr = 0;
	CELL* rulingArr;

	scanf("%d", &size);
	arr = (int*)malloc(size * sizeof(int));

	for (i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	rulingArr = findRuling(arr, size, &resSizePtr);

	if (resSizePtr == 0)
		printf("NULL");
	else
	{
		for (i = 0; i < resSizePtr; i++)
		{
			printf("%d ", rulingArr[i].val);
			printf("%d ", rulingArr[i].place);
		}
	}
}

CELL* findRuling(int nums[], int size, int* resSizePtr)
{
	int i, c = 0, count = 0;
	CELL* newarr = NULL;;

	for (i = 0; i < size; i++)
	{
		if (isMax(nums, i + 1))
			count++;

	}
	if (count == 0)
		return NULL;
	newarr = (CELL*)malloc(count * sizeof(CELL));
	for (i = 1; i < size; i++)
	{
		if (isMax(nums, i))
		{
			newarr[c].val = nums[i];
			newarr[c].place = i;
			c++;
		}
	}
	*resSizePtr = count;
	return newarr;

}

bool isMax(int n[], int index)
{
	int i;
	int counter = 0;

	for (i = 0; i < index; i++)
	{
		if (n[i] < n[index])
		{
			counter++;
		}
	}
	if (counter == index)
	{
		return true;
	}
	return false;
}