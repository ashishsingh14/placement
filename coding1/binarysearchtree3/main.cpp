#include "functions.h"

void calling1()
{
    BST*b = new BST();
    b->insert(6);
    b->insert(3);
    b->insert(15);
    b->insert(13);
    b->insert(7);
    cout<<endl;
    //b->sortedlinkedlisttobst();
    //b->treepreandlevel();
    //b->constructfrompostorder();
    //b->constructcompletefromlinkedlist();
//    b->storeancestors();
//    b->findlcainbst(15,3);
//    b->findfloor(5);
    b->findpreandsuccesor(13);
}

int main()
{
    calling1();
    return 0;
}

