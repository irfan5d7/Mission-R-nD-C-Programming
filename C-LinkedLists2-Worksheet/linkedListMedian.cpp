/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	else
	{
		int i = 0,l=-1;
		struct node *temp;
		for (temp = head; temp != NULL; temp = temp->next)
			l++;
		for (temp = head; i != l / 2; temp = temp->next, i++){}
		if ((l+1) % 2 != 0)
			return temp->num;
		else
			return (temp->num + temp->next->num) /2 ;
	}
}
