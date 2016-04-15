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
#include <set>
using namespace std;

//int count( vector<long long int>cg, long long int m, long long int n)
//{
//    // If n is 0 then there is 1 solution (do not include any coin)
//    if (n == 0)
//        return 1;

//    // If n is less than 0 then no solution exists
//    if (n < 0)
//        return 0;

//    // If there are no coins and n is greater than 0, then no solution exist
//    if (m <=0 && n >= 1)
//        return 0;

//    // count is sum of solutions (i) including S[m-1] (ii) excluding S[m-1]
//    return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
//}

void gfiles()
{
    int t;
    cin>>t;
    int c =0;
    while(t--)
    {
        vector<long long int> p;
        vector<long long int>d;
        c++;
        int n;
        cin>>n;
        long long int a,b;
        for(int i =0;i<n;i++)
        {
            cin>>a>>b;
            p.push_back(a);
            d.push_back(b);
        }

        map<int , set<long long int> >m;
        m[p[0]].insert(d[0]);
        long long int ans = d[0];
        for(long long int i = 1;i<p.size();i++)
        {
            ans += d[i]-d[i-1];
            m[p[i]-p[i-1]].insert(d[i]-d[i-1]);
        }

//        map<int , set<long long int> >::iterator i;
//        for(i = m.begin();i!=m.end();i++)
//        {
//            set<long long int> ::iterator j;
//            cout<<i->first<<" ";
//            for(j=(i->second.begin());j!=(i->second.end());j++)
//                cout<<*j<<" ";
//            cout<<endl;
//        }

        int rem = 100 - p[p.size()-1];
//        vector<long long int> cg;
//        for(i = m.begin();i!=m.end();i++)
//        {
//            if(i->first<=rem)
//                cg.push_back(i->first);
//        }

        if(rem==0)
        {
            cout<<"Case #"<<c<<": "<<ans<<endl;
            continue;
        }
        if(m[rem].size()==1)
        {
            cout<<"Case #"<<c<<": "<<ans+(*(m[rem].begin()))<<endl;
            continue;
        }
        if(m[rem].size()>1)
        {
            cout<<"Case #"<<c<<": -1"<<endl;
            continue;
        }
        if(m[rem].size()==0)
        {
            cout<<"Case #"<<c<<": -1"<<endl;
            continue;
       }

    }
}

int minimum(int a, int b)
{
    return a<b?a:b;
}

void granks()
{
    int t;
    cin>>t;
    int ca =0;
    while(t--)
    {
        ca++;
        int p;
        cin>>p;
        long long int points[p+1];
        for(int i = 1;i<=p;i++)
        {
            cin>>points[i];
        }

        int n;
        cin>>n;
        int weight[n+1];
        map<string, vector<int> >m;
        int c = 0;
        string player;
        for(int i = 1;i<=n;i++)
        {
            cin>>weight[i];
            for(int j = 1;j<=p;j++)
            {
                c++;
                cin>>player;
                m[player].push_back(weight[i] * points[j]);
            }

        }

        int q;
        cin>>q;

        map<string,vector<int> >::iterator i;

        map<int,vector<string> rank;
        int l;
        long long ans =0;
        for(i = m.begin();i!=m.end();i++)
        {
            vector<int> mt = i->second;
            sort(mt.begin(),mt.end());
            //cout<<i->first<<" ";

            for(l =0;l<minimum(q,mt.size());l++)
            {
                //cout<<*j<<" ";
                ans = ans + mt[l+mt.size()-1];

            }
            ans = -1 * ans;
            rank[ans].push_back(i->first);
            ans = 0;
            //cout<<endl;
        }



        cout<<"Case #"<<ca<<":"<<endl;
        map<int,vector<string> > ::iterator k;
        int cur = 1;

        for(k=rank.begin();k!=rank.end();k++)
        {
            //num++;
            vector<string> mk = i->second;
            sort(mk.begin(), mk.end());
            int sz = mk.size();
            for(int p = 0;p<sz;p++)
                cout<<cur<<": "<<mk[p]<<endl;
            c = c+sz;

        }
        //cout<<endl;

    }
}

int main()
{
    granks();
//    map<int,set<int> >m;
//    m[0].insert(5);
//    m[0].insert(10);

//    map<int , set<int> >::iterator i;
//    for(i = m.begin();i!=m.end();i++)
//    {
//        set<int> ::iterator j;
//        for(j=(i->second.begin());j!=(i->second.end());j++)
//        cout<<"j "<<*j<<endl;
//    }

    return 0;
}

