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

void students()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<string,int> m;

        for(int i =0;i<n;i++)
        {
            int s;
            cin>>s;
            string subject;
            for(int j =0;j<s;j++)
            {
                cin>>subject;
                m[subject]++;
            }
        }


        map<string,int>::iterator i;
        int ans =0;
        for(i = m.begin();i!=m.end();i++)
        {
            cout<<i->first<<" "<<i->second<<endl;
            ans = ans + i->second*(i->second-1)/2;
        }

        cout<<ans<<endl;

    }

}

int compare(int a, int b)
{
    return a>b;
}

void cuts()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        long long int hor[m-1];
        long long int ver[n-1];

        for(int i =0;i<m-1;i++)
            cin>>hor[i];
        for(int i =0;i<n-1;i++)
            cin>>ver[i];


        sort(hor,hor+m-1,compare);
        sort(ver,ver+n-1,compare);

//        for(int i =0;i<m-1;i++)
//            cout<<hor[i]<<" ";
//        cout<<endl;
//        for(int i =0;i<n-1;i++)
//            cout<<ver[i]<<" ";
//        cout<<endl;

        int h,v;
        h = v = 1;

        int i,j;
        i = j =0;
        long long int cost = 0;
#define mod 1000000007
        while(i<m-1 && j<n-1)
        {

            if(hor[i]>=ver[j])
            {
                cost = (cost%mod + (hor[i]*v)%mod)%mod;

                h++;
                i++;
            }
            else
            {
                cost = (cost%mod + (ver[j]*h)%mod)%mod;

                v++;
                j++;
            }

        }
        while(i<m-1)
        {
            cost = cost + hor[i]*v;
            i++;
        }
        while(j<n-1)
        {
            cost = cost + ver[j]*h;
            j++;
        }

        cout<<cost<<endl;

    }
}



#include<bits/stdc++.h>


typedef long long int ll;

void solve()
{
    ll N,M;
    ll x,prefix=0,maxim=0;
    cin>>N>>M;
    set<ll> S;
    S.insert(0);
    for(int i=1;i<=N;i++){
        cin>>x;
        prefix = (prefix + x)%M;
        maxim = max(maxim,prefix);
        set<ll>::iterator  it = S.lower_bound(prefix+1);
        if( it != S.end() ){
            cout<<"hello"<<*it<<endl;
            maxim = max(maxim,prefix - (*it) + M );
        }
        S.insert(prefix);
    }
    cout<<maxim<<endl;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)  solve();
    return 0;
}
