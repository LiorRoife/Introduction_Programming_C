// שאלה6.c
// Name: Lior Roife
// ID: 206257826
// 28/12/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool subsetSum(int arr[], int size, int sum); // This function gets as niput an array, it's size, a number (sum).
											  // The function returns true if any sum of 2 values from the array equal to the number.
											   //The function returns false if there is not two numbers that their sum equal to the number.
void main()
{
	int size, sum;
	scanf("%d", &sum);
	scanf("%d", &size);
	int* arr = (int*)calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	// You need to write this function according to question.
	bool result = subsetSum(arr, size, sum);

	printf("%s", result ? "true" : "false");
}

bool subsetSum(int arr[], int size, int sum)
{
	if (sum == 0)
		return true;
	if (sum != 0 && size == 0)
		return false;
	if (arr[size - 1] > sum)   //checks if the number is bigger then the sum, if not,it later subtracts it
		return subsetSum(arr, size - 1, sum);
	return subsetSum(arr, size - 1, sum) || subsetSum(arr, size - 1, sum - arr[size - 1]); 	//cuts the last number in the array and subtract it from the sum.

}
