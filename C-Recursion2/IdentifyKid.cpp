/*

Problem Code: IdentifyKid

There are three types of Guys,
'A' - Ambitious Boy 
'B' - Brilliant Boy
'C' - Creative Boy

The first generation guy is 'A'
each guy will have 3 kids 'A','B','C' , but the order will be different

'A' children will be  A ,B, C
'B' children will be  B ,C, A
'C' children will be  C ,A, B    ( rotations of “ABC”)


So basically , if it was represented in the form of a tree


1st  Generation -	                                   A
Index -                                                1
                                 /                     |                   \
2nd Generation -	            A                      B                    C
Index -			                1                      2                    3
                           /    |    \            /    |    \           /   |   \
3rd Generation -          A     B     C          B     C     A         C    A    B
Index-                    1     2     3          4     5     6         7    8     9

Given the N,K which represents the Nth generation and Kth index
You need to identify the type of the kid present there.

Note : If there is No Guy present there, return '\0'

*/

#include<stdio.h>
#include<string.h>

char kid_rec(int n,int k)
{
	if (n == 1)
		return 'A';
	else
	{
		n--;
		char akids[4] = "ABC";
		char bkids[4] = "BCA";
		char ckids[4] = "CAB";
		int i;
		char r;
		if (k % 3 == 0)
		{
			i = 3;
			k = k / 3;
		}
		else
		{
			i = k % 3;
			k = k / 3;
			k++;
		}
		r = kid_rec(n, k);
		if (r == 'A')
			return akids[i - 1];
		if (r == 'B')
			return bkids[i - 1];
		if (r == 'C')
			return ckids[i - 1];
	}
}
char identifyKid(int N, int K) {
	if (N==0||K==0)
	return '\0';
	int i;
	double j=1;
	for (i = 0; i < N; i++)
	{
		j = j*3;
	}
	if (K > j)
		return '\0';
	else
	{
		return kid_rec(N, K);
	}
}