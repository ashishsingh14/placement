#include "functions.h"
void calling1(int n)
{
    int * arr = new int[SIZE];
    calculate(n, arr,0);
    delete arr;
}

int main()
{
    calling1(3);
    return 0;
}

