#include "functions.h"

void calling1()
{
    BST*b = new BST();
    b->insert(15);
    b->insert(13);
    b->insert(17);
    b->insert(10);
    b->insert(14);
    b->insert(16);
    b->insert(20);
    b->inorder();
    cout<<endl;
    b->roottoleaf();
    cout<<endl;


    delete b;
}

int main()
{
    calling1();
    return 0;
}

