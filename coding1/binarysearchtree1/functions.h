#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <string.h>
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
    void insertHelper(Node **node,int data);
    int hasPathSumHelper(Node* node,int sum);
    void printlevelorderhelper(Node*node);
    void printAllPossiblePathsHelper(Node* node,int paths[],int len);
    void deleteBSTHelper(Node *node);
    void BSTdeletesimpleHelper(Node *node);
    void bstdeletegeekshelper(Node *node);
    void deleteusingdoublehelper(Node ** node);
    void deletenodehelper(Node **, Node *);
    Node* searchnodehelper(Node *, int);
    Node* findparenthelper(Node *, Node*);
    Node* findparent(Node *);
    Node * greattreelisthelper(Node *);
    int countleafnodehelper(Node *);
    void childrensumhelper(Node*);
    void preorderhelper(Node*);
public:
    BST();
    void insert(int data);
    void inorder();
    void preorder();
    void Insert(int data);
    int hasPathSum(int sum);
    void printlevelorder();
    void printAllPossiblePaths();
    void printPath(int paths[],int len);
    void deleteBST();
    void checkempty();
    void BSTdeletesimple();
    void bstdeletegeeks();
    void deleteusingdouble();
    void deletenode(int);
    void inordersuccessor(Node *);
    Node* searchnode(int a);
    void voidswap();
    void swappointers(Node **, Node**);
    Node* append(Node*a, Node *b);
    void greattreelist();
    void printforgreatlist(Node *);
    void countleafnodes();
    void childrensum();
    void increment(Node* , int);
    void checktesting();
    void createrandom();
    Node* newnode(int);
    Node* treefromprein(int*,int*,int,int);
    Node* treefrompostin(int*,int*,int,int);
    int searchin(int *, int,int,int);
    void buildtree();
    Node*constructtreeFromInAndPostTraversals(int inorder[],int postorder[],int startIndx,int endIndx);
};

#endif // FUNCTIONS_H
