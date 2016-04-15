#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#define size 3
using namespace std;


void findlongestlength();
void stock();
int helperutil(char arr[size][size],int dp[size][size], int i, int j,char p);
void candies();
#endif // FUNCTIONS_H
