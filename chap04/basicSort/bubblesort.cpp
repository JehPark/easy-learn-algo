#include "basicsort.h"

void bubblesort(int *arr, int size)
{
    for (int last = size - 1; last > 0; last--)
    {
        for (int i = 0; i < last; i++)
        {
            if (arr[i] > arr[i + 1])
                swap(arr, i, i + 1);
        }
    }
}