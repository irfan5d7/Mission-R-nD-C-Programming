/*

Bharath is genius reverse engineer, invented a world demanding machine and Kept in a secret building with many doors with each door having a passkey.
A Pass key is made up of some digits. Like a passkey can be 1234, 452 etc.
All doors will have passkeys of same digits, (formed from each other). like if number of doors are 3, 1223,2132,2321 can be passkeys for those doors.
(Where as 3321 cannot as 3 is repeated 2 times where as in above sequence its repeated only 1 time)

Sam is very excited to see his wonderful creation. So, she went to the building. She knows the final passkey of last door but dont know
what is the exact passkey for each before door. As said before there are many doors with lock in a linear fashion such that
she can cross second door only after crossing first door. she can cross third door only after crossing 2nd door.

Lets say the final pass key she has is 758.
First door pass key is the largest number that can be formed by given final passkey -> 875
Second door pass key is the next largest number that can be formed -> 857
Third door opens for next largest number ->785
Finally fourth door has 758 as passkey and she can enter the room.

Find which Nth door's room contains the machine or How many doors should Sam cross to see the machine?

The final passkey Sam has will be given in the form of Doubly Linked List
eg: 7 <-> 5 <-> 8  o/p: 4

For the above Passkey ,output will be 4, as Sam needs to cross 4 doors which each door having below passkeys.
explanation: (1) 875 (2) 857 (3) 785 (4) 758

Ex 2 :
If DLL has 9 <-> 1 <-> 4 <-> 6.
For the above Passkey ,output will be 4, as Sam needs to cross 6 doors which each door having below passkeys.
explanation: (1) 9641 (2) 9614 (3) 9461 (4) 9416 (5) 9164 (6) 9146

NOTE:	(1)	DLL can contain maximum of 12 nodes
(2)	All doors will have a Passkey which is formed by the numbers of the original pass key only
(3) From the first door to last, passkey will be in decreasing order.
(4) Duplicates are allowed
(5) "075" is not treated as "75". 0 is also given same importance as others.

You can solve this question in multiple ways.
Can you solve it without converting to any intermediate forms or using extra space etc? These will be the common followup questions
that can be asked in an interview.

Return -1 for invalid cases.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int n)
{
	return (n <= 1) ? 1 : n * fact(n - 1);
}

int findBigger(char* str, int low, int high)
{
	int countRight = 0, i;

	for (i = low + 1; i <= high; ++i)
		if (str[i] >= str[low])
			++countRight;

	return countRight;
}

int findRank(char* str, int len)
{
	int mul = fact(len);
	int rank = 1;
	int count;
	int i;
	
	for (i = 0; i < len; ++i)
	{
		mul /= len - i;

		count = findBigger(str, i, len - 1);

		rank = rank + count * mul;
	}
	int *c = (int *)malloc(sizeof(int)*len);
	for (i = 0; i < len; i++)
		c[i] = 1;
	count = 1;
	for (i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (str[i] == str[j])
				c[i]++;
		}
	}
	for (i = 0; i < len; i++)
		c[i] = fact(c[i]);
	for (i = 1; i < len; i++)
		c[0] = c[0] * c[i];
	rank = rank / c[0];
	if (rank == 0)
		return 1;
	return rank;
}
struct passKeyNode
{
	int num;
	struct passKeyNode *prev;
	struct passKeyNode *next;
};

int doorstoCross(struct passKeyNode *passKeyHead)
{
	if (passKeyHead == NULL)
		return -1;
	struct passKeyNode *last, *temp;
	int i, l;
	for (last = passKeyHead, l = 0; last->next != NULL; last = last->next)
		l++;
	l++;
	char *key = (char *)malloc(sizeof(char)*l);
	for (i = 0, temp = passKeyHead; i < l; temp = temp->next, i++)
	{
		key[i] = temp->num + 48;
	}
	i = findRank(key, l);
	return i;
}