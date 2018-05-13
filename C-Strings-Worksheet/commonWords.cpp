/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include<string.h>
#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;
	else
	{
		char **r = (char **)malloc(sizeof(char)*SIZE);
		char s1[100][100], s2[100][100];
		int i, j, sp1, sp2;
		sp1 = sp2 = 0;
		for (i = 0; i < strlen(str1); i++)
		{
			if (str1[i] == ' ')
			{
				sp1++;
			}
		}
		if (sp1 == strlen(str1))
			return NULL;
		for (i = 0; i < strlen(str2); i++)
		{
			if (str2[i] == ' ')
			{
				sp2++;
			}
		}
		if (sp2 == strlen(str2))
			return NULL;
		int a, b;
		a = b = 0;
		for (i = 0; i < strlen(str1); i++)
		{
			if (str1[i] != ' ')
			{
				s1[a][b] = str1[i];
				b++;
			}
			else
			{
				s1[a][b] = '\0';
				a++;
				b = 0;
			}
		}
		s1[a][b] = '\0';

		a = 0;
		b = 0;
		for (i = 0; i < strlen(str2); i++)
		{
			if (str2[i] != ' ')
			{
				s2[a][b] = str2[i];
				b++;
			}
			else
			{
				s2[a][b] = '\0';
				a++;
				b = 0;
			}
		}
		s2[a][b] = '\0';
		int k = 0;
		for (i = 0; i <= sp1; i++)
		{
			for (j = 0; j <= sp2; j++)
			{
				if (strcmp(s1[i], s2[j]) == 0)
				{
					r[k] = s1[i];
					k++;
				}
			}
		}
		if (k == 0)
			return NULL;
		else
			return r;
	}
	}
