#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <list>
#include <queue>
#include <map>
using namespace std;

class node
{
public:
    int data;
    node * next;
};

class Graph
{
    int v;
    list<int>*adj;
    void dfshelper(int s, bool *visited);
    void cyclehelper(int s, bool *visited);
    void countstepsinmatrixhelper();
public:
    Graph(int v);
    void addedge(int s, int d);
    void bfs(int s);
    void dfs();
    bool iscyclic();
    void countislands();
    bool issafe(int **a, int i , int j, int n, bool *visited);
    void dfsmatrix(int **a, int i, int j, int n, bool *visited);
    void countstepsinmatrix();
    bool unionfind();
    int findparent(int * parent, int i);
    void takeunion(int*parent, int x, int y);

};



#endif // FUNCTIONS_H
