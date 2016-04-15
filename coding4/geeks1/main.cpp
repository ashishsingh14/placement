#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int ans = 0;
map<int,int>ma;
void merge(int*arr, int l, int m, int h)
{

    int n1 = m-l+1;
    int n2 = h-m;
    vector<int>q(n1);
    vector<int>r(n2);

    for(int i =0;i<n1;i++)
        q[i] = arr[l+i];
    for(int i =0;i<n2;i++)
    {
        r[i] = arr[m+i+1];
    }

    int k;
    int i = 0;
    int j = 0;

    for(k = l;k<=h;k++)
    {
        if((i<n1 && j<n2 && q[i]<=r[j]) || j>=n2)
        {
            arr[k] = q[i++];
        }
        else
        {
            arr[k] = r[j++];
            ma[q[i]]++;
            ans += n1-i;
        }
    }


}

void mergesort(int *arr, int l, int h)
{
    if(l<h)
    {
        int mid = l +(h-l)/2;

        mergesort(arr, l, mid);
        mergesort(arr, mid+1,h);
        merge(arr,l,mid,h);
    }
}


void findthreeclosest()
{
    int A[] = {1, 4, 10};
    int B[] = {2, 15, 20};
    int C[] = {10, 12};


    int i,j,k;
    i = j = k = 0;
    int diff = INT_MAX;
    int m,n,o;
    m = n = o = 0;
    while(i<3 && j<3 && k<2)
    {

       int ma = max(A[i],max(B[j],C[k]));
       int mi = min(A[i],min(B[j],C[k]));
       if(ma-mi<diff)
       {
           diff = ma-mi;
           m = i;
           n = j;
           o = k;

       }
       if(diff==0)
           break;
       if(mi==A[i])i++;
       else if(mi==B[j])j++;
       else
           k++;
    }

    cout<<A[m]<<" "<<B[n]<<" "<<C[o]<<endl;
}


int mincoins(int *coins, int sum, int size)
{
    if(sum==0)
        return 0;
    if(size==0 || sum<0)
        return INT_MAX;
    int ans = mincoins(coins,sum-coins[size-1],size );
    if(ans!=INT_MAX)
    return min(1+ans, mincoins(coins,sum,size-1));
    else
    {
        cout<<"Hi"<<endl;
        return mincoins(coins,sum,size-1);
    }

}

int main()
{
    int arr[] = {5,4,3,2,1};
    mergesort(arr,0,4);
    for(int i =0;i<5;i++)
        cout<<arr[i]<<" ";

    cout<<"The total inversions are "<<ans<<endl;

    map<int,int>::iterator i;
    for(i = ma.begin();i!=ma.end();i++)
        cout<<i->first<<" "<<i->second<<endl;


//    int coins[] = {3, 5};

//    int sum  = 7;
//    cout<<"Hey"<<endl;
//    cout<<"Min coins are "<<mincoins(coins, sum, 2)<<endl;

    return 0;
}

