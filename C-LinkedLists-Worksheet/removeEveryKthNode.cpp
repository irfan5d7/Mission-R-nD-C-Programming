/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (head == NULL || K <= 1)
		return NULL;
	else
	{
		int i = 1,l,j;
		struct node *prev, *temp;
		temp = head;
		while (temp->next != NULL)
		{
			i++;
			temp = temp->next;
		}
		l = i;
		if (K > l)
			return head;
		i = j = 0;
		temp = head;
		prev = temp;
		while (j<l)
		{
			i = 0;
			while (i != K - 1)
			{
				prev = temp;
				temp = temp->next;
				i++;
				j++;
			}
			if (j <= l-1)
			{
				prev->next = temp->next;
				prev = prev->next;
				temp = prev;
			}
			else
			{
				prev->next = NULL;
				break;
			}
			j++;
		}
		for (temp = head; temp != NULL; temp = temp->next)
			temp->num;
		return head;
	}
}