/*
Problem Code :NWAR

There is a war going among numbers ,on who should be considered as a Leader and finally they have reached a conclusion .
For those numbers when breaked into digits and Individual squares are added ,and if the sum is not 1 ,the process is repeated for the sum and so on.
When doing this if any any time ,Sum reaches 1 , that number can be called as Leader Number , other wise not .

Ex: 1000 => (1^2 + 0^2 + 0^2 + 0^2) ==> 1 .1000 is a leader number
Ex: 44 => (16+16) => 32 => (9+4) ==> 13 => (1+9) ==> 10 ==> (1+0) ==> 1. 44 is a leader number .
Ex: 67 => (36+49) ==> 85 => By Doing Dividing and Squaring and Summing we get this series
89 => 145 => 42 => 20 => 4 => 16 => 37 => 58 => 89 , As 89 is already generated No matter how many times we do this process We can never reach 1 .So its not a leader Element .

Given an Array of Numbers ,You need to return the array of Leader Elements .You should also copy the Number of Leader Elements Found in *leadersArraLen variable .
Order should be maintained in the Result Array .

Ex Input : [

Constraints :
0<= A[i]< 1000000
0<len<10000

Note : Returns Array Length will not be greater than 10001 . And If the leader number occured 2 or more times in the original array include those many times in answer
Note : Return NULL for Invalid Inputs
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int check(int *ar, int a, int l)
{
	int i;
	for (i = 0; i < l; i++)
	{
		if (ar[i] == a)
			return 1;
	}
	return 0;
}


int war(int n)
{
	if (n == 0)
		return 0;
	else
	{
		int r, s, k, i;
		s = k = i = 0;
		int *aar = (int *)malloc(sizeof(int) * 100);
		aar[i] = n;
		i++;
		while (s != 1 && k != 1)
		{
			while (n != 0)
			{
				r = n % 10;
				s = s + (r*r);
				n = n / 10;
			}
			k = check(aar,s, i + 1);
			if (k == 0)
			{
				aar[i] = s;
				n = s;
				s = 0;
				i++;
			}
		}
		if (s == 1)
			return 1;
		else
			return 0;
	}
}

int* getSquareLeaderArray(int *arr, int len, int *leadersArrayLen){
	if (arr == NULL || len <=0)
	return NULL;
	else
	{
		int *out = (int*)malloc(sizeof(int)*len);
		int i, j, k;
		j = 0;
		for (i = 0; i < len; i++)
		{
			k = war(arr[i]);
			if (k == 1)
			{
				out[j] = arr[i];
				j++;
				(*leadersArrayLen)++;
			}
		}
		return out;
	}

}
