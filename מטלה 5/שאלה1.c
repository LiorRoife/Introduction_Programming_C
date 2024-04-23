// שאלה1.c
// Name: Lior Roife
// ID: 206257826
// 28/12/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 50   // Maximum Phisical Size of An Array.
const int EOD = -1;   // End Of Data


int readArray(int Array[]); // This function gets as input an array, fills it until the input is -1 and returns the array's size.

void iOfLongestDecreasingSeq(int Array[], int size); // This function gets as input an array and it's size.
													 // And prints the index of the longest Decreasing sequrnce in the array.

int main()
{
	int Arr[MAX_SIZE];
	int size;
	size = readArray(Arr);
	iOfLongestDecreasingSeq(Arr, size);
}

int readArray(int Array[])
{
	int size = 0, num;
	scanf("%d", &num);
	while ((num != EOD) && size < MAX_SIZE)
	{
		Array[size] = num;
		size++;
		scanf("%d", &num);
	}
	if (num != EOD)
		printf("Too many numbers, ignoring \n");
	return size;
}

void iOfLongestDecreasingSeq(int Array[], int size)
{
	int i, iOfLongest, curLen = 0, maxLen = 0;
	for (i = 1; i < size; i++)
	{
		if (Array[i - 1] >= Array[i])
			curLen++;
		else
			curLen = 0;
		if (curLen > maxLen)
		{
			maxLen = curLen;
			iOfLongest = i;
		}
	}
	printf("The longest Decreasing Sequence starts at place %d of the array", iOfLongest - maxLen);
}
