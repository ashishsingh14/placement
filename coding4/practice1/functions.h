#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stack>
#include <algorithm>
#include <ctype.h>
#include <sstream>

#define M 5
#define N 5
#define V 6

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node*newnode(int a);

void convertomirrortree(Node *root);

void inorder(Node *root);
bool dfsassign(int c, bool *seen, int *match, bool graph[M][N]);
void roottoleafpath(Node *root, int sum, int currentsum, int level, int &ans);
void roottoleafpathhelper(Node *root, int sum);
void largestnumber(int *arr, int n);

string removealloccurences(string a, string b);

void printoccurences();

void convertonestringintoanother(string a, string b);

void minimumstepsfromonestringtoanother(string arr[], int n, string src, string dest);
int onechardistance(string a, string b);

void maximumbipartitemathching();



bool issafe(int a[5][6], int x, int y, bool visited[5][6]);
void islandshelper(int a[5][6], bool visited[5][6], int x, int y);
void numberfislands();

void maxflow();

bool psuedoanagram(string a, string b);
bool checkifalphabet(char a);

void convertdectoheaxa(int number);
char valToChar(int val);
int charToVal(char curChar);
void convertodecimal(string h);

void binomialcoefficient();

#endif // FUNCTIONS_H
