/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int height_bst(struct node *node)
{
	if (node == NULL)
		return 0;
	else
	{
		int l_height = (height_bst(node->left));
		int r_height = (height_bst(node->right));
		if (l_height > r_height)
			return (l_height + 1);
		else
			return(r_height + 1);
	}
}
void rec_helper(struct node* node, int level,int *arr,int *i)
{
	if (node == NULL)
		return;
	if (level == 1)
		arr[(*i)++] = node->data;
	else if (level > 1)
	{
		rec_helper(node->right, level - 1,arr,i);
		rec_helper(node->left, level - 1,arr,i);
	}
}

void l_traversal(struct node* root,int *arr,int *i)
{
	int h = height_bst(root);
	int l;
	for ( l = 1; l <= h; l++)
		rec_helper(root, l,arr,i);
}


int size(struct node* node)
{
	if (node == NULL)
		return 0;
	else
		return(size(node->left) + 1 + size(node->right));
}


int* BSTRighttoLeftRows(struct node* root)
{ 
	if (root ==NULL)
    return NULL;
	else
	{
		int s = size(root);
		int *rowRtoL = (int *)malloc(sizeof(int)*s);
		int i = 0;
		l_traversal(root, rowRtoL, &i);
		return rowRtoL;
	}
}
