/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorder_helper(struct node *node, int *arr, int *i)
{
	if (node!=NULL)
	{
		inorder_helper(node->left, arr, i);
		arr[(*i)++] = node->data;
		inorder_helper(node->right, arr, i);
	}
}

void preorder_helper(struct node *node, int *arr, int *i)
{
	if (node != NULL)
	{
		arr[(*i)++] = node->data;
		preorder_helper(node->left, arr, i);
		preorder_helper(node->right, arr,i);
	}
}
void postorder_helper(struct node *node, int *arr, int *i)
{
	if (node == NULL)
		return;
	postorder_helper(node->left, arr, i);
	postorder_helper(node->right, arr, i);
	arr[(*i)++] = node->data;
}
void inorder(struct node *root, int *arr){
	if (arr == NULL)
		return;
	int i = 0;
	inorder_helper(root, arr,&i);
}
void preorder(struct node *root, int *arr){
	if (arr == NULL)
		return;
	int i=0;
	preorder_helper(root, arr, &i);
}
void postorder(struct node *root, int *arr){
	if (arr == NULL)
		return;
	int i = 0;
	postorder_helper(root, arr, &i);
}

