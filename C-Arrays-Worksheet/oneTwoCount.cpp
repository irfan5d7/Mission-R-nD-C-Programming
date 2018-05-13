
/*
OVERVIEW: Given an Integer Array return the count of one's and two's in a new array of length two.
Ex: input: [1,2,2,1,2,1,2]
output: [3,4]
where 3 is the count of 1's and 4 is the count of 2's

INPUTS: An Integer Array and length of the array

OUTPUT: An Array with 1's count and 2's count

ERROR CASES: Return NULL for invalid inputs

Difficulty : Very Easy
*/

#include <stdio.h>
#include<malloc.h>
int* oneTwoCount(int* input, int length)
{
	int i,c=0;
	int* a = (int*)malloc(2 * sizeof(int));
	a[0] = 0, a[1] = 0;
	if (length > 0 && input != NULL)
	{
			for (i = 0; i < length; i++)
			{
				if (input[i] == 1)
					a[0] = a[0] + 1;
				if (input[i]==2)
					a[1] = a[1] + 1;
			}
			return a;
	}
	else
		return NULL;
}
