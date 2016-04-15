#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node * right;
    Node *nextright;
};

class BST{
private:
    Node * root;
    void inserthelper(Node * root, int data);
    void inorderhelper(Node * root);
    void verticaldhelper(Node * root, int hd, map<int, int> &mymap);
    void connectnodessamelevelhelper(Node * );
    void doubletree(Node *, Node**);
    Node* findlcahelper(Node*, int a, int b, int& v1, int& v2, int level, int&dist);
    bool findhelper(Node*root, int a);
    int finddistancefromroot(Node*,int a,int level);
    void sumfromrootleave(Node *, int&sum, int d);
    void prinancestorsworecursion(Node * root, int a);
    int printdistanceatkhelper(Node *, int b, int a);
    void printdownfromnode(Node*, int a);
    void calculateverticalhelper(Node*, int &minr, int& maxr, int hd);
    void printvertivcalhelper(Node *, int i);
    int maxpathtwoleaveshelper(Node * , int&);
    void reversealternatelevelshelper(Node *root, int *nodes, int &index, int level);
    void insertelementsintoarray(Node * , int * a, int &i , int level);
    void clonebinarytreehelper(Node * root, Node**);
    Node * newnode(int data);
public:
    BST();
    void insert(int data);
    void inorder();
    void verticald();
    void connectnodessamelevel();
    void printsamelevel();
    void doubletree();
    void findlca(int a, int b);
    void findnode(int a);
    void sumfromrootleave();
    void printancestors(int a);
    void printdistanceatk(int a, int b);
    void printvertivcal();
    void maxpathtwoleaves();
    void reversealternatelevels();
    void clonebinarytree();

};

#endif // FUNCTIONS_H
