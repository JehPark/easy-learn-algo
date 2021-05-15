#ifndef NSELECTION_H
#define NSELECTION_H

#include <iostream>
#include <climits>

using namespace std;

int linearSelect(int *arr, int p, int r, int i);
int partition(int *arr, int p, int r);
int partition(int *arr, int p, int r, int size);
int select(int *arr, int p, int r, int i);

#endif
