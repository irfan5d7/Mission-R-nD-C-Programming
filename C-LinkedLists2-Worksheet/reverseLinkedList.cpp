/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	else
		if (head->next == NULL)
			return head;
		else
		{
			struct node *temp, *prev, *next;
			temp = prev = next = head;
			temp = temp->next;
			next = temp->next;
			head->next = NULL;
			while (temp->next != NULL)
			{
				temp->next = prev;
				prev = temp;
				temp = next;
				next = next->next;
			}
			temp->next = prev;
			head = temp;
			for (temp = head; temp != NULL;temp=temp->next)
				temp->num;
			return head;
		}
}
