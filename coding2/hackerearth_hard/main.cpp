#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#define size 100000
using namespace std;

void comrades()
{
    int n,q;
    cin>>n;
    int superior[size] = {0};
    int temp;
    int type, id;

    for(int i =0;i<n;i++)
    {
        cin>>temp;
        if(temp==0)
        {
            continue;
        }
        else
        {
            superior[temp] = 1;
        }

    }

    cin>>q;
    int save;
    for(int j = 0;j<q;j++)
    {
        cin>>type>>id;
        if(type==3)
        {
            cout<<superior[id]<<endl;
        }
        else if(type==2)
        {
            save = superior[id];
            superior[id] = 0;
        }
        else if(type==1)
        {
            superior[id] = save;
        }
    }

}

void swapit()
{
    int t;
    cin>>t;
    int n,k;
    long long int arr[n];
    while(t--)
    {
        cin>>n>>k;
        for(int i = 0;i<n;i++)
        {
            cin>>arr[i];
        }

        int j = k;
        while(k!=0)
        {
            if(k>0)
            {
                for(int i = 0;i<n;i++)
                {
                        if(arr[i+k]<arr[i+k-1] && arr[i+k]<arr[k])
                        {
                            swap(arr[i+k],arr[i+k-1]);
                            k--;
                        }
                }
            }

        }

        for(int i = 0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }
}

int countsetbits(long long int x)
{
   int count = 0;
   while(x>0)
   {
       x = x&(x-1);
       count++;
   }
   return count;

}

bool compare(int i , int j)
{
    return countsetbits(i)>countsetbits(j);
}

void monkchoice()
{
    int t;
    int n , k;
    cin>>t;
    long long ans;
    while(t--)
    {
        cin>>n>>k;
        int arr[n];
        ans = 0;
        for(int i =0;i<n;i++)
        {
            cin>>arr[i];
        }

        sort(arr, arr+n, compare);
        for(int i =0;i<k;i++)
        {
            ans += countsetbits(arr[i]);
        }
        cout<<ans<<endl;
    }

}

void monkandhisfriend()
{
    int t;
    long long m,p,x;
    cin>>t;
    while(t--)
    {
        cin>>m>>p;
        x = m^p;
        cout<<countsetbits(x)<<endl;
    }
}


int main()
{
    monkchoice();
    return 0;
}

