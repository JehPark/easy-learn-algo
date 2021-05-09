#include "basicsort.h"

void insertionsort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int loc = i - 1;
        int newitem = arr[i];
        while (loc >= 0 && newitem < arr[loc])
        {
            arr[loc + 1] = arr[loc];
            loc--;
        }
        arr[loc + 1] = newitem;
    }
}