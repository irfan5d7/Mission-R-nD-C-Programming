/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
#include<string.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int cmp(char *a, char *b)
{
	int ya = (a[6] - '0') * 1000 + (a[7] - '0') * 100 + (a[8] - '0') * 10 + (a[9] - '0');
	int yb = (a[6] - '0') * 1000 + (b[7] - '0') * 100 + (b[8] - '0') * 10 + (b[9] - '0');
	if (ya > yb)
		return 1;
	else if (ya < yb)
		return -1;
	else
	{
		int ma =(a[3] - '0') * 10 + (a[4] - '0');
		int mb = (b[3] - '0') * 10 + (b[4] - '0');
		if (ma > mb)
			return 1;
		else if (ma < mb)
			return  -1;
		else
		{
			int da = (a[0] - '0') * 10 + (a[1] - '0');
			int db = (b[0] - '0') * 10 + (b[1] - '0');
			if (da > db)
				return 1;
			else if (da < db)
				return -1;
			return 0;
		}
	}
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	if (A == NULL || B == NULL || ALen<0 || BLen<0)
		return NULL;
	else
	{
		int i,j,k,c;
		c= j = k = 0; 
		struct transaction *out = (struct transaction *)malloc(sizeof(struct transaction)*(ALen+BLen));
		while (c < (ALen + BLen) && (j < ALen && k < BLen))
		{
				i = cmp(A[j].date, B[k].date);
				if (i < 0)
				{
					out[c] = A[j];
					j++, c++;
				}
				else if (i > 0)
				{
					out[c] = B[k];
					c++, k++;
				}
				else
				{
					out[c] = A[j];
					c++, j++;
					out[c] = B[k];
					c++, k++;
				}

		}
		if (k < BLen)
		{
			for (i = k; i < BLen; i++, c++)
				out[c] = B[i];
		}
		if (j < BLen)
		{
			for (i = j; i < ALen; i++, c++)
				out[c] = A[i];
		}
		return out;
	}
}