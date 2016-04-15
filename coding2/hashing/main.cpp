#include "functions.h"

void calling1()
{
    int arr[10] = {2,2,2,1,1,3,4,5,0,0};
    radixsort(arr,10);
    printarray(arr,10);
}

int main()
{
    calling1();
    return 0;
}

