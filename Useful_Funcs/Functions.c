#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void simpleSort(int arr[], int size);
int findMinPl(int arr[], int start, int end);
void swapInArr(int arr[], int pl1, int pl2);
void bubbleSort(int arr[], int size);
int linearSearch(int arr[], int size, int num);
int binarySearch(int arr[], int size, int num);
int countZeros(int arr[], int size);
void sortedMerge(int arr1[], int size1, int arr2[], int size2, int res[]);
void mergeSort(int data[], int size);
int moveNeg(int data[], int size);
void moveNegPos(int data[], int size);
int strlen(char s[]);
void strcpy(char dest[], char src[]);
void gradeSort(int data[], int size);


void main()
{

}

/*
הפונקציה עוברת על הכל המערך ובכל פעם מוצאת את הערך המינימלי ומכניסה אותו להיות הבא במערך החדש
O(size^2)
*/
void simpleSort(int arr[], int size)
	int i, pl;
	for (i = 0; i < size; i + 1)
	{
		pl = findMinPl(arr, i, size - 1);
		swapInArr(arr, i, pl);
	}
}

/*
פונקציה שמקבלת מערך ו2 קצוות ומחפשת את המקום של הערך הקטן ביותר
O(size)
*/
int findMinPl(int arr[], int start, int end)
{
	//START - מאיפה להתחיל לחפש
	//END - איפה לסיים את החיפוש

	int minVal;	// הערך הקטן ביותר שמצאנו
	int minPl; //המקום של הערך הקטן ביותר שמצאנו
	int i; //אינדקס

	minVal = arr[start];//ניגש לכתובת המערך במקום סטארט 
	minPl = start;
	for (i = start + 1; i <= end; i++)
	{
		if (arr[i] < minVal)
		{
			minVal = arr[i];
			minPl = i;
		}
	}
	return (minPl);
}

/*
 פונקציה שמחליפה בין ערכים במערך
 O(1)
*/
void swapInArr(int arr[], int pl1, int pl2)
{
	int save;
	save = arr[pl1];
	arr[pl1] = arr[pl2];
	arr[pl2] = save;
}
/*
במיון זה עוברים על המערך שוב ושוב, ובכל פעם משווים שני
ערכים סמוכים ואם הם מסודרים לא נכון (כלומר הגדול נמצא
לפני הקטן) – נחליף ביניהם. בכל מעבר לפחות ערך אחד מגיע
למקומו הנכון.
O(size^2)
*/
void bubbleSort(int arr[], int size) 
{
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = size - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
				swapInArr(arr, j - 1, j);
		}
	}
}

/*
הפונקציה תבדוק אם הערך השמור ב נאמ נמצא במערך אם כן, הפונקציה תחזיר את האינדקס המתאים. אם לא, הפונקציה תחזיר -1
O(size)
*/
int linearSearch(int arr[], int size, int num) // ôåð÷öéä î÷áìú îòøê ,âåãìå åîñôø åîçæéøä îé÷åí äîñôø áîòøê àå 1 àí äîñôø ìà ÷ééí áîòøê.
{                                              // ñãø âåãì ùì size
	int i;
	for (i = 0; i < size; i++);
	{
		if (arr[i] == num)
			return i;
	}
	return -1;
}

/*
הפונקציה תבדוק אם הערך השמור ב נאמ נמצא במערך. אם כן הפונקציה תחזיר את האינדקס המתאים. אם לא, הפונקציה תחזיר -1.
נניח תמיד שהמערך ממוין מהקטן לגדול.
בכל פעם "נחצה" את המערך ל2, ונבין באיזה חלק של המערך המספר שאנו מחפשים ונתמקד בו.
O(log(Size))
*/
int binarySearch(int arr[], int size, int num) 
{                                             
	int start, end; //תחום המקומות במערך שבו אנו מחפשים
	int mid; //אמצע תחום החיפוש
	//initialization
	start = 0;
	end = size - 1;
	//Number Search
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == num)
		{
			return (mid);
		}
		else if (arr[mid] < num)
		{
			start = mid + 1;//אם היינו כותבים סטארט = מיד וגם אנד = מיד היינו נתקעים בלולאה אין סופית
		}
		else //arr[mid]>num
		{
			end = mid - 1;
		}
	}
	// No number found start>end
	return (-1);
}

