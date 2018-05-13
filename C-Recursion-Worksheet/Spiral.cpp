/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void spiral_rec(int **arr,int *spir,int rows,int cols,int nlen,int i,int j,int indx,int br,int bc,int flag)
{
	if (indx >= nlen)
		return;
	else
	{
		if (j < cols && i == br &&  flag == 1)
		{
			spir[indx] = arr[i][j];
			indx++;
			spiral_rec(arr, spir, rows, cols, nlen, i, j + 1, indx, br, bc,flag);
		}
		else if (j == cols && i < rows)
		{
			flag = 0;
			if (i == br)
				i++;
			spir[indx] = arr[i][j-1];
			indx++;
			spiral_rec(arr, spir, rows, cols, nlen, i + 1, j, indx, br, bc,flag);
		}
		else if (i == rows && j > bc)
		{
			if (j == cols)
				j = j - 2;
			spir[indx] = arr[i - 1][j];
			indx++;
			spiral_rec(arr, spir, rows, cols, nlen, i, j-1, indx, br, bc,flag);
		}
		else if (i <= rows && i > br &&j == bc)
		{
			if (i == rows)
				i--;
			spir[indx] = arr[i][j];
			indx++;
			spiral_rec(arr, spir, rows, cols, nlen, i-1, j, indx, br, bc,flag);
		}
		else if (j == bc && i == br)
		{
			rows--;
			cols--;
			bc++;
			br++;
			j = bc;
			i = br;
			flag = 1;
			spiral_rec(arr, spir, rows, cols, nlen, i, j, indx, br, bc,flag);
		}

	}
}

int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0 || input_array == NULL)
		return NULL;
	else
	{
		int *spir = (int *)malloc(sizeof(int)*(rows*columns));
		spiral_rec(input_array, spir, rows, columns, rows*columns, 0, 0, 0,0,0,1);
		for (int i = 0; i < rows*columns; i++)
			spir[i];
		return spir;
	}
}
