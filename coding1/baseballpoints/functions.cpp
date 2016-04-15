#include "functions.h"

void calculate(int n, int*arr, int i)
{
    if(n==0)
    {
        printarray(arr,i);
    }
    if(n>0)
    {
        for(int j = 1;j<=3;j++)
        {
            arr[i] = j;
            calculate(n-j,arr, i+1);
        }
    }
}


void printarray(int *arr, int size)
{
    for(int i =0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

