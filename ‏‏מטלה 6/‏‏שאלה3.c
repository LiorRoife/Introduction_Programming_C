// שאלה3.c
// Name: Lior Roife
// ID: 206257826
// 09/01/20

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* str_last(char* str1, char* str2);  // This function gets as input two strings
										 // The function returns an address of the index where the appearance of str2 starts in str1.

int strleng(char s[]);                    //This function returns the length of a string.

void main()
{
	char s1[200];
	char s2[200];
	char* result;

	scanf("%s %s", s1, s2);
	result = str_last(s1, s2);

	if (result != NULL)
		printf("%s\n", str_last(s1, s2));
	else
		printf("%s could not be found in %s", s2, s1);
}

char* str_last(char* str1, char* str2)
{
	int i = 0, j = 0, count = 0;
	char* appearAdd = NULL;;
	bool appear = false;
	if (str1 == str2)
		return str1;
	else
	{
		for (i; i < strleng(str1); i++)
		{
			if (str1[i] == str2[j])
			{
				count++;
				j++;
				if (count == strleng(str2))
				{
					appearAdd = str1 + (i - count + 1);
					appear = true;
					count = 0;
					j = 0;
				}
			}
			else
				j = 0;
		}
		if (appear)
			return appearAdd;
		else
			return NULL;
	}
}

int strleng(char s[])     //This function returns the length of a string.
{
	int count = 0;
	if (s[0] == '\0')
		return count;
	else
	{
		count = strleng(s + 1);
	}
	return count + 1;
}
