/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int cmp(char *s, char* w, int i, int j)
{
	while (w[j] != '\0')
	{
		if (s[i] == w[j])
			i++, j++;
		else
			break;
	}
	if (w[j] == '\0')
		return 1;
	else
		return 0;
}


int count_word_in_str_way_1(char *str, char *word){
	if (str == NULL || word == NULL)
		return 0;
	else
	{
		int i, j, k,c;
		i = j = c = 0;
		while (str[i] != '\0')
		{
			j = 0;
			if (str[i] == word[j])
			{
				k = cmp(str, word, i, j);
				if (k == 1)
					c++;
				i++;
			}
			else
				i++;
		}
		return c;
	}
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	return 0;
}

