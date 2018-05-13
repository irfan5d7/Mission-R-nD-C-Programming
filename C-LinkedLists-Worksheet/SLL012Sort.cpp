/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){

}

/*
This is the actual function. You are supposed to change only the links.
*/
void sll_012_sort(struct node **head){
	struct node *t1,*t2,*prev1,*prev2,*temp,*next;
	prev1 = prev2 = temp = t1 = t2 = next = *head;
	int i = 0;
	for (t1 = *head; t1!= NULL; t1 = t1->next)
	{
		prev2 = t1;
		for (t2 =t1->next; t2 != NULL; t2 = t2->next)
		{
			if (t1->data > t2->data)
			{
				if (i != 0)
					prev1->next = t2;
				prev2->next = t1;
				if (t2->next == NULL)
				{
					t2->next = t1->next;
					t1->next = NULL;
				}
				else{
					next = t2->next;
					t2->next = t1->next;
					t1->next = next;
				}
				temp = t1;
				t1 = t2;
				t2 = temp;
				if (i == 0)
					*head = t1;
			}
			prev2 = t2;
		}
		i++;
		prev1 = t1;
		
	}


}

