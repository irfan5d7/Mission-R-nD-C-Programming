/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (len < 0||Arr==NULL)
		return NULL;
	else
	{
		int i, j = 0, k;
		len = len + 1;
		int *a = (int *)malloc(len*sizeof(int));
		for (i = 0; i < len - 1; i++)
		{
			if (Arr[i] < num)
			{
				a[j] = Arr[i];
				j++;
				printf("%d\t", a[j]);
			}
			else
			{
				a[j] = num;
				j++;
				break;
			}
		}
		if (i != len - 1)
		{
			for (k = i; k < len; k++, j++)
				a[j] = Arr[k];
		}
		else{
			a[j] = num;
		}
		return a;
	}
}