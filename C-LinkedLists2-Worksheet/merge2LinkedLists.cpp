/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	else
	{
		struct node *temp1, *temp2,*rhead,*rtemp;
		temp1 = head1;
		temp2 = head2;
		if (head1->num < head2->num) {
			temp1=head1->next;
			head1->next = NULL;
			rtemp = rhead = head1;
		}
		else
		{
			temp2 = head2->next;
			head2->next = NULL;
			rtemp = rhead = head2;
		}
		while (temp1 != NULL && temp2 != NULL)
		{
			if (temp1->num < temp2->num)
			{
				rtemp->next = temp1;
				rtemp = rtemp->next;
				temp1 = temp1->next;
				rtemp->next = NULL;
			}
			else
			{
				rtemp->next = temp2;
				rtemp = rtemp->next;
				temp2 = temp2->next;
				rtemp->next = NULL;
			}
		}
		while (temp2 != NULL)
		{
			rtemp->next = temp2;
			rtemp = rtemp->next;
			temp2 = temp2->next;
			rtemp->next = NULL;
		}
		while (temp1 != NULL)
		{
			rtemp->next = temp1;
			rtemp = rtemp->next;
			temp1 = temp1->next;
			rtemp->next = NULL;
		}

		return rhead;
	}
}
