/*
Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.
Example 1:

Input :
20        25
/  \      /  \
5    30   10   35
Output :

Bst 1 :
20
/   \
5     30
\   /  \
10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,
Any 1 of those correct ways would be fine .

Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs
If an element of BST2 is already in BST 1, then BST2 node is ignored.

(Both r1 and r2 shouldnt be NULL at the time of Input)
Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.
You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard

*/
#include <stdlib.h>
#include <stdio.h>

struct BstNode {
	int data;
	struct BstNode *left;
	struct BstNode *right;
};
void rec_helper(struct BstNode *root1, int k, struct BstNode *temp, int *i)
{
	if (root1 != NULL){
		if (root1->data == k)
		{
			(*i) = 1;
			return;
		}
		else if (k> root1->data)
		{
			rec_helper(root1->right, k, temp, i);
			if (*i == 0)
			{
				root1->right = temp;
				root1->right->left = NULL;
				root1->right->right = NULL;
				(*i) = 1;
			}
			return;
		}
		else if (k< root1->data)
		{
			rec_helper(root1->left, k, temp, i);
			if (*i == 0)
			{
				root1->left = temp;
				root1->left->left = NULL;
				root1->left->right = NULL;
				(*i) = 1;
			}
			return;
		}
	}
}
void merge_rec(struct BstNode **root1, struct BstNode *root2)
{
	if (root2 != NULL)
	{
		merge_rec(root1, root2->left);
		merge_rec(root1, root2->right);
		int i = 0;
		rec_helper(*root1, root2->data, root2, &i);
	}
}
void merge_two_bst(struct BstNode **root1, struct BstNode *root2)
{
	if (root2 == NULL)
	{
		return;
	}
	else if (*root1 == NULL)
	{
		*root1 = (struct BstNode *)malloc(sizeof(struct BstNode));
		(*root1) = root2;
	}
	else merge_rec(root1, root2);
}