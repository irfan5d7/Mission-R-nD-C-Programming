/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1)

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input, int length)
{
	int temp = 0, i, j = 0;
	for (i = 0; i < length; i++)
	{
		if (input[i] < 0)
		{
			temp++;
		}
		if (input[i] >= 0)
		{
			j++;
		}
	}
	if (j == 0 || temp == 0)
		return 0;
	else
	{
		for (i = 0; i < length; i++)
		{
			for (j = i + 1; j < length; j++)
			{
				if (input[i]>input[j])
				{
					temp = input[i];
					input[i] = input[j];
					input[j] = temp;

				}
			}
		}
		for (i = 0; i < length; i++)
		{
			if (input[i] >= 0)
			{
				break;
			}
		}
		temp = input[i - 1] + input[length - 1];
		return temp;
	}
}