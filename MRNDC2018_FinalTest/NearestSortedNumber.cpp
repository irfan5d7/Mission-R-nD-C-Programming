/*
	problemCode : NearestSortedNumber
	score : 15

	A Sorted Number is a number in which all its digits are in non-decending order.
	for example "129" , "222", "345", "999" are all Sorted Numbers.
	Where as the numbers "110" , "1000", "143" are not Sorted Numbers.

	You are given an integer N in the form of a string.
	
	Your task is to find the the last Sorted Number in the range [1,N]

	Sorted Numbers = [1,2,3,4,5,6,7,8,9,  11,12,13,...19,  22,23,24,.... INF]

	Sample Cases : 
	N = 10, result = 9
	N = 12, result = 12
	N = 19, result = 19
	N = 21, result = 19

	Note : 
	1) if there is no answer or the input is invalid , return NULL
	2) Input consists of no leading zeros, and output should not consist of leading zeros
	returning "0002" instead of "2" is considered as a wrong answer.

	Constraints : 
	1 <= len <= 100000 (i.e 100000 digits not integer 100000)
*/


#include<stdio.h>
#include<malloc.h>
int cmp(int *arr, int len)
{
	int r = 0;
	for (int i = 1; i <= len - 1; i++)
	{
		if (arr[r] <= arr[i])
			r = i;
		else
		{
			return r;
		}
	}
	return r;

}
char * NearestSortedNumber(char *N, int len){
	if (N==NULL || len <1)
	return NULL;
	else
	{
		int *arr = (int *)malloc(sizeof(int)*len);
		int i;
		for(i = 0; i < len; i++)
		{
			if (N[i] >= 48 && N[i] <= 57)
			{
				arr[i] = N[i] - 48;
			}
			else
			{
				return NULL;
			}
		}
			int indx = cmp(arr, len);
			if (indx != len - 1)
			{
				arr[indx] = arr[indx] - 1;
				for (i = indx + 1; i < len; i++)
					arr[i] = 9;
			}
			int f = 0,j;
			char *ret = (char *)malloc(sizeof(char)*(len+1));
			for (i = 0,j=0; i < len; i++)
			{
				if (arr[i]  != 0 || f == 1)
				{
					ret[j] = arr[i] + 48;
					j++;
					f = 1;
				}
			}
			ret[j] = '\0';
			return ret;
	}
}

