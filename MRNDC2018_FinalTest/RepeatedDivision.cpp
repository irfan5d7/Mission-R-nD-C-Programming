/*

problemCode : RepeatedDivision
score : 10

Repeated 2 Division.

Given a Number N, your task is to find a number in the range [1,N]
such that the number is most divisible reptedly by 2

Example :
N = 6

x   -    DivisibleCount
1   -    0
2   -    1
3   -    0
4   -    2
5   -    0
6   -    1

Hence the answer is 4 since it can be repetedly divisible 2 times.

CONSTRAINTS : 
	1 <= N < 2^32

*/


int RepeatedDivision(int N){
	if (N == 1)
	return 0;
	int i = 0,n;
	n = N;
	while (n >1)
	{
		n = n / 2;
		i++;
	}
	n = 1;
	while (i != 0)
	{
		n = n * 2;
		i--;
	}
	return n;
}

