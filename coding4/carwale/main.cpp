#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[1000000];
#define mod 1000000007

int helpingcoin(int *h, int *t,int sum)
{
    if(dp[sum]!=-1)
        return dp[sum];
    if(sum<0)
        return 0;
    if(sum==0)
        return 1;
    int count = 0;
    for(int i =0;i<2;i++)
    {
        count+= helpingcoin(h,t,sum-h[i]);
        count = count%mod;
    }
    for(int i =0;i<2;i++)
    {
        count += helpingcoin(h,t,sum-t[i]);
        count = count%mod;
    }
    return dp[sum] = count;
    //return count;
}

void faircoins()
{
    int count = 0;
    int head[] = {1,2};
    int tail[] = {1,2};

    int t;
    cin>>t;

    while(t--)
    {
        long long int n ;
        cin>>n;
        count = 0;
        memset(dp,-1,sizeof(dp));
        for(int i =0;i<2;i++)
        {
            count += helpingcoin(head, tail, n-head[i]);
            count = count%mod;
        }

//        for(int i =0;i<5;i++)
//            cout<<dp[i]<<" ";
//        cout<<endl;

    cout<<count<<endl;
    }

}


int main()
{
    faircoins();
    return 0;
}

