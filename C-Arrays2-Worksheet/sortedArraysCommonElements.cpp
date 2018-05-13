/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: 
A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL || B==NULL ||ALen<0||BLen<0)
	return NULL;
	else
	{
		int i, j, k, l,p,c=0,u;
		struct transaction *out;
		if (ALen > BLen)
			k = ALen, l = BLen;
		else
			k = BLen, l = ALen;
		out = (struct transaction *)malloc(sizeof(struct transaction)*l);
		for (i = 0; i < l; i++)
		{
			for (j = 0; j < k; j++)
			{
				u = 0;
				for (p = 0; p < 10; p++)
				{
					if (A[j].date[p] == B[i].date[p])
						u++;
				}
				if (u == 10)
				{
					out[c] = B[i];
					c++;
				}

			}
			
		}
		if (c == 0)
			return NULL;
		else
			return out;

	}
}
