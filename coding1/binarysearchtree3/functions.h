#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node * right;
};

class nodel{
public:
    int data;
    nodel*next;
};

class BST{
private:
    Node * root;
    void inserthelper(Node * root, int data);
    void inorderhelper(Node * root);
    Node *removekeysoutsidegivenrangehelper(Node * , int l, int h);
    bool triplethelper(Node *);
    void converttodll(Node *, Node**, Node **tail);
    bool findsumindll(Node * head, Node*tail, int sum);
    bool isbsthelper(Node*,int,int);
    void inplacedlltobsthelper(Node * root);
    Node* newnode(int data);
    void mergetwobststackhelper(Node *, Node*);
    void mergetwobstusingdllhelper(Node *, Node *);
    Node* mergetwodll(Node *, Node*);
    Node* sortedlinkedlisttobsthelper(Node**, int);
    Node* treepreandlevelhelper(int *in, int * level, int l, int h, int size);
    void constructfrompostorderhelper(Node *root);
    bool storeancestorshelper(Node * root, int key,vector<int>&v, int i);
    int findfloorhelper(Node * root, int key);
    void findpreandsuccesorhelper(Node * root, int key, int &succ, int &pred);
public:
    BST();
    void insert(int data);
    void inorder();
    void removekeysoutsidegivenrange();
    bool triplet();
    void isbst();
    void inplacedlltobst();
    void mergetwobstwithstack();
    void printdoublelinkedlist(Node*);
    void mergetwobstusingdll();
    void sortedlinkedlisttobst();
    void treepreandlevel();
    void constructfrompostorder();
    void constructcompletefromlinkedlist();
    void storeancestors();
    void findlcainbst(int n1, int n2);
    void findfloor(int key);
    void findpreandsuccesor(int key);

};
int* constructlevel(int *in, int *level, int l, int h,int size);
int search(int *in, int el, int l, int h);

#endif // FUNCTIONS_H
