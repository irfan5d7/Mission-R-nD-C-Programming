/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>
#include<string.h>
char * get_last_word(char * str){
	if (str == NULL)
		return NULL;
	else
	{
		int i,l,s,k;
		l = s = k = 0;
		while (str[l] != '\0')
		{
			l++;
			if (str[l] == ' ')
				s=l;
		}
		if (s != 0)
			s++;
		char *out = (char *)malloc(sizeof(char)*(l - s + 1));
		for (i = s; i < l; i++,k++)
			out[k] = str[i];
		out[k] = '\0';
		return out;
	}
}
