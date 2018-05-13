/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

void convert_bst_helper(struct node *node, int *arr, int low, int high, int len)
{
	if (node == NULL)
		return;
	int mid;
	if (low <= high)
	{
		struct node * temp = (struct node *)malloc(sizeof(struct node));
		mid = (low + high) / 2;
		temp->data = arr[mid];
		temp->left = NULL;
		temp->right = NULL;
		if (temp->data < node->data)
			node->left = temp;
		else
			node->right = temp;
		convert_bst_helper(temp, arr, low, mid - 1, len);
		convert_bst_helper(temp, arr, mid + 1, high, len);

	}
}

struct node * convert_array_to_bst(int *arr, int len){
	if (len<=0||arr==NULL)
	return NULL;
	struct node *head = (struct node *)malloc(sizeof(struct node));
	int low = 0, high = len - 1;
	int mid = (low + high) / 2;
	head->data = arr[mid];
	head->left = NULL;
	head->right = NULL;
	convert_bst_helper(head, arr, 0, mid - 1, len);
	convert_bst_helper(head, arr, mid + 1, len - 1, len);
	return head;
}

