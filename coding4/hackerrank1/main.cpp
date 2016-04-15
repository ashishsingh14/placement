#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <map>
#include <limits.h>
#define mod 1000000007
using namespace std;

void monkandhisfriends()
{
    int n,m,t;
    cin>>t;
    while(t--)
    {

        cin>>n>>m;
        long long int a;
        vector<long long int>c;
        set<long long int> s;
        for(int i =0;i<n;i++)
        {
            scanf("%d",&a);
            s.insert(a);

        }

        for(int i =0;i<m;i++)
        {
            scanf("%d",&a);
            c.push_back(a);

        }


        for(int i =0;i<c.size();i++)
        {
            if(s.find(c[i])!=s.end())
            {
                cout<<"YES"<<endl;
            }
            else
                cout<<"NO"<<endl;
            s.insert(c[i]);
        }

    }
}



void monkandcandybags()
{
    int t;
    cin>>t;
    long long int a;

    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<long long int>c;
        for(int i =0;i<n;i++)
        {
            scanf("%lld",&a);
            c.push_back(a);

        }

        make_heap(c.begin(),c.end());
        long long ans =0;
        for(int i =0;i<k;i++)
        {
            long long int temp = c.front();
            cout<<temp<<endl;
            ans += temp;
            pop_heap(c.begin(),c.end());
            c.pop_back();
            c.push_back(floor(temp/2));
            push_heap(c.begin(),c.end());

        }
        cout<<ans<<endl;
    }
}

bool compare(int a, int b)
{
    return a>b?true:false;
}

bool comparepair(pair<string, int> a, pair<string, int> b)
{
    if(a.second==b.second)
    {
         if(a.first.compare(b.first)>0)
         {
             return 0;
         }
         else
             return 1;

    }
    else
        return a.second>b.second;
}

void monkanclassmark()
{
    int t;
    cin>>t;

    vector< pair<string,int> > v;
    string s;
    int n;
    for(int j =0;j<t;j++)
    {
        cin>>s>>n;
        v.push_back(make_pair(s,n));
    }
    sort(v.begin(),v.end(),comparepair);
    vector< pair<string,int> >::iterator i;
    for(i = v.begin();i!=v.end();i++)
    {
        cout<<((*i).first)<<" "<<((*i).second)<<endl;
    }
}

void monkparty()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<string,int>m;
        string a;
        while(n--)
        {
            cin>>a;
            m[a]++;
        }

        map<string,int>::iterator i;
        for(i = m.begin();i!=m.end();i++)
        {
            cout<<i->first<<endl;
        }
    }
}

void pokemons()
{
    int t;
    cin>>t;
    while(t--)
    {
        map<int,int> m;
        int n,a,b;
        cin>>n;
        long long int ans =0;
        for(int i =0;i<n;i++)
        {
            cin>>a>>b;
            if(a!=b)
            {
                if(m[b]==0)
                    ans++;
                else
                    m[b]--;
            }
            m[a]++;
        }


        cout<<ans<<endl;
    }
}
void multiply(int a[26][26], int b[26][26])
{
    int c[26][26];
    for(int i =0;i<26;i++)
        for(int j =0;j<26;j++)
        {
            for(int k =0;k<26;k++)
            {
                c[i][j] += a[i][k] * b[k][j];
                if(c[i][j]>=mod)
                    c[i][j] = c[i][j]%mod;
            }
        }
    for(int i =0;i<26;i++)
        for(int j =0;j<26;j++)
            a[i][j] = c[i][j];

}

void calculatepower(int a[26][26],int n)
{
    int c[26][26];
    for(int i =0;i<26;i++)
        c[i][i] = 1;
    while(n)
    {
        if(n&1)
        {
            multiply(c, a);
        }
        multiply(a,a);
        n = n/2;
    }
    for(int i =0;i<26;i++)
        for(int j =0;j<26;j++)
            a[i][j] = c[i][j];
}

void pkandinteresting()
{
    int t;
    int a[26][26],c[26][26];
    for(int i =0;i<26;i++)
        for(int j =0;j<26;j++)
        {
            cin>>a[i][j];
            c[i][j] = a[i][j];
        }
    long long ans = 0;

    cin>>t;
    char z;
    long long int len;
    while(t--)
    {
        cin>>z>>len;
        int col = z-'a';
        if(len==1)
        {
            cout<<"1"<<endl;
        }
        else if(len==2)
        {
            for(int i =0;i<26;i++)
            {
                if(a[i][col])
                {
                    ans = ans + a[i][col];
                    ans = ans%mod;
                }
            }
            cout<<ans<<endl;

        }
        else
        {
            calculatepower(a, len-1);
            for(int i =0;i<26;i++)
            {
                if(a[i][col])
                {
                    ans = ans + a[i][col];
                    ans = ans%mod;
                }
            }
            cout<<ans<<endl;

        }

    }

}

