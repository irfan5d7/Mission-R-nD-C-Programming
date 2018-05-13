/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>

void and(char *s1, char *s2, char *out,int l)
{
	int i = 0;
	while (i<l)
	{
		if (s1[i] == s2[i] && s1[i] == '1')
			out[i] = '1';
		else
			out[i] = '0';
		i++;
	}
}
void or(char *s1, char *s2, char *out,int l)
{
	int i = 0;
	while (i<l)
	{
		if (s1[i] == s2[i] && s1[i] == '0')
			out[i] = '0';
		else
			out[i] = '1';
		i++;
	}
}
void nor(char *s1, char *s2, char *out,int l)
{
	int i = 0;
	while (i<l)
	{
		if (s1[i] == '0'&&s2[i] == '0')
			out[i] = '1';
		else
			out[i] = '0';
		i++;
	}
}
void xor(char *s1, char *s2, char *out,int l)
{
	int i = 0;
	while (i<l)
	{
		if (s1[i] == s2[i])
			out[i] = '0';
		else
			out[i] = '1';
		i++;
	}
}

char *performOperation(char *str1, char *str2, char *operation){
	
	int l1, l2,l,i,j;
	l1 = l2 = 0;
	while (str1[l1] != '\0') 
		l1++;
	while (str2[l2] != '\0') 
		l2++;
		if (l1 >= l2)
		l = l1;
	else
		l = l2;
	char *s = (char*)malloc(sizeof(char)*l);
	for (i = 0; i < l; i++)
		s[i] = '0';

	if (l1 > l2 && l2!=0){
			for (i = l2-1,j=l-1; i >= 0; i--,j--)
			{
				s[j] = str2[i];
			}
	}
	else if (l1<l2 && l1!=0){
			for (i = l1-1,j=l-1; i >= 0; i--,j--)
			{
				s[j] = str1[i];
			}
	}
	char *out = (char *)malloc(sizeof(char)*l+1);
	if (operation[0] == 'A')
	{
		if (l1 == l2) { and(str1, str2, out,l); }
		else if (l>l2){ and(str1, s, out,l); }
		else if (l>l1) and(s, str2, out,l);
	}
	else if (operation[0] == 'O')
	{
		if (l1 == l2) { or(str1, str2, out,l); }
		else if (l>l2){ or(str1, s, out,l); }
		else if (l>l1) or(s, str2, out,l);
	}
	else if (operation[0] == 'N')
	{
		if (l1 == l2) { nor(str1, str2, out,l); }
		else if (l1>l2){ nor(str1, s, out,l); }
		else if (l2>l1) nor(s, str2, out,l);
	}
	else if (operation[0] == 'X')
	{
		if(l1 == l2) { xor(str1, str2, out,l); }
	else if (l>l2){ xor(str1, s, out,l); }
	else if (l>l1) xor(s, str2, out,l);
	}
	out[l] = '\0';
	return out;
}








