#include "basicsort.h"

void impbubblesort(int *arr, int size)
{
    bool sorted;

    sorted = true;
    for (int last = size - 1; last > 0; last--)
    {
        sorted = true;
        for (int i = 0; i < last - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
                sorted = false;
            }
        }
        if (sorted == true)
            break;
    }
}