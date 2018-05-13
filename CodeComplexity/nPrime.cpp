/*

Here you will be doing the same ArraysQuestion you did before, but now in multiple ways.

OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]
INPUTS: An Integer N
OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)
ERROR CASES: Return NULL for invalid inputs
Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}

Observations: (Write down what you observed here):

Way 1 :

Way 2 :

Way 3:

Conclusion :
*/

#include <stdio.h>
#include<malloc.h>
#include <math.h>


/*

Manually loop over every element, Find if its prime or not. Store it in an array.
Write the worst complexity code you can write :D.
*/
int* nPrimeBruteForce(int N)
{
	int i, j, k=0,c=0;
	int *out = (int *)malloc(sizeof(int)*N);
	for (i =2 ; i <= N; i++)
	{
		c = 0;
		for (j = 2; j <= i;j++)
			if (i%j == 0)
			{
				c++;
			}
		if (c <= 1)
			out[k] = i, k++;
	}
	return out;
}


/*
Remove even numbers, Run it again.
Just remove even numbers. So it should essentially take half of time for function 1, Did it really happened?

*/
int* nPrimeEvenRemoved(int N)
{
	int i, j, k = 0, c = 0;
	int *out = (int *)malloc(sizeof(int)*N);
	out[k] = 2;
	k++;
	for (i = 3; i <= N; i = i + 2)
	{
		c = 0;
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				c++;
				break;
			}
			}
			if (c == 0)
			{
				out[k] = i;
				k++;
			}
	}
	return out;
}

/*
Do all optimizations you can think of.

Hint : 
A number can be considered a prime, if its not divisible by any of the primes which are less than it.
ie 100 can be considered as a prime, if no prime number which is less than 100 divides 100 (With remainder as 0).
7 is prime as no prime less than it (2,3,5) can divide it. Think proof for this too.

This heavily reduces the number of divisions you do. If you did correctly you should see some heavy difference in timings.

*/
int* nPrimeOptimized(int N)
{
	int i, j;
	int *out = (int *)malloc(sizeof(int)*N);
	int *check = (int *)malloc(sizeof(int)*(N + 1));
		for (i = 2; i <= N; i++)
			check[i] = 1;
		for (i = 2; i <= N; i++)
		{
			if (check[i])
			{
				for (j = i; i*j <= N; j ++)
					check[i*j] = 0;
			}
		}
		j = 0;
		for (i = 2; i <= N; i++)
		{
			if (check[i])
			{
				out[j] = i;
				j++;
			}
		}
		return out;
}