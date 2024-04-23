// שאלה1.c
// Name: Lior Roife
// ID: 206257826
// 09/01/20

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_COLS 256
#define MAX_ROWS 100

bool isPalindrome(char s[]);        // This function gets as input a string, checks if it'd Palindrome. returns true if it is, false if not.

void switchLetters(char s[]);       // This function gets as input a string, swaps between every 2 following letters.
									// If the (size%2 != 0) the function won't change the last letter.

void removeChar(char s[], char ch); // This function gets as input a string and a char. 
									// The function removes every appearance of the char from the string and updates the string.

int strStr(char s1[], char s2[]);   // This function gets as input 2 strings, the function returns the index where s2  appears in s1.
									// The function will reeturn -1 if s1 not appear in s2.

int string2Integer(char s[]);       // This function gets as input a string and returns the number built from the string cells.


void swapInArr(char[], int pl1, int pl2); //This function gets as input a string and 2 indexes, the functions swaps between the values in the indexes.
int strleng(char s[]);                    // This function gets as input a string and returns its length.
void strcopy(char newstr[], char str[]);  // This function gets as input 2 string and 

void main()
{
	char Arr[MAX_ROWS][MAX_COLS];
	int lines = 0, res, i;
	bool emptyLine = false;
	do 	// Scans for input from the user until the input is an empty line.

	{
		gets(Arr[lines]);

		if (Arr[lines][0] == '\0')
			emptyLine = true;
		else
			lines++;

	} while (!emptyLine);

	removeChar(Arr[0], ' ');  // Remove spaces from the first line.

	if (!isPalindrome(Arr[1])) // checks if the second line of the array is Palindrome.
		switchLetters(Arr[1]); // If the line isn't Palindrome the program swaps between every 2 following cells in this array line.
	int thirdRow = string2Integer(Arr[2]); //Converts the third row of the array into a number.
	for (i = 3; i < lines; i++)	// Removes any rows from the third row and above that contains the string "new".
	{
		res = strStr(Arr[i], "new");
		if (res != -1)
		{
			for (int j = i + 1; j < lines; j++)
			{
				strcopy(Arr[j - 1], Arr[j]);
			}
			lines--;
			i--;
		}
	}
	printf("%d\n", thirdRow);	//Prints the 3rd row of the array, then the rest of the rows.
	while (lines > 0)
	{
		printf("%s\n", Arr[lines - 1]);
		lines--;
	}
}

bool isPalindrome(char s[])
{
	int i = 0, count = 0, length;
	length = strleng(s);
	if (length == 1)
		return true;
	for (i; i < length; i++)
	{
		if (s[i] == s[length - 1 - i])
			count++;
	}
	if (count == (length - 1 / 2)) // Count = the number of times the function found two equal numbers in simeetric indexes.
		return true;
	else
		return false;
}

void switchLetters(char s[])
{
	int length, i = 0;
	length = strleng(s);
	if (length % 2 == 0)  // If the length is even, run "length" iterations.
		for (i; i <= length; i += 2)
			swapInArr(s, i, i + 1);
	else                  // If the length is odd, run "length-1" iterations.
		for (i; i < length - 1; i += 2)
			swapInArr(s, i, i + 1);
}

void removeChar(char s[], char ch)
{
	int  j = 0, i = 0;
	int length = strleng(s);
	for (i; i < length; i++)
	{
		if (s[i] != ch)
		{
			s[j] = s[i];
			j++;
		}
	}
	s[j] = '\0';
}

int strStr(char s1[], char s2[])
{
	int i = 0, j = 0, count = 0;
	if (s1 == s2)
		return 0;  // If the strings are equal, the function returns the index 0.
	else
	{
		for (i; i < strleng(s1); i++)
		{
			if (s1[i] == s2[j])
			{
				count++;
				j++;
				if (count == strleng(s2)) // The function found appearance of s2 in s1.
					return  i - count + 1;
			}
			else
			{
				count = 0;
				j = 0;
			}
		}
	}
	return -1;
}

int string2Integer(char s[])
{
	int i = 0, value = 0;
	int length = strleng(s);
	for (i = length - 1; i >= 0; i--)
	{
		value += (s[i] - '0') * pow(10, length - 1 - i);
	}
	return value;
}

void swapInArr(char arr[], int pl1, int pl2)  // This function gets as input a string and 2 indexes.
{
	int save;
	save = arr[pl1];
	arr[pl1] = arr[pl2];
	arr[pl2] = save;
}

int strleng(char s[])     //This function returns the length of a string.
{
	int count = 0;
	while (s[count] != '\0')
		count++;
	return count;
}

void strcopy(char newstr[], char str[])
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
}