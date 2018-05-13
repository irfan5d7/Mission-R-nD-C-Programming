/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int height_rec(struct node *node)
{
	if (node == NULL)
		return 0;
	else
	{
		int l_height = (height_rec(node->left));
		int r_height = (height_rec(node->right));
		if (l_height > r_height)
			return (l_height + 1);
		else
			return(r_height + 1);
	}
}

int get_height(struct node *root){
	if (root == NULL)
		return 0;
	else
	{
		return (height_rec(root));
	}
}

void sum_help(struct node *node, int *s)
{
	if (node == NULL)
		return;
	(*s) = (*s) + node->data;
	sum_help(node->left, s);
	sum_help(node->right, s);
}

int get_left_subtree_sum(struct node *root){
	if (root == NULL)
		return 0;
	else
	{
		int s = 0;
		sum_help(root->left, &s);
		return s;
	}
}

int get_right_subtree_sum(struct node *root){
	if (root == NULL)
		return 0;
	else
	{
		int s = 0;
		sum_help(root->right, &s);
		return s;
	}
}

