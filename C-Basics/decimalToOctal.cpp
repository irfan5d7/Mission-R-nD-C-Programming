/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>

int decimalToOctal(int num)
{
	if (num < 0)
		return 0;
	else
	{
		int m, o, r;
		if (num < 7)
			return num;
		else
		{
			m = 1;
			o = 0;
			while (num > 0)
			{
				r = num % 8;
				num = num / 8;
				r *= m;
				o += r;
				m = m * 10;
			}
			return o;
		}
	}
}

float decimalToOctalFraction(float num)
{
	return 0.0;
}

