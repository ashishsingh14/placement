#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <list>
#include <queue>
#include <math.h>
using namespace std;
void bfs(int s, int v, list<int> *adj);

void callingbfs();

void printarray(int *a, int size);

void printgraph(list<int> *adj, int v);
void dfshelper(list<int> *adj, int s, bool visited[], int &vertices);
#endif // FUNCTIONS_H