/*
מתאים למערכים ממוינים בהם יש רק הרבה איברים בעלי אותו ערך (כלומר הרבה 0 והרבה 1, לדוגמא)
ואנחנו רוצים למצוא מתי מתחילים / נגמרים איברים בעלי ערך מסויים, או כמה איברים בעלי אותו ערך קיימים במערך
במקרה זה נבצע חיפוש בינארי למקום בו יש ספרה אחת ואחרי ספרה שונה
וכך נוכל לספור כמה איברים בעלי אותה ספרה יש לנו במערך
O(log(size))
*/
int countZeros(int arr[], int size)
{
	int start, end, mid;
	if (arr[0] == 1)
	{
		return 0;
	}
	if (arr[0] == 1) //full of 1s
	{
		return 0;
	}
	if (arr[size - 1 == 0])//full of 0s
	{
		return size;
	}
	//size>=2
	//initialize variables
	start = 0;
	end = size - 2; //מחפשים מקום שבו יש 0 ואחרי 1 בין סטארט ל אנד. לא נגלוש מחוץ למערך
	//search
	while (start <= end)
	{
		mid = (start - end) / 2;
		if (arr[mid] == 1)//צריך לחפש 0 במקומות קטנים מ מיד
			end = mid - 1;
		else //arr[mid]=0
		{
			if (arr[mid + 1] == 1)
				return(mid + 1);
			else //arr[mid]=0 arr[mid+1]=0
				start = mid + 1;
		}
	}
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
ניקח שני מערכים ממוינם ונמזג אותם למערך ממוין אחד
O(size1+size2)
*/
void sortedMerge(int arr1[], int size1, int arr2[], int size2, int res[])  
{
	int read1 = 0; // המקום הבא לקריאה מתוך המערך הראשון
	int read2 = 0; //המקום הבא לקריאה מתוך המערך השני
	int write = 0; //המקום הבא לכתיבה בתוך מערך התוצאה  - רס

	while ((read1 < size1) && (read2 < size2))//כל עוד יש איבר במערך הראשון וגם במערך השני
	{
		if (arr1[read1] <= arr2[read2])
		{//Copy a variable from arr1
			res[write] = arr1[read1];//another option: res[write++]=arr1[read1++]
			write++;
			read1++;
		}
		else //arr[read1]>arr2[read2]
		{//Copy a variable from arr2
			res[write] = arr2[read2];
			write++;
			read2++;
		}
	}
	while (read1 < size1)
	{//Copy the end of arr1
		res[write] = arr1[read1];
		write++;
		read1++;
	}
	while (read2 < size2)
	{//Copy the end of arr2
		res[write] = arr2[read2];
		read2++;
		write++;
	}
}

/*
הפונקציה משנה את סדר שמירת הנתונים במערך, כך
שכל המספרים השליליים יופיעו בתחילת המערך. אין צורך
לשמור את הערכים האי-שליליים. הפונקציה תחזיר את גודלו
הלוגי החדש של המערך.
O(size)
*/
int moveNeg(int data[], int size)
{
	int read; //Next place to read
	int write; //Next place to write. logical size
	for (read = 0, write = 0; read < size; read++)
	{
		if (data[read] < 0)
		{
			data[write] = data[read];
			write++;
		}
	}
	return write;
}

/*
הפונקציה משנה את סדר שמירת הנתונים במערך,
כך שכל המספרים השליליים יופיעו בתחילת המערך והערכים האי- שליליים בסופן
הסדר הפנימי (בין השליליים או בין האי-שלילים) איננו חשוב
O(size)
*/
void moveNegPos(int data[], int size)
{
	int start = 0; //Looking for the next non negative place
	int end = size - 1; //Looking for the next negative place

	while (start < end)
	{
		while ((start < size) && (data[start] < 0))//נשים קודם את התנאי הראשון כי לא נרצה שתהיה גלישהץ אם התנאי הראשון לא מתקיים, התנאי השני אפילו לא יבדקץ אם היה הפוך, יכלה להיות גלישה
		{
			start++;
		}
		while ((end >= 0) && data[end] >= 0)
		{
			end--;
		}
		if (start < end)
			swapInArr(data, start, end);
	}
}

/*
חישוב אורך של מחרוזת לא כולל תו סיום
('\0')
*/
int strlen(char s[])
{
	int count = 0;
	while (s[count] != '\0')
		count++;
	return count;
}

/*
העתקת מחרוזת מקור למחרוזת יעד
*/
void strcpy(char dest[], char src[])
{
	int ind;
	ind = 0;
	while (src[ind] != '\0')
	{
		dest[ind] = src[ind];
		ind++;
	}
	dest[ind] = '\0';
}

/*
שרשור מחרוזת מקור עם מחרוזת יעד
*/
void strcat(char dest[], char src[])
{
	int readInd;
	int writeInd;

	writeInd = strlen(dest) - 1;
	readInd = 0;

	while (src[readInd] != '\0')
	{
		dest[writeInd] = src[readInd];
		writeInd++;
		readInd++;
	}
	dest[writeInd] = '\0';
}

/*
השוואה לקסיקוגרפית של שתי מחרוזות
*/
int strcmp(char s1[], char s2p[])
{
	int i = 0;
	while ((s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*
יותר יעיל ממיון בועות אבל תופס יותר זיכרון
מקבלים מערך של נתונים מספריים שלמים של ציונים, כלומר טווח הנתונים הוא בין 0 ל100
ככה נוכל לבצע מיון עם סדר גודל קטן יותר ממיון בועות וכו
נאתחל מערך של מונים כך שכל איבריו יהיו 0
נעבור על המערך שקיבלנו ונספור כמה פעמים מופיעה כל ספרה ונכתוב על המערך החדש
כלומר אם מצאנו שבמקום מסויים מופיע המספר 10, נעלה את הערך של האינדקס 10 במערך החדש שיצרנו
לאחר מכן נעבור על המערך שקיבלנו ונכתוב אותו בצורה הזאת:
אם מצאנו ש 1 מופיע פעמיים, נכתוב 1,1 בשני המקומות הראשונים במערך, אחר כך נכתוב את 2 לפי כמות הפעמים שהוא מופיע וכו
*/
void gradeSort(int data[], int size)
{
	int i, j;//loops index
	int write;//the next writing place
	int counts[1 + MAX_GRADE];//array of counters
	for (i = 0; i <= MAX_GRADE; i++)//put 0 in all counters
	{
		counts[i] = 0;
	}
	//read all the info and count into the counters array how many times it appears
	for (i = 0; i < size; i++)
	{
		counts[data[i]]++;//נניח שהערך של דאטא במקום 1 הוא 10, אז הערך של קאונטס במקום 10 יגדל ב1
	}
	//write again all the grades into data array in a sorted way
	write = 0;
	for (i = 0; i <= MAX_GRADE; i++)
	{
		//write grade i
		for (j = 0; j < counts[i]; j++)
		{
			data[write] = i;
			write++;
		}
	}

	void mergeSort(int data[], int size)
	{
		int temp; // מצביע למערך שמוקצה דינאמית
		int i; //אינדקס
		if (size == 1)
			return;//אין צורך לסדר את המערך
		else//אם במערך יש יותר מאיבר אחד
			mergeSort(data, size / 2);// מיון החצי הראשון של המערך. אחרי הפקודה הזו, יהיו 2 חצאי מערך ממוינים
		mergeSort(data + size / 2, size - size / 2);//מיון החצי השני של המערך
			//מיזוג המערכים
			temp = (int*)malloc(size * sizeof(int));//הגדרת מערך זמני למיזוג
			sortedmerge(data, size / 2, data + size / 2, size - size / 2, temp);
			for ( i = 0; i < size; i++)//הנתונים צריכים לחזוק בתוך המערך שקיבלנו (דאטא) אז נעתיק אותם חזרה אליו ואז נשחרר אותו
			{
				data[i] = temp[i];
			}
			free(temp);
	}
