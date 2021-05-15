#include "nselection.h"

int select(int *arr, int p, int r, int i)
{
	int q, k;
	if (p > r)
		return (0);
	if (p == r)
		return (arr[p]);
	q = partition(arr, p, r);
	k = q - p + 1;
	if (k > i)
		return (select(arr, p, q - 1, i));
	else if (k == i)
		return (arr[q]);
	else
		return (select(arr, q + 1, r, i - k));
}

int partition(int *arr, int p, int r)
{
	int i, tmp;

	i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (arr[j] < arr[r])
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	tmp = arr[r];
	arr[r] = arr[i + 1];
	arr[i + 1] = tmp;
	return (i + 1);
}
