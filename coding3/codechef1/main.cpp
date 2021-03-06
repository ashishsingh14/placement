#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
struct p
{
    int m, f;
};
typedef struct p pp;


void merge(int *arr, int l, int m, int h);
long long int ans = 0;
void mergesort(int *arr, int l, int h)
{
    int mid;
    if(l<h)
    {
        mid = (h+l)/2;
        mergesort(arr,l,mid);
        mergesort(arr, mid+1,h);
        merge(arr,l,mid,h);
    }

}

void merge(int * arr, int l, int m, int h)
{
    int n1,n2;
    n1 = m-l+1;
    n2 = h-m;

    vector<int>left(n1,0);
    vector<int>right(n2,0);

    for(int i =0;i<n1;i++)
    {
        left[i] = arr[l+i];
    }
    for(int j =0;j<n2;j++)
    {
        right[j] = arr[m+j+1];
    }

    int k ;
    int i = 0;
    int j = 0;
    for(k=l;k<=h;k++)
    {
        if((i<n1 && left[i]<=right[j]) || j>=n2)
        {
            arr[k] = left[i++];
        }
        else
        {
            arr[k] = right[j++];
            ans +=  n1-i;

        }
    }


}

int compare(const void *a, const void *b)
{
    //return *(struct p*)a.m - *(struct p*)b.m;

    struct p* x = (( struct p*)a);
    struct p* y = ((struct p*)b);
    return x->m - y->m;

}

void chefreunion()
{
    int n;
    cin>>n;

    pp input[n];
    int a,b;
    int final[n];
    for(int i =0;i<n;i++)
    {
        cin>>a>>b;
        input[i].m = a;
        input[i].f = b;

    }
    //cout<<sizeof(pp)<<endl;
    qsort(input,n, sizeof(*input),compare);
    for(int i =0;i<n;i++)
    {
        //cout<<input[i].m<<"->"<<input[i].f<<endl;
        final[i] = input[i].f;
    }
    mergesort(final,0,n-1);
//    for(int i =0;i<n;i++)
//    {
//        //cout<<input[i].m<<"->"<<input[i].f<<endl;
//        cout<<final[i]<<" ";
//    }
//    cout<<endl;
    cout<<ans<<endl;


}

int main()
{
    chefreunion();
    return 0;
}

