#include "advsort.h"

void heapify(int *arr, int root, int last)
{
    int left, right, smaller;

    left = root * 2;
    right = root * 2 + 1;
    smaller = 0;
    if (right <= last)
    {
        if (arr[left] < arr[right])
            smaller = left;
        else
            smaller = right;
    }
    else if (left <= last)
        smaller = left;
    else
        return;
    if (arr[smaller] < arr[root])
    {
        int temp = arr[root];
        arr[root] = arr[smaller];
        arr[smaller] = temp;
        heapify(arr, smaller, last);
    }
}

void buildheap(int *arr, int size)
{
    for (int i = (size - 1) / 2; i >= 0; i--)
        heapify(arr, i, size - 1);
}

void heapsort(int *arr, int size)
{
    buildheap(arr, size);
    for (int i = size - 1; i > 0; i--)
    {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, 0, i - 1);
    }
}