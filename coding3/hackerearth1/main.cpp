#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;


vector<int> findprime(ll x)
{
    vector<int>v;
    if(x==2)
    {
        v.push_back(2);
        return v;
    }
    ll c = x;
    for(int i =2;i*i<=x;i++)
    {
        int count =0;
        while(x%i==0)
        {
            x = x/i;
            count++;
        }
        if(count)
            v.push_back(i);
    }
    if(x>2)
        v.push_back(x);

//    vector<int>::iterator i;
//    cout<<"for "<<c<<endl;
//    for(i = v.begin();i!=v.end();i++)
//    {
//        cout<<*i<<" ";
//    }
//    cout<<endl;
    return v;
}

void missdd()
{
    ll n,k,q;
    cin>>n;
    cin>>q;
    while(q--)
    {
        cin>>k;
        ll ans =0;
        for(ll i =2;i<=n;i++)
        {
            vector<int>v = findprime(i);
            long long int l = v.size();
            if(l==k)
                ans++;
        }
        cout<<ans<<endl;

    }
}

void pandchocolates()
{
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        int input[n];
        for(int i =0;i<n;i++)
            cin>>input[i];
        long long int ans =0;
        long long int mod = 1000000007;
        int table[n];
        int sum[n];
        for(int i =0;i<n;i++)
        {
            table[i] = 0;
            sum[i] = 0;
        }
        table[0] = 1;
        sum[0] = input[0];
        if(n==1)
        {
            cout<<"1"<<endl;
            continue;
        }
        else
        {
            for(int i = 1;i<n;i++)
            {
                //for(int )
                if(input[i]>1)
                {
                    table[i] = (input[i]+sum[i-1]-1)%mod;
                    sum[i]= (sum[i-1]%mod + input[i]%mod)%mod;

                }
                else
                {
                    table[i] = table[i-1];
                    sum[i]= (sum[i-1]%mod + input[i]%mod)%mod;
                }
            }

//            for(int i =0;i<n;i++)
//                cout<<table[i]<<" ";
//            cout<<endl;
            cout<<table[n-1]<<endl;
        }

    }

}

int main()
{
    pandchocolates();
    return 0;
}

