/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};


struct node * numberToLinkedList(int N) {
	struct node *head = (struct node*)malloc(sizeof(struct node));
	if (N == 0)
	{
		head->num = N;
		head->next = NULL;
	}
	else
	{

		if (N < 0)
			N = -N;
		int i, l;
		i = l = 0;
		int *ar = (int *)malloc(sizeof(int) * 10);
		while (N != 0)
		{
			ar[i] = N % 10;
			N = N / 10;
			i++;
		}
		l = i-1;
		i = 0;
		struct node *temp;
		head = NULL;
		while (i<=l)
		{
			temp = (struct node*)malloc(sizeof(struct node));
			temp->num = ar[i];
			if (head == NULL)
			{
				head = temp;
				head->next = NULL;
			}
			else
			{ 
				temp->next = head;
				head = temp;
			}
			i++;
		}
	}
	
	return head;
}