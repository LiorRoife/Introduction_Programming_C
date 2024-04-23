//2שאלה.c
// Name: Lior Roife
// 17/11/19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/****************************************************************************************
The program gets as input a ddecimal number between -8 to 7 and outputs its binary value.
*****************************************************************************************/
const int fpnum = 0;
const int fnnum = 1;
void main()
{
	int num, snum, tnum, fonum;
	printf("Enter a number between minus Eight to Seven \n");
	scanf("%d", &num);
	if (num >= 0)                                 // if the num between 0 to 7
	{
		fonum = num % 2;
		tnum = (num / 2) % 2;
		snum = ((num / 2) / 2) % 2;
		printf("The Binary Value of The Number is:\t");
		printf("%d%d%d%d\n", fpnum, snum, tnum, fonum);
	}
	else                                          // if the num between -8 to -1
	{
		num += 8;                                 // שיטה לחשב ערך בינארי של מספרים שליליים - 4 סיביות ראשונות
		fonum = num % 2;
		tnum = (num / 2) % 2;
		snum = ((num / 2) / 2) % 2;
		printf("The Binary Value of The Number is:\t");
		printf("%d%d%d%d\n", fnnum, snum, tnum, fonum);
	}
}