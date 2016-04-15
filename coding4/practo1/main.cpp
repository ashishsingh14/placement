#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int compare(string a, string b)
{
    return a.size()>b.size();
}

bool checkifnext(string a, string b)
{
    if(a.size()-b.size()>1)
    {
        return false;
    }
    else if((a.size()-b.size())==1)
    {
        int i,j;
        i = j = 0;
        for(j = 0;j<a.size() && i<b.size();j++)
        {
            if(a[j]==b[i])
            {
                i++;
            }


        }
        return i==b.size();
    }
    else
        return false;
}

void longestchain()
{
    string s [] = {"bdca", "bda","bca","ba","b","a"};
    int n = sizeof(s)/sizeof(s[0]);
    sort(s,s+n,compare);

    map<string,vector<string > > m;


    for(int i =0;i<n-1;i++)
    {
        for(int j =i+1;j<n;j++)
        {
            if(checkifnext(s[i],s[j]))
            {
                m[s[i]].push_back(s[j]);
            }
        }
    }

    map<string,vector<string > > ::iterator i;

    for(i = m.begin();i!=m.end();i++)
    {
        vector<string>::iterator j;
        cout<<i->first<<"->";
        for(j = i->second.begin();j!=i->second.end();j++)
        {
            cout<<*j<<" ";
        }
        cout<<endl;
    }

    map<string, int> visited;
    map<string,int> distance;
    int ans = INT_MIN;
    for(int i =0;i<n;i++)
    {
        queue<string>q;

        q.push(s[i]);
        visited[s[i]] = 1;
        distance[s[i]] = 1;

        while(!q.empty())
        {
            string top = q.front();
            q.pop();
            vector<string>::iterator j;
            for(j = m[top].begin();j!=m[top].end();j++)
            {
                if(visited[*j]==0)
                {
                    visited[*j] = 1;
                    distance[*j] = distance[top] + 1;
                    ans = max(distance[*j], ans);
                    q.push(*j);
                }
            }

        }
        visited.clear();
        distance.clear();

    }

    cout<<"answer is "<<ans<<endl;



}

int main()
{
    longestchain();
    return 0;
}

