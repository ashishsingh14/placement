#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
using namespace std;

void findallprimefactors(int n)
{
    int v[100];
    for(int i = 0;i<100;i++)
    {
        v[i] = 0;
    }
    while(n%2==0)
    {
        v[2] = v[2]+1;
        n = n/2;
    }

    for(int i =3;i*i<=n;i=i+2)
    {
        while(n%i==0)
        {
            v[i] = v[i]+1;
            n = n/i;
        }
    }
    if(n>2)
        v[n] = v[n]+1;
    int i;
    for(i = 0;i<100;i++)
    {
        if(v[i])
            cout<<i<<" "<<v[i]<<endl;
    }
}

void catalannumber(int n )
{
    int table[n+1];
    memset(table,0,sizeof(table));
    table[0] =  table[1] = 1;
    for(int i =2;i<=n;i++)
    {
        for(int j =0;j<i;j++)
        {
            table[i]+= table[j]*table[i-j-1];
        }
    }
    cout<<"Nth catalan number is "<<table[n]<<endl;
}
int compare(const void *a, const void *b)
{
    return *(int*)a<*(int*)b;
}

void sortfunction()
{
    int arr[5] = {23,34,1,2,11};
    qsort(arr,5,sizeof(int),compare);
    for(int i =0;i<5;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    sortfunction();
    return 0;
}

