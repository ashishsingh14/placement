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

bool checkifinterleaving(string a, string b, string c, int i, int j, int k)
{
    if(i==a.size() && j==b.size()&& k==c.size())
        return true;
    if(c[k]==a[i] && c[k]==b[j])
    {
        return checkifinterleaving(a,b,c,i+1,j,k+1) || checkifinterleaving(a,b,c,i,j+1,k+1);
    }
    else
    {
        if(i<a.size() && k<c.size() && c[k]==a[i])
            return checkifinterleaving(a,b,c,i+1,j,k+1);

        else if(j<b.size() && k<c.size() && c[k]==b[j])
            return checkifinterleaving(a,b,c,i,j+1,k+1);

    }
    return false;
}

void lengthoflongestvalidsubstring(string b)
{
    int result = 0;
    stack<int>s;
    s.push(-1);

    for(int i =0;i<b.size();i++)
    {
        if(b[i]=='(')
        {
            s.push(i);
        }
        else
        {
            s.pop();
            if(!s.empty())
                result = max(result, i-s.top());
            else
                s.push(i);
        }
    }
    cout<<"The maximum length is "<<result<<endl;
}

void charcount()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        string s3 = s1+s2;
        map<char,int> m;
        for(int i =0;i<s3.size();i++)
        {
            m[s3[i]]++;
        }
        map<char,int>::iterator i;
        i = m.begin();
        int ans = i->first;
        i++;
        char a = '{';
        while(i!=m.end())
        {

            if(ans<=(i->second))
            {
                if(a>(i->first))
                {
                    cout<<i->first<<endl;
                    ans = i->second;
                    a = (char)(i->first);
                }
            }
         i++;
        }
        cout<<a<<endl;
    }
}

void romannumbersystem()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<4)
        {
            cout<<"1"<<endl;
            continue;
        }
        else if(n>=4 && n<9)
        {
            cout<<"2"<<endl;
            continue;
        }
        else if(n>=9 && n<40)
        {
            cout<<"3"<<endl;
            continue;
        }
        else if(n>=40 && n<90)
        {
            cout<<"4"<<endl;
            continue;
        }
        else if(n>=90 && n<400)
        {
            cout<<"5"<<endl;
            continue;
        }
        else if(n>=400 && n<900)
        {
            cout<<"5"<<endl;
            continue;
        }
        else
        {
            cout<<"6"<<endl;
            continue;
        }
    }
}

void optimalsubstringreversal()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int start,end;
        start = end = -1;
        int count = 1;
        for(int i =1;i<s.length();i++)
        {
            if(s[i]==s[0])
                count++;
        }
        if(count==s.size())
        {
            cout<<"0"<<" 0"<<endl;
            continue;
        }
        else
        {
            int l = 0;
            int h = s.size()-1;
            char end = 0;
            char start = 255;

            while(l<h)
            {
                if(end<s[l])
                {
                    end = (int)s[l];
                    l++;
                }
                if(s[h]<start)
                {
                    start = (int)s[h];
                    h--;
                }
            }
            cout<<l<<" "<<h<<endl;
        }
    }
}

void dfs(list<int> *adj, int s, int visited[], int &vertices)
{
    visited[s] = 1;
    vertices++;
    //cout<<s<<" ";
    list<int>::iterator i;
    for(i = adj[s].begin();i!=adj[s].end();i++)
    {
        if(visited[*i]==0)
        {
            dfs(adj, *i, visited,vertices);
        }
    }
}

void fireescaperoutes()
{
    int t;
    cin>>t;
    int n,m;
    while(t--)
    {
        cin>>n>>m;
        list<int>*adj = new list<int>[n];
        int a,b;
        for(int i =0;i<m;i++)
        {
            cin>>a>>b;
            a = a-1;
            b = b-1;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int visited[n];
        int components[n];
        for(int i=0;i<n;i++)
        {
            visited[i] = 0;
        }
        int comp,ver;
        comp = ver = 0;
        for(int i =0;i<n;i++)
        {
            if(visited[i]==0)
            {
                ver = 0;
                dfs(adj, i, visited,ver);
                components[comp] = ver;
                comp++;
            }
        }
        long long int ans = 1;
        #define mod 1000000007
        for(int i = 0;i<comp;i++)
        {
            ans *= components[i];
            ans = ans%mod;
        }
        cout<<comp<<" "<<ans<<endl;

    }
}

void friends()
{
    int n;
    cin>>n;
    int a[n][n];
    int c[n][n];
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cin>>a[i][j];
        }
        cout<<endl;
    }


    long long int ans =0;


    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            c[i][j] = 0;
            for(int k =0;k<n;k++)
            {
                c[i][j] += a[i][k] * a[k][j];
            }
        }
    }

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(i!=j && !a[i][j] && c[i][j])
            {
                ans += 1;
            }
        }
    }

    cout<<ans<<endl;
}

void function1()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int l = s.size();
        int i;
        for(i = l-1;i>0;i--)
        {
            if(s[i]>s[i-1])
            {
                break;
            }
        }
        if(i==0)
        {
            cout<<"no answer\n";
            continue;
        }


        int j = i-1;
        int smallest = i;
        for(int k = i+1;k<l;k++)
        {
            if(s[k]<s[smallest] && s[k]>s[j] )
            {
                smallest = k;
            }
        }

        swap(s[j],s[smallest]);
        sort(s.begin()+i,s.end());

        cout<<s<<endl;
    }
}

void player()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double ans = log(n);
        ans = (double)n*ans;
        cout<<ans<<endl;
    }
}

void sherlockanagram()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        map<string,int>m;
        int l = s.size();
        for(int i =1;i<=l;i++)
        {
            for(int j = 0;j<=l-i;j++)
            {
                string sub = s.substr(j,i);
                sort(sub.begin(),sub.end());
                m[sub]++;
            }
        }

        long long ans =0;
        map<string,int>::iterator i;
        for(i = m.begin();i!=m.end();i++)
        {
            ans += (i->second)*(i->second-1)/2;
        }
        cout<<ans<<endl;
    }
}

int main()
{
//    string a,b,c;
//    a = "abcd";
//    b = "xyz";
//    c = "axybczd";
//    if(checkifinterleaving(a,b,c,0,0,0))
//        cout<<"Possible\n";
//    else
//        cout<<"Not possible\n";

//    string s = "aaa";
//    int x = 0;
//    for(int i =0;i<s.size();i++)
//    {

//        //int b = (int)(s[i]-'a');
//        x = x ^ (int)s[i];

//    }


//    string s = "defgab";
//    sort(s.begin()+1,s.end());
//    cout<<s<<endl;



    unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6},
                               {7, 8, 9}, {10, 11, 12}};
       printf("%d, %d, %d", x+3, *(x+3), *(x+2)+3);

    //cout<<"x "<< x<<endl; next_permutation function call in cpp.
    return 0;
}

