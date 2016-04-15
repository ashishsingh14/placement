#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <map>
#include <limits.h>
#include <queue>
#include <functional>
#include <string.h>
#include <stdlib.h>
#define mod 1000000007
using namespace std;


void monkandmultiplication()
{
    int n;
    cin>>n;
    priority_queue<long long int>q;
    long long int a;
    for(int i =0;i<n;i++)
    {
        scanf("%lld",&a);
        q.push(a);

        if(q.size()<3)
        {
            cout<<"-1"<<endl;
            continue;
        }
        else
        {

           long long int d = q.top();
           q.pop();
           long long int c = q.top();
           q.pop();
           long long int b = q.top();
           q.pop();
           q.push(d);
//           push_heap(v.begin(),v.end());
          q.push(c);
//           push_heap(v.begin(),v.end());
          q.push(b);
//           push_heap(v.begin(),v.end());
           cout<<d*b*c<<endl;

       }

   }
}

void monkandqueries()
{
    int t;
    cin>>t;
    priority_queue <int, vector<int>, greater<int> > q;
    priority_queue <int> r;
    int c[100005];
    memset(c,0,sizeof(c));
    while(t--)
    {
        int a;
        cin>>a;
        int b;
        if(a==1)
        {
            cin>>b;
            q.push(b);
            r.push(b);
            c[b]++;
        }
        else if(a==2)
        {
            cin>>b;
            if(c[b])
            {
                c[b]--;
            }
            else
                cout<<"-1"<<endl;


        }
        else if(a==3)
        {
            while(r.size() && c[r.top()]==0)
                r.pop();
            if(r.size())
                cout<<r.top()<<endl;
            else
               cout<<"-1"<<endl;
        }
        else if (a==4)
        {
            while(q.size() && c[q.top()]==0)
                q.pop();
            if(q.size())
                cout<<q.top()<<endl;
            else
               cout<<"-1"<<endl;
        }
    }
}


void monkandchampionleagues()
{
    int m,n;
    cin>>m>>n;
    priority_queue<int> q;
    int a;
    for(int i =0;i<m;i++)
    {
        cin>>a;
        q.push(a);
    }

    long long ans =0;
    for(int i =0;i<n;i++)
    {
        int b = q.top();
        ans += b;
        q.pop();
        b  = b-1;
        q.push(b);
    }
    cout<<ans<<endl;
}

void monkandiq()
{
    int c,p,n;
    cin>>c>>p>>n;

    int courses[100002];
    memset(courses,0,sizeof(courses));

    int done[100002];
    int notdone[100002];

    for(int i = 1;i<=n;i++)
    {
        cin>>done[i];
        courses[i]++;
    }

    for(int i = 1;i<=p;i++)
    {
        cin>>notdone[i];
    }

    vector<int, priority_queue<int> > v;






}

int main()
{
    monkandchampionleagues();

//    vector<long long int>v;
//    v.push_back(4);
//    v.push_back(6);
//    v.push_back(1);
//    v.push_back(8);
//    make_heap(v.begin(),v.begin()+2);
//    cout<<v.front()<<endl;
    return 0;
}

