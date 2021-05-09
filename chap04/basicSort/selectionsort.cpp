#include "basicsort.h"

int		theLargest(int *arr, int last)
{
	int max;
	int ret;

	max = INT_MIN;
	ret = 0;
	for (int i = 0; i <= last; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			ret = i;
		}
	}
	return (ret);
}

void	swap(int *arr, int idx1, int idx2)
{
	int temp;

	temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void	selectionsort(int *arr, int size)
{
	int bidx;

	bidx = 0;
	for (int i = size - 1; i > 0; i--)
	{
		bidx = theLargest(arr, i);
		swap(arr, bidx, i);
	}
}
