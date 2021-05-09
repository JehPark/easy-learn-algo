#include "advsort.h"

int main(void)
{
    int size;
    int *arr;
    int choose;

    cout << "Enter the size of array. \n";
    cin >> size;
    cout << "Enter " << size << " integer \n";
    arr = new int[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Choose sorting algorithms\n";
    cout << "1. mergesort\n";
    cout << "2. quicksort\n";
    cout << "3. heapsort\n";
    cin >> choose;
    switch (choose)
    {
    case 1:
        mergesort(arr, size);
        break;
    case 2:
        quicksort(arr, size);
        break;
    case 3:
        heapsort(arr, size);
        break;
    case 4:
        break;
    case 0:
        break;
    }
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return (0);
}
