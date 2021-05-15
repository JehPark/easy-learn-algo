#include "linearselection.h"

int linearSelect(int *arr, int p, int r, int i)
{
	int *midarr;
	int j;

	j = 0;
	if (p < r)
	{
		if (r - p + 1 < 6)
			return select(arr, p, r, i);
		int size = (r - p + 1) / 5 + (r - p + 1) % 5 == 0 ? 0 : 1;
		midarr = new int[size];
		for (int i = p + 4; i <= r; i += 5)
		{
			if (i > r)
				midarr[j] = select(arr, i - 4, r, (i + r - 4) / 2);
			midarr[j++] = select(arr, i - 4, i, (2 * i - 4) / 2);
		}
		int M = linearSelect(midarr, 0, size - 1, j / 2);
		delete[] midarr;
		int q = partition(arr, 0, M, r);
		int k = q - p + 1;
		if (k > i)
			return (linearSelect(arr, p, q - 1, i));
		else if (k == i)
			return (arr[q]);
		else
			return (linearSelect(arr, q + 1, r, i - k));
	}
	return (-1);
}

int select(int *arr, int p, int r, int i)
{
	int q, k;

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
	return (i);
}

int partition(int *arr, int p, int r, int size)
{
	int i, tmp;

	i = p - 1;
	for (int j = p; j <= size; j++)
	{
		if (arr[j] < r)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	return (i);
}