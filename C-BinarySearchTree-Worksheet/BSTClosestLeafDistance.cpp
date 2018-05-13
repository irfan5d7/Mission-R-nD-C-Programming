/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

int height_help(struct node * node)
{
	if (node == NULL)
		return NULL;
	else
	{
		int l = height_help(node->left);
		int r = height_help(node->right);
		if (l > r)
			return (l + 1);
		else
			return (r + 1);
	}
}

void leaf_below(struct node *node, int level, int *closer)
{
	if (node == NULL)
		return;
	else
	{
		if (node->left == NULL && node->right == NULL)
		{
			if (level < (*closer))
				(*closer) = level;
			return;
		}
		leaf_below(node->left, level + 1, closer);
		leaf_below(node->right, level + 1, closer);
	}

}

int leaf_from_above(struct node * node, struct node *temp, int *closer)
{
	if (node == NULL) 
		return -1;
	if (node == temp) 
		return 0;
	int ret_lef = leaf_from_above(node->left,temp, closer);
	if (ret_lef != -1)
	{
		leaf_below(node->right, ret_lef + 2, closer);
		return ret_lef + 1;
	}
	int ret_rt = leaf_from_above(node->right, temp, closer);
	if (ret_rt != -1)
	{
		leaf_below(node->left, ret_rt + 2, closer);
		return ret_rt + 1;
	}

	return -1;
}


int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
  return -1;
	else
	{
		int closer = height_help(root),lev=0;
		leaf_below(temp,lev ,&closer);
		int ret = leaf_from_above(root, temp, &closer);
		return closer;
	}
}
