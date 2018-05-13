




/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == NULL || len <= 0 || (date[2] != '-'||date
		[5] != '-'))
		return NULL;
	int d, m, y;
	d = (date[0] - '0') * 10 + (date[1] - '0');
	m = (date[3] - '0') * 10 + (date[4] - '0');
	y = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	if ((m < 0 || m>12) || (m == 2 && d > 28) || (d < 0 && d>31))
		return NULL;
	else
	{
		int i,j, c = -1;
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < 11; j++)
			{
				if (Arr[i].date[j] != date[j])
					break;
			}
			if (j == 11)
				c = i;
    	}
		if (c == -1)
			return 0;
		else
			return (len-c-1);
	}
}