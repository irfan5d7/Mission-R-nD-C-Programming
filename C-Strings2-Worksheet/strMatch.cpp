/*
ProblemCode : STRMATCH
Marks : 10
Difficulty :Easy.

A String(which only has small case a-z letters) is said to be corrupted if some of the charecters are removed and replaced by the number of characters removed .
Like : apple can be converted into a3e (ppl removed), or a4 (pple removed),ap2e (pl removed) .

helloworld can be modified as hello5 , h9 , 9d , etc , There is no limit on the number of characters that can be removed , or number of different times they can be
removed .

Some more examples are ,abcdefghijkl can be modified as a2d2g4l , a10l .
If 2 or more numbers occured consecutively , you should consider them as a whole , like a23re , is not a "2Chars removed" "3Chars Removed" re ,
it is a "23 Chars removed" re .

Your Task is , Given two corrupted Strings , you need to find whether a common word can be formed from those both corrupted strings
, If Yes ,return 1 , If no word can formed return 0 , -1 For invalid inputs .

Ex Input : s1= "a3e" and s2="4e" , Example Output : 1 .

This is because , apple word can be formed from both .

Ex Input 2 : s1= "k2e2f" and s2="k1fr3" , Returns 0 . No common word can be formed from those both Strings .
Ex Input 3: "5e3" and "abcdeej2" returns 1 , where as if s1 is 5e3i and s2 is abcdeekoll returns 0

Constraints :
A String will only have letters from "a-z and 0-9" ;
0<=Len Of Str1,Str2 <=10000
Numbers occuring in the String can be anything from 1 till 999 .

You can implement the helper functions ,if you want ,Although its optional .Dont worry about space for this question .

Note : Only 25% of Cases ,will have numbers >9 in the Strings .
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int add(char *str, int *indx)
{
	int i, r, s;
	r = s = 0;
	i = *indx;
	if (str[i + 2] >= '0' && str[i + 2] <= '9' && str[i + 1] >= '0' && str[i + 1] <= '9')
		r = 100;
	else if (str[i + 1] >= '0' && str[i + 1] <= '9')
		r = 10;
	else
		r = 1;
	while (r != 0)
	{
		s = s + (str[i]-48) * r;
		r = r / 10;
		i++;
	}
	*indx = i;
	return s;
}
int isSTRMatched(char *str1, char *str2){

	if (str1 == NULL || str2 == NULL || (str1[0] == '\0'&&str2[0] == '\0'))
		return 1;
	else
	{
		int i, j, l1, l2, r;
		i = j = l1 = l2 = 0;
		char *s1 = (char *)malloc(sizeof(char) * 10000);
		char *s2 = (char *)malloc(sizeof(char) * 10000);
		while (str1[i] != '\0')
		{
			if (str1[i] >= 'a' && str1[i] <= 'z')
			{
				s1[j] = str1[i];
				i++, j++;
			}
			else
			{
				l1 = add(str1, &i);
				while (l1 != 0)
				{
					s1[j] = '*';
					j++;
					l1--;
				}
			}
		}
		s1[j] = '\0';
		l1 = j;
		i = j = 0;
		while (str2[i] != '\0')
		{
			if (str2[i] >= 'a' && str2[i] <= 'z')
			{
				s2[j] = str2[i];
				i++, j++;
			}
			else
			{
				l2 = add(str2, &i);
				while (l2 != 0)
				{
					s2[j] = '*';
					j++;
					l2--;
				}
			}
		}
		s2[j] = '\0';
		l2 = j;
		if (l1 != l2)
			return 0;
		else
		{
			i = 0;
			while (s1[1]!='\0')
			{
				if (s1[i] != '*'&& s2[i] != '*')
				{
					if (s1[i] != s2[i])
						return 0;
					else
						return 1;
				}
				i++;
			}
			return 1;

		}

	}
}

