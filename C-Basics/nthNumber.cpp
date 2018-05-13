/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci()
nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	if (n <= 0)
		return -1;
	else
	{
		int  y, z, i, x;
		if (n == 0 || n == 1)
			return 0;
		else if (n == 2 || n == 3)
			return 1;
		else
		{
			i = 3;
			y = x = 1;
			while (i < n)
			{
				z = x + y;
				x = y;
				y = z;
				i++;
			}
			return y;
		}
	}
}

int nthPrime(int num)
{
	if (num <= 0)
		return -1;
	else
	{
		int i, j, k, c;
		k = 0;
		for (i = 2; k != num; i++)
		{
			c = 0;
			for (j = 2; j < i; j++)
			{
				if (i%j == 0)
				{
					c++;

				}

			}
			if (c == 0)
				k++;
		}
		return i - 1;
	}
}