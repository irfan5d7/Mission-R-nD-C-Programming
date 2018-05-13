
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include<malloc.h>
int* nPrime(int N)
{
	if (N <= 0)
		return NULL;
	else
	{
		int i, j, c, l = 0;
		int	*p = (int*)malloc(N*sizeof(int));
		int *r;
		if (N <= 0)
			return NULL;
		else
		{
			for (i = 2; i <= N; i++)
			{
				c = 0;
				for (j = 2; j <= i; j++)
				{
					if (i%j==0)
					c++;
				}
				if (c == 1)
				{
					p[l] = i;
					l++;
				}
			}
			int *r = (int*)malloc(l*sizeof(int));
			for (i = 0; i < l; i++)
				r[i] = p[i];
			return r;
		}
	}
}