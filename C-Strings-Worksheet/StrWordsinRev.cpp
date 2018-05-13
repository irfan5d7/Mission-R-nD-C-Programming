/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void rev(int s, int e, char *str){
	int i, j;
	char temp;
	for (i = s, j = e; i != j && i <= j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
int end(char *str, int b)
{
	int i = b;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	return i - 1;
}
void str_words_in_rev(char *input, int len){
	int j, k;
	strrev(input);
	j = 0;
	while (input[j] != '\0')
	{
		k = end(input, j);
		if (j == k)
			j = j + 2;
		else
		{
			rev(j, k, input);
			j = k + 1;
			while (input[j] == ' '&& input[j + 1] != '\0')
				j++;
		}
		
	}
}

