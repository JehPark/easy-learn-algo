#include "advsort.h"

int partition(int *arr, int start, int end)
{
    int stand = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] < stand)
        {
            int temp = arr[j];
            arr[j] = arr[++i];
            arr[i] = temp;
        }
    }
    arr[end] = arr[i + 1];
    arr[i + 1] = stand;
    return (i + 1);
}

void q_sort(int *arr, int start, int end)
{
    if (start < end)
    {
        int part = partition(arr, start, end);
        q_sort(arr, start, part - 1);
        q_sort(arr, part + 1, end);
    }
}

void quicksort(int *arr, int size)
{
    q_sort(arr, 0, size - 1);
}