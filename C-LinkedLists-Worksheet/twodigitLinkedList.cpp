/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>
#include<math.h>

struct twoDigitNode {
	int digit1;
	int digit2;
	struct twoDigitNode *next;
};

int convert_sll_2digit_to_int(struct twoDigitNode *head){
	struct twoDigitNode *temp;
	int l = 1, s = 0,r;
	for (temp = head; temp->next != NULL; temp = temp->next)
	{
		l++;
	}
	l = l * 2;
	for (temp = head; temp != NULL; temp = temp->next)
	{
		r = pow(10.0, l - 1);
		s = s + (temp->digit1)*r;
		l--;
		r = pow(10.0, l - 1);
		s = s + (temp->digit2)*r;
		l--;
	}

	return s;
}
