/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<math.h>

void number_to_str(float number, char *str, int afterdecimal){
	int i = 0, n;
	int a = floor(log10(abs(number))) + 1;
	if (number < 0)
	{
		number = -number;
		a++;
		str[0] = '-';
	}
	n = number;
	i = a - 1;
	while (n != 0)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	i = a;
	if (afterdecimal == 0)
	{
		str[i] = '\0';
	}
	else
	{
		str[i] = '.';
		i++;
		a = 0;
		while (a < afterdecimal)
		{
		n = number = number * 10;
			str[i] = (n % 10) + 48;
			i++;
			a++;
		}
		str[i] = '\0';
	}
}