/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include<malloc.h>
int removeArrayDuplicates(int *Arr, int len)
{
	int i, j, k, c, a = 0;
	if (len <=1 )
		return -1;
	else
	{
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len-i-1; j++)
			{
				if (Arr[j]>Arr[j+1])
				{
					c = Arr[j];
					Arr[j] = Arr[j+1];
					Arr[j+1] = c;

				}
			}
		}
		c = len;
			for (i = 0; i<c; i++)
			{
				if (Arr[i] == Arr[i + 1])
				{
					for (j = i + 1; j < c; j++)
						Arr[j - 1] = Arr[j];
						Arr[c] = NULL;
						c--;
				}
			}
			len = c;
			for (i = 0; i < c; i++)
				Arr[i];

		return len+1;
	}
}
