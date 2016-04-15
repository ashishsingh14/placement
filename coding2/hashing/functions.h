#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <limits.h>
using namespace std;
#define range 255

void countsort(int *arr, int size);
void countsortradix(int *arr, int exp, int size);
void printarray(int *arr, int size);

void radixsort(int * arr, int size);

#endif // FUNCTIONS_H
