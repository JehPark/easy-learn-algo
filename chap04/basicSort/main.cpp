#include "basicsort.h"

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
    cout << "1. selectionsort\n";
    cout << "2. bubblesort\n";
    cout << "3. impbubblesort\n";
    cout << "4. insertionsort\n";
    cin >> choose;
    switch (choose)
    {
    case 1:
        selectionsort(arr, size);
        break;
    case 2:
        bubblesort(arr, size);
        break;
    case 3:
        impbubblesort(arr, size);
        break;
    case 4:
        insertionsort(arr, size);
        break;
    case 0:
        break;
    }
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    return (0);
}
