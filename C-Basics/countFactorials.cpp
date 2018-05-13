/*Problem - To find the number of factorials in a given range.
Description - You will be given an input array[l, h] which gives the range.Your job is to return the count of the number of factorials between 'l' and 'h' both included.

Example: input = [2, 10]
		 The factorails between 2 and 10 is '2' alone.Hence 1 must be returned.


Constraints :
1) The range should not be negative, i.e neither of l and h should be negative.If so, return -1.
2) l, h are both long integers.
3) The range should be non decreasing, i.e l <= h.It is not, return -1.

DONT CHANGE THE FUNCTION HEADERS.



*/

#include <stdio.h>

int fac(long n);
int countFactorials(long l, long h)
{
	if (l < 0 || l>h)
		return -1;
	if (l == h)
		return 1;
	else
	{
		int c = 0, i = 1, r;
		while (1)
		{
			r = fac(i);
			if (r > h)
				break;
			if (r >= l && r <= h)
			{
				c++;
			}
			i++;
		}
		return c;
	}
}


int fac(long n)
{
	long i;
	if (n == 1 || n == 0)
		return 1;
	else
	{
		i = n - 1;
		while (i>=1)
		{
			n = n*i;
			i--;
		}
		return n;
	}
}
