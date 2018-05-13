/*
ProblemCode : ROPESTUDENTS
Difficulty : Medium
Marks : 20

The following story makes No Sense at all :D , But have fun reading it :D .

Once in MissionRnD School , large number of school students are practicing for a parade in a large playground .
All these students have a sir called Bharath who suggested that
they will go for a crazy pyramid Kind Formation ,where initially there will be one leaderStudent who will be tied up with 3 other students ,
These 3 students will each be tied up with 3 more students , and this goes on till all students are tied up .

Example : Let A be the leader student , He is tied up with {B,C,D} and B is tied up with {E,F,G} , C tied up with {H,I,J} , D tied up with {K,L,M} .
From E to M they are tied up with no further students .

Now they will play a game where leaderStudent will pass a ball to one of the students he got tied up with , Assume A passed the ball to either B,C, or D .[Let it be D]
Now D will can pass the ball to  either K,L, or M .Let let it be L . Now L cant pass the ball anymore further .So the ball can be in the hands of Max of 3 people [A,D,L]
before it is stopped . This is called as ****maxBallDistance ****. No matter whom A passes the ball first ,It reaches the end after making 2 passes ,ie total of 3 people
have holded the ball [including A]

Example Image Link : https://goo.gl/hjE5ec


Now students being restless ,some of them got bored , and escaped cutting of their Ropes . If a student has escaped ,All the following students who are tied up with him
are free and they have also escaped , Like if B cutoff the Rope between A and B , All of B, and his successors [E,F,G] have also escaped .

Now in this example let us assume E,F,G has escaped , Now A can pass ball to either B,C or D ,But if A passes ball to B ,it will stop their itself as all of B's
successors have escaped ,Now the ball has been holded by 2 people ,If A has passed the ball to either C or D ,it can be passed one more time ,but in case A passed to B
it cant be passed anymore .So we call this distance of 2 as ***minBallDistance** .

Example Image Link : https://goo.gl/VDMQxE
maxBallDistance is 3 .[ACH or ACI etc]
minBallDistance is 2 [AB]

***
Now given a formation of Students , can you help the Bharath find the minBallDistance and maxBallDistance . Only distances are needed , no need of studentsNames.
***

Example 2 Image Link :  https://goo.gl/2JO0MN
maxBallDistance is  5 . [Path is "ADJKL" ]
minBallDistance is 3 . [Path is "ABE" or "ABF" ]

Example 3 Image Link : https://goo.gl/lbg4jB
maxBallDistance is 4 .[ADEF]
minBallDistance is 2 [AC]

Note :
Ball can only be passed forward but not again backward .ie A can pass to B,C, or D but B cant pass ball to A .
Ball will only stop when their are no more persons he can pass the ball again to .

Representation :
Each student is represented by struct student .
Each student will have a letter as his name ,a,b, or c like that.
first will be address of one first student tied to him or NULL if that student escaped .
second will be address of one second student tied to him or NULL if that student escaped .
third will be address of one third student tied to him or NULL if that student escaped .
A null Student wont have any more students linked to him .
You need to copy the minBallDistance and maxBallDistance into the pointer variables appropirately .

Constraints :
Max or Min ball distance will always be less than 9999.

*/
#include<stdlib.h>
#include<stdio.h>

struct student
{
	char letter;
	struct student *first;
	struct student *second;
	struct student *third;
};


void dep_rec(struct student *node, int *min, int *max,int c)
{
	if (node != NULL)
	{
		c++;
		dep_rec(node->first, min, max, c);
		dep_rec(node->second, min, max, c);
		dep_rec(node->third, min, max, c);
	}

	else
	{
		if ((*min) == 0 || c< (*min))
			(*min) = c;
		if (c > (*max)) 
			(*max) = c;
		
	}
}

void findBallDistance(struct student *leaderStudent, int *minBallDistance, int *maxBallDistance)
{
	 int count = 0;
	(*minBallDistance) = (*maxBallDistance) = 0;
	dep_rec(leaderStudent, minBallDistance, maxBallDistance,count);
}
