#include "advsort.h"

void merge(int *arr, int start, int mid, int end)
{
    int *temp;
    int i, j, t;

    temp = new int[end - start + 1];
    i = start;
    j = mid + 1;
    t = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
            temp[t++] = arr[j++];
        else
            temp[t++] = arr[i++];
    }
    while (i <= mid)
        temp[t++] = arr[i++];
    while (j <= end)
        temp[t++] = arr[j++];
    t = 0;
    i = start;
    while (i <= end)
        arr[i++] = temp[t++];
    delete[] temp;
}

void split(int *arr, int start, int end)
{
    if (end > start)
    {
        int mid = (start + end) / 2;
        split(arr, start, mid);
        split(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void mergesort(int *arr, int size)
{
    split(arr, 0, size - 1);
}