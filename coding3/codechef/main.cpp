#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <map>
using namespace std;
#define size 1000000
map<int,long long int>m;
void precompute()
{
    m[0] = 0;
    m[1] = 1;
    m[2] = 2;
    for(int i= 3;i<=size;i++)
    {
        m[i] = i;

        if(m[i/2]+m[i/3]+m[i/4]>m[i])
            m[i] = m[i/2]+m[i/3]+m[i/4];
    }

}

long long int bytelandiancoins(long long int n)
{
    if(n<size)
        return m[n];
    else
        return max(n,m[n/2]+m[n/3]+m[n/4]);
}

void closingthetweets()
{
    int n,k,b;
    cin>>n>>k;
    int ans =0;
    string s;
    int arr[1001] = {0};
    for(int i =0;i<k;i++)
    {
        cin>>s;
        if(s=="CLICK")
        {
            cin>>b;
            if(arr[b]==0)
            {
                arr[b] = 1;
                ans = ans + 1;
            }
            else
            {
                arr[b] = 0;
                ans = ans -1;
            }
        }
        else if(s=="CLOSEALL")
           {
            for(int i =1;i<=n;i++)
                arr[i] =0;
            ans =0;
        }
        cout<<ans<<endl;

    }

}

int main()
{
//    long long int n;
//    precompute();
//    while(scanf("%lld",&n)>0)
//    {
//        cout<<bytelandiancoins(n)<<endl;
//    }

    closingthetweets();
    return 0;
}

