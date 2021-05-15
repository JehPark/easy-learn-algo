#include "nselection.h"

int main(void)
{
    int size;
    int *arr;
    int choose;

    cout << "Enter the size of array. \n";
    cin >> size;
    cout << "Enter " << size << " integers \n";
    arr = new int[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Choose i th number\n";
    cin >> choose;
	cout << "Result: " << select(arr, 0, size - 1, choose) << "\n";
    return (0);
}
