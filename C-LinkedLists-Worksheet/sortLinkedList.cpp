/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	struct node *temp, *inode, *jnode;
	temp = (struct node*)malloc(sizeof(struct node));
	for (inode = head; inode != NULL; inode = inode->next)
	{
		for (jnode = inode->next; jnode != NULL; jnode = jnode->next)
		{
			if (inode->num > jnode->num)
			{
				temp->num = inode->num;
				inode->num = jnode->num;
				jnode->num = temp->num;
			}
		}
	}
	for (temp = head; temp != NULL; temp = temp->next)
		temp->num;
	return head;

}