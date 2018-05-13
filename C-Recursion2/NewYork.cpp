/*

Problem Code : New York

Count the number of ways of reaching top left cell (0,0) to right bottom cell (n-1,m-1) of a 2d matrix.

You have to change the direction "exactly 'k' times", you can change to any direction top,down,left,right.

You can start with any direction (initially at (0,0) only right and down are possible).

For Example :
N = 3, m = 4 , k = 1
These are the two sequences , change in direction is indicated by *

(1,1) -->  (2,1) -->  (3,1) -->  (3,2)* -->  (3,3) --> (3,4)
(1,1) -->  (1,2) -->  (1,3) -->  (1,4) --> (2,4)* -->  (3,4)

N = 3, m = 4, k = 2

(1,1) --> (2,1) --> (2,2)* --> (2,3) -->  (2,4) -->  (3,4)*
(1,1) --> (1,2) -->  (2,2)* --> (3,2) -->  (3,3)* --> (3,4)
(1,1) --> (1,2) -->  (1,3) -->  (2,3)* -->  (3,3) -->  (3,4)*

Return 0 for invalid cases
*/

#include <stdio.h>
#include <stdlib.h>

void newyork_recr(int n, int m, int x, int y, int dd, int l, int *c, int dpr, int dprs)
{
	if (x >= 0 && y >= 0 && x < n && y < m)
	{
		if (dpr != dprs)
		{
			l++;
			dpr = dprs;
		}
		if (x == n - 1 && y == m - 1)
		{
			if (dd == l)
				(*c)++;
			else
				return;
		}
		if (dd >= l)
		{
			newyork_recr(n, m, x - 1, y, dd, l, c, dpr, 1);
			newyork_recr(n, m, x, y + 1, dd, l, c, dpr, 2);
			newyork_recr(n, m, x + 1, y, dd, l, c, dpr, 3);
			newyork_recr(n, m, x, y - 1, dd, l, c, dpr, 4);
		}
	}
}

int NewYork(int n, int m, int k){
	int dp = 0,c=0;
	newyork_recr(n, m, 0, 0, k, -1, &c, dp, 0);
	return c;
}