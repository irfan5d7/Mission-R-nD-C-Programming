/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):

Way 1 :

Way 2 :

Way 3:

Conclusion :
*/
#include <stdio.h>
#include <stdlib.h>

/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ? __________
*/
int* sumoftwoBF(int *nums, int target, int len){
	if (nums == NULL || len <= 0)
		return NULL;
	else
	{
		int *out = (int *)malloc(sizeof(int) * 2);
		int i, j;
		for ( i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{
				if (i != j && nums[i]+nums[j] == target)
				{
						if (nums[i]>nums[j])
						{
							out[0] = nums[j];
							out[1] = nums[i];
						}
						else
						{
							out[0] = nums[i];
							out[1] = nums[j];
						}
						return out;
					}
				}
			}
	}
}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add
so that total sum will become less.

What is the complexity of this method ? __________
*/
void qsort(int *nums, int low, int high)
{
	int pivot, i, j,temp;
	if (low < high)
	{
		pivot = low;
		i = low + 1;
		j = high;
		while (i < j)
		{
			while (nums[i] <= nums[pivot] && i <= high)
			{
				while (nums[pivot] == nums[i])
					i++;
				if (nums[pivot] > nums[i])
				{
					temp = nums[pivot];
					nums[pivot] = nums[i];
					nums[i] = temp;
					pivot++;
					i++;
				}
			}
			while (nums[pivot] < nums[j])
				j--;
			if (i < j)
			{
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
		qsort(nums, low, pivot - 1);
		qsort(nums, j + 1, high);
	}
}
int* sumoftwoSortAndSearch(int *nums, int target, int len){
	if (nums != NULL)
	{
		int *out = (int *)malloc(sizeof(int) * 2);
		int i = 0, j = len - 1;
		qsort(nums, 0, j);
		while (j > i)
		{
			if ((nums[i] + nums[j]) == target)
			{
				out[0] = nums[i];
				out[1] = nums[j];
				return out;
			}
			if ((nums[i] + nums[j]) > target)
				j--;
			if ((nums[i] + nums[j]) < target)
				i++;
		}
		return NULL;
	}
	else
		return NULL;
}


/*

Array contains only integers from 1-100; Can you use this range restriction and an extra array to
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
*/
int* sumoftwoExtraArray(int *nums, int target, int len)
{
	int *store = (int *)malloc(sizeof(int) * 101);
	int *res = (int *)malloc(sizeof(int) * 2);
	int i, a;
	for (i = 0; i <= 100; i++)
	{
		store[i] = 0;
	}
	for (i = 0; i < len; i++)
	{
		a = nums[i];
		if (a < target)
		{
			if ((a + store[a]) == target)
			{
				if (a > store[a])
				{
					res[0] = store[a];
					res[1] = a;
				}
				else
				{
					res[1] = store[a];
					res[0] = a;
				}
				return res;
			}
			else
			{
				store[target - a] = a;
			}
		}
	}

}


