/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i, j=-1, c,k=0;
	for (k = 0; k < 2;k++
		)
	{
		for (i = 0; i < len - 1; i++)
		{
			if (Arr[i]>Arr[i + 1])
			{
				if (j == -1)
				{
					c = Arr[i];
					j = i;
				}
				else
				{
					Arr[j] = Arr[i + 1];
					Arr[i + 1] = c;
					k++;
				}
			}
		}
	}
	return NULL;
}