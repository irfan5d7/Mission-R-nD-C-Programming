/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an Array and its length and a key element, return the index (Where key is found) if key is found in array
or -1 if key is not found.

Sample Input : 
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search:

Binary Search :

Conclusion :
*/

int linearSearch(int *arr, int len, int key) {

	if (len < 0)
		return -1;
	else
	{
		int i = 0;
		while (arr[i] != key && i<len)
		{
			i++;
		}
		if (arr[i] ==key)
			return i;
		else
			return -1;
	}
}



int binarySearch(int *arr, int len, int key) {
	//Use this function as wrapper function,if you are implementing bs recursively.
	if (len<0)
	return -1;
	else
	{
		int f, l, m;
		f = 0;
		l = len - 1;
		while (f <= l)
		{
			m = (f + l) / 2;
			if (arr[m] == key)
				break;
			else
			{
				if (arr[m] > key)
					l = m - 1;
				else
					f = m - 1;
			}
		}
		if (arr[m] == key)
			return m;
	}
}