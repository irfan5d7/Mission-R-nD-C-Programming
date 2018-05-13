/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
1		1
1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2);

int check_path(int *maze, int rows, int columns, int x1, int y1,int x2, int y2,int x,int y)
{
	int a;
	if (x == x2&& y == y2)
	{
		return 1;
	}
	else
	{
		x = x1 - 1, y = y1;
		if (x >= 0 && y >= 0 && x < rows&& y < columns)
		{
			if (maze[(x*columns) + y] == 1)
			{
				maze[(x1*columns) + y1] = 0;
				x1 = x;
				y1 = y;
				a = check_path(maze, rows, columns, x1, y1, x2, y2, x, y);
				maze[((x1 + 1)*columns) + y1] = 1;
				if (a == 1)
					return a;
			}
		}
		x = x1, y = y1-1;
		if (x >= 0 && y >= 0 && x < rows&& y < columns)
		{
			if (maze[(x*columns) + y] == 1)
			{
				maze[(x1*columns) + y1] = 0;
				x1 = x;
				y1 = y;
				a = check_path(maze, rows, columns, x1, y1, x2, y2, x, y);
				maze[(x1*columns) + (y1 + 1)] = 1;
				if (a == 1)
					return a;
			}
		}
		x = x1, y = y1+1;
		if (x >= 0 && y >= 0 && x < rows&& y < columns)
		{
			if (maze[(x*columns) + y] == 1)
			{
				maze[(x1*columns) + y1] = 0;
				x1 = x;
				y1 = y;
				a = check_path(maze, rows, columns, x1, y1, x2, y2, x, y);
				maze[(x1*columns) + (y1 - 1)] = 1;
				if (a == 1)
					return a;
			}
		}
		x = x1 + 1, y = y1;
		if (x >= 0 && y >= 0 && x < rows&& y < columns)
		{
			if (maze[(x*columns) + y] == 1)
			{
				maze[(x1*columns) + y1] = 0;
				x1 = x;
				y1 = y;
				a = check_path(maze, rows, columns, x1, y1, x2, y2, x, y);
				maze[((x1 - 1)*columns) + y1] = 1;
				if (a == 1)
					return a;
			}
		}
		return 0;
	}
}

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows <= 0 || columns <= 0 || x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || x1 >= rows || x2 >= rows || y1 >= columns || y2 >= columns)
		return 0;
	else if (maze[(x1*columns) + y1] == 0 || maze[(x2*columns) + y2] == 0)
		return 0;
	else if (x1 == x2&&y1 == y2)
		return 1;
	int res = check_path(maze, rows, columns, x1, y1, x2, y2,x1,y1);
	return res;
}
