/*

Given a matrix nxn and a starting point (p,q),
Output all the points in the matrix which are identical to the starting point in the fashion similar to magic tool in Adobe photoshop.
Eg:
(p,q) : (0,3)
1 2 3 3
3 2 3 3
5 3 3 3
4 5 1 4
o/p : [ (0,2) (0,3) (1,2) (1,3) (2,2) (2,3) (2,1) ]

Use 2 structures provided to solve the problem.

struct point -> contains x, y corresponding to point on matrix.
struct result -> contains 3 fields
1. selected -> contains all the final points after the selecting process.
2. size -> number of the selected points.
3. visited -> utility variable to note the visited points on matrix during recursion.

In error cases return a emply structures
size = 0;
selected = {};
visited = {};

NOTE : Donot use any Global Variables
*/
#include <malloc.h>

struct Point {
	int x;
	int y;
};


struct result {
	Point* selected;
	bool *visited;
	int size;
};


void select(char *pixels, int m, int n, struct Point pivot, int x, int y, result* res, int *i, int j, int u, int v, int w, char z) {
	if ((x >= 0 && x <= m &&y >= 0 && y <= n) && (j != x || u != y))
	{

		if (*(pixels + (x*(n + 1)) + y) == z)
		{
			if ((*i) != 0)
			{
				j = v;
				u = w;
			}
			v = x;
			w = y;
			res->selected[(*i)++] = { x, y };

			res->visited[x*n + y] = true;
			res->size = *i;

			select(pixels, m, n, pivot, x - 1, y, res, i, j, u, v, w, z);
			select(pixels, m, n, pivot, x, y + 1, res, i, j, u, v, w, z);
			select(pixels, m, n, pivot, x + 1, y, res, i, j, u, v, w, z);
			select(pixels, m, n, pivot, x, y - 1, res, i, j, u, v, w, z);
		}
	}
}

struct result select_wrapper(char* pixels, int m, int n, struct Point pivot) {
	result *res = (result*)malloc(sizeof(result));
	res->selected = (Point*)malloc((m + 1)*(n + 1)*sizeof(Point));
	res->visited = (bool*)malloc((m + 1)*(n + 1)*sizeof(bool));
	res->size = 0;
	int p = pivot.x; int q = pivot.y, i = 0;
	if (pixels =='\0')
		return *res;
	char d = *(pixels + ((pivot.x)*(n + 1)) + pivot.y);
	select(pixels, m, n, pivot, p, q, res, &i, -1, -1, 0, 0, d);
	return *res;
}
