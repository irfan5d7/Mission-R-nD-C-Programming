/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int *ap(int *ar, int begin, int len)
{
	int i=begin,c=0;
	int *ret = (int *)malloc(sizeof(int) * 2);
	while (i < len - 1)
	{
		if ((ar[i + 1] - ar[i]) == (ar[i + 2] - ar[i + 1]))
		{
			if (c == 0)
			{
				ret[0] = i, c++;
			}
			i++;
		}
		else if ((ar[i + 1] - ar[i]) != (ar[i + 2] - ar[i + 1]) && (c != 0))
		{
			ret[1] = i + 1;
			break;
		}
		else
			i++;
	}
	return ret;
}
int *gp(int *ar, int begin, int len)
{
	int i = begin, c = 0;
	int *ret = (int *)malloc(sizeof(int) * 2);
	while (i < len - 1)
	{
		if ((float(ar[i + 1]) / float(ar[i])) == (float(ar[i + 2]) / float(ar[i + 1])))
		{
			if (c == 0)
				ret[0] = i, c++;
			i++;
		}
		else if ((float(ar[i + 1]) / float(ar[i])) != (float(ar[i + 2]) / float(ar[i + 1])) && c != 0)
		{
			ret[1] = i + 1;
			break;
		}
		else
			i++;
	}
	return ret;
}
int * find_sequences(int *arr, int len){
	if (arr==NULL ||len<=0)
	return NULL;
	else
	{
		int *out = (int*)malloc(sizeof(int) * 6);
		int *r,begin;
		r = ap(arr, 0, len);
		out[0] = r[0];
		out[1] = r[1];
		free(r);
		r = ap(arr, out[1], len);
		out[2] = r[0];
		out[3] = r[1];
		free(r);
		r = gp(arr, 0, len);
		out[4] = r[0];
		out[5] = r[1];
		return out;
	}
}