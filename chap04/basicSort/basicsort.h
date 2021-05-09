#ifndef BASICSORT_H
#define BASICSORT_H

#include <climits>
#include <iostream>

using namespace std;

void	selectionsort(int *arr, int size);
int		theLargest(int *arr, int last);
void	swap(int *arr, int idx1, int idx2);

#endif
