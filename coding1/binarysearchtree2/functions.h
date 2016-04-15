#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node * right;
};

class BST{
private:
    Node * root;
    void inserthelper(Node * root, int data);
    void inorderhelper(Node * root);
    void postorderusingonestackhelper(Node*);
    void postorderusingtwostackhelper(Node*);
    void morrisinorderhelper(Node*);
    void morrispreorderhelper(Node*);
    void inorderstackhelper(Node *);
    void preorderstackhelper(Node *);
    void postorderstackhelper(Node *);
    bool roottoleafhelper(Node *, int);

public:
    BST();
    void insert(int data);
    void inorder();
    void postorderusingonestack();
    void postorderusingtwostack();
    void morrisinorder();
    void morrispreorder();
    void inorderstack();
    void preorderstack();
    void postorderstack();
    void roottoleaf();
};


#endif // FUNCTIONS_H
