/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(long int num)
{
	if (num < 0)
		return 0;
	if (num < 8)
		return num;
	else
	{
		int b = 1, s = 0,r;
		while (num != 0)
		{
			r = num % 10;
			s = s + (r*b);
			b = b * 8;
			num = num / 10;
		}
		num = s;
		s = 0;
		b = 1;
		while (num != 0)
		{
			r = num % 16;
			s = s + (r*b);
			b = b * 10;
			num = num / 16;
		}
		return s;
	}
}

float octalToHexadecimalFraction(float num)
{
	return 0.0;
}