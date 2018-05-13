#include"Header.h"
#include"dynamicstruct.h"
int char_to_int(char *s, int n);
void csr(char *arr, char *tmp, int *k, int *i);
void typescount(char *types, int *inc, int *cc, int *fc);
int stcmp(char *s1, char *s2);
int substr(char *str, char *search);
int char_to_int(char *s, int n)
{
	int i, r, m;
	r = 0; m = 1;
	for (i = n - 1; i >= 0; i--)
	{
		r = r + (s[i] - '0')*m;
		m = m * 10;
	}
	return r;
}
void csr(char *arr, char *tmp, int *k, int *i)
{
	while (arr[*i] != ',' && arr[*i] != '\n' && arr[*i] != '\0')
	{
		tmp[*k] = arr[*i];
		(*k)++; (*i)++;
	}
	tmp[(*k)] = '\0';
	return tmp;
}
void typescount(char *types, int *inc, int *cc, int *fc)
{
	int i, k;
	char tmpar[100];
	i = 0;
	while (types[i] != '\0')
	{
		k = 0;
		while (types[i] != ' ' && types[i] != '\0')
		{
			tmpar[k++] = types[i++];
		}
		tmpar[k] = '\0';
		if (stcmp(tmpar, "int"))
		{
			(*inc)++;
		}
		else if (stcmp(tmpar, "string"))
		{
			(*cc)++;
		}
		else if (stcmp(tmpar, "float"))
		{
			(*fc)++;
		}
		if (types[i] == ' ')
			i++;
	}
}
int stcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return 0;
		i++;
	}
	if ((s1[i] == '\0' && s2[i] == '\0') || ((s1[i] == ' ' && s2[i] == ' ')))
		return 1;
	else
		return 0;
}
int substr(char *str, char *search)
{
	int count1 = 0, count2 = 0, i, j, flag;
	while (str[count1] != '\0')
		count1++;
	while (search[count2] != '\0')
		count2++;
	for (i = 0; i <= count1 - count2; i++)
	{
		for (j = i; j < i + count2; j++)
		{
			flag = 1;
			if (str[j] != search[j - i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	if (flag)
		return 1;
	else
		return 0;
}