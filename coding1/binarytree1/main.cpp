#include "functions.h"

void calling1()
{
    BST*b = new BST();
    b->insert(5);
    b->insert(3);
    b->insert(2);
    b->insert(4);
    b->insert(8);
    b->insert(6);
    b->insert(9);
    //b->insert(30);
    b->inorder();
    cout<<endl;
    b->clonebinarytree();

    delete b;
}

void calling2(int a[], int *b)
{
    cout<<sizeof(a)/sizeof(int)<<endl;;
    cout<<sizeof(b)/sizeof(int)<<endl;;
    const char *str = "ascdcd\0cdcdc";
    char st[] = {'a','\0','d'};
    cout<<str<<endl;
    cout<<st<<endl;

    /*
     warning: deprecated conversion from string constant to 'char*' [-Wwrite-strings]
    */
}

void calling3(Node ***a)
{
    if(*a==NULL)
    {
        cout<<"yes"<<endl;
        **a = new Node();
        (**a)->data = 5;
        (**a)->left = NULL;
        (**a)->right = NULL;
        (**a)->nextright = NULL;
        cout<<(**a)->data<<endl;

    }


}

void calling4(int **a)
{
    *a = new int(100);

}

void calling5(int***a)
{
    **a = new int(1000);
}

void calling6(int a)
{
    if(a==0)
        return;
    //a = a-1; // this will work
    calling6(--a); // this will work
    //calling6(a--);   // will not work
    cout<<a<<endl;

    /*
     * //    int *a;
//    calling4(&a);
//    cout<<*a<<endl;


    int **a;
    calling5(&a);
    cout<<**a<<endl;
*/
}

int main()
{

    calling1();

    return 0;
}