int findleader(int *parent, int i)
{

    if(parent[i]==-1)
        return i;
    findleader(parent,parent[i]);
}

void changeleader(int *parent, int i)
{
    int x = findleader(parent,i);
    if(x==i)
        return;
    else
    {
        parent[x] = i;
        parent[i] = -1;
    }

}

void uniongroup(int *parent, int a, int b)
{
    int x = findleader(parent,a);
    int y = findleader(parent, b);
    if(x==y)
        return;
    parent[x] = y;
}


void cityandsoldiers()
{
    int n,q;
    cin>>n>>q;
    int parent[100005];

    for(int i =1;i<=n;i++)
        parent[i] = -1;

    for(int i =0;i<q;i++)
    {
       int a,b,c;

       cin>>a;
       if(a==1)
       {
            cin>>b>>c;
            uniongroup(parent,b,c);
       }
       else if(a==2)
       {
            cin>>b;
            changeleader(parent, b);
       }
       else{
            cin>>b;
            cout<<findleader(parent,b)<<endl;

        }
    }
}

void cityandcampers()
{
    int n,q;
    cin>>n>>q;
    int parent[100005];

    for(int i =1;i<=n;i++)
        parent[i] = -1;
    for(int i =0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        uniongroup(parent,a,b);
        int ma,mi;
        ma = INT_MIN;
        mi = INT_MAX;
        map<int,int>m;
        vector<int> v(n+1,0);
        for(int i =1;i<=n;i++)
        {

            int p = findleader(parent, i);
            //m[p]++;
            v[p]++;
        }

        vector<int>::iterator j;
        //make_heap(v.begin(),v.end());
        sort(v.begin(),v.end(),compare);
//        int diff = INT_MAX;
//        for(j = 1;j<v.size();j++)
//        {
//            if(v[j]!=0)
//                diff = min(diff, v[j]-v[j]);
//        }



    }
}

void cityandfireman()
{
    int n;
    cin>>n;
    int risk[1003];
    int parent[1004];
    int copy[1004];


    for(int i =1;i<=n;i++)
        parent[i] = -1;

    for(int i =1;i<=n;i++)
        cin>>risk[i];
    int k;
    cin>>k;
    int a,b;
    for(int i =0;i<k;i++)
    {
        cin>>a>>b;
        uniongroup(parent,a,b);
    }

    long long int ans =1;

    map<int,multiset<int> > m;
    for(int i =1;i<=n;i++)
        copy[i] = findleader(parent,i);

    for(int i =1;i<=n;i++)
        cout<<i<<" "<<copy[i]<<endl;

    for(int i =1;i<=n;i++)
        m[copy[i]].insert(risk[i]);

    map<int,multiset<int> >::iterator i;

    for(i = m.begin();i!=m.end();i++)
    {
        int low = *(i->second.begin());
        i->second.erase(i->second.begin());

        int count = 1;
        //cout<<"low"<<low;
        //cout<<i->first<<"->";
        multiset<int>::iterator j;
        for(j = i->second.begin();j!=i->second.end();j++)
        {
            if(*j!=low)
                break;
//            cout<<"ashish";
//            cout<<*j<<endl;
            count++;


        }
        ans = (ans *count)%mod;
    }


    cout<<ans<<endl;

}


void cityandflood()
{
    int n;
    cin>>n;

    int parent[1004];



    for(int i =1;i<=n;i++)
        parent[i] = -1;


    int k;
    cin>>k;
    int a,b;
    for(int i =0;i<k;i++)
    {
        cin>>a>>b;
        uniongroup(parent,b,a);
    }

    map<int,int> m;
    for(int i =1;i<=n;i++)
    {

        int p = findleader(parent, i);
        //m[p]++;
        m[p]++;
    }
    long long int ans =0;
    map<int,int>::iterator i;
    for(i = m.begin();i!=m.end();i++)
    {
        if(i->second!=0)
            ans++;
    }
    cout<<ans<<endl;

}

int main()
{

    //monkanclassmark();
//    vector<int>v;
//    v.push_back(12);
//    v.push_back(1);
//    sort(v.begin(),v.end(),compare);
//    cout<<v.front()<<endl;

    cityandflood();
    return 0;
}
