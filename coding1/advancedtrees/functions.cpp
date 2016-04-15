#include "functions.h"


Ternarytree::Ternarytree()
{
    root = NULL;
}

Ternarynode* Ternarytree::newnode(char data)
{
    Ternarynode*n = new Ternarynode();
    n->data = data;
    n->equal = NULL;
    n->left = NULL;
    n->right = NULL;
    return n;
}


void Ternarytree::insert()
{
    insert(root);
}


