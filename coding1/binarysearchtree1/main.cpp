#include "functions.h"

int main()
{
    BST * b = new BST();
//    b->createrandom();
//    cout<<endl;
//    b->inorder();
//    b->childrensum();
//    cout<<endl;
//    b->inorder();
    b->buildtree();
    b->inorder();
    delete b;

    return 0;
}


