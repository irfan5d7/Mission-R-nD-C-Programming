/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

void dateconvrt(struct node *head, int *d, int *m, int *y)
{
	(*d) = (*m) = (*y) = 0;
	struct node *temp = head;
	int r;
	r = 10;
	while (r != 0)
	{
		(*d) = (*d)+ temp->data*r;
		temp = temp->next;
		r = r / 10;
	}
	r = 10;
	while (r != 0)
	{
		(*m) = (*m)+temp->data*r;
		temp = temp->next;
		r = r / 10;
	}
	r = 1000;
	while (r != 0)
	{
		(*y) = (*y) + temp->data*r;
		temp = temp->next;
		r = r / 10;
	}

}
int daysCount(int *d, int *m, int *y)
{
	int days = 0,i;
	int *month = (int *)malloc(sizeof(int) *12);
	month[0] = month[2] = month[4] = month[6] = month[7] = month[9] = month[11] = 31;
	month[3] = month[5] = month[8] = month[10] = 30;
	month[1] = 28;
	for (i = 0; i < (*m)-1; i++)
		days = days + month[i];
	days = days + (*d);
	days = days + ceil(*y*365.2425);
	if (!((*m)>2 && ((*y) % 400 == 0 || ((*y) % 400 != 0 && (*y) % 100 != 0 && (*y) % 4 == 0))))
		days--;
	return days;
}
int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	else
	{
		int dd1, dd2, mm1, mm2, yy1, yy2;
		dateconvrt(date1head, &dd1, &mm1, &yy1);
		dateconvrt(date2head, &dd2, &mm2, &yy2);
		if (dd1 == dd2 && mm1 == mm2 && yy1 == yy2)
			return 0;
		int days1, days2;
		dd1, dd2, mm1, mm2, yy2, yy2;
		days1 = daysCount(&dd1, &mm1, &yy1);
		days2 = daysCount(&dd2, &mm2, &yy2);
		days1 = days2 - days1;
		if (days1 < 0)
			days1 = -days1;
		return days1-1;
	}
}