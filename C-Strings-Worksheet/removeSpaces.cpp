/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {
	if (str == '\0')
	return '\0';
	else
	{
		int i, j,k;
		for (i = 0;str[i]!='\0' ; i++)
		{
			for (j = 0; str[j] != '\0'; j++)
			{
				if (str[j] == ' ')
				{
					for (k = j;  str[k]!='\0'; k++)
						str[k] = str[k + 1];
				}
			}
		}
		for (i = 0;i<20;i++)
		str[i];
		return *str;
	}
}