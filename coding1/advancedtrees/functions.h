#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

class Ternarynode{
    int data;
    Ternarynode* left;
    Ternarynode* right;
    Ternarynode* equal;
    unsigned int isendofstring;
};


class Ternarytree
{

private:
    Ternarynode * root;
    Ternarytree();
    void insert(char data);
    void search(char );
    Ternarynode * newnode(char data);
public:
    void insert();
    void search();

};

#endif // FUNCTIONS_H
