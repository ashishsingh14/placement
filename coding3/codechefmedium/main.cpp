#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void dfs(list<int>*adj,int s, int *visited)
{
    visited[s] = 1;
    list<int>::iterator i;

        for(i = adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i] = 1;
                dfs(adj,*i,visited);
            }
        }

}

void orderingpossible()
{
    int t,n;
    cin>>t;
    list<int>*adj;
    while(t--)
    {

        cin>>n;
        adj = new list<int>[26];
        string s[n];
        int vertices =0;
        for(int i =0;i<n;i++)
        {
            cin>>s[i];
            int l = s[i].size();
            adj[s[i][0]-'a'].push_back(s[i][l-1]-'a');

        }
        for(int j =0;j<26;j++)
        {
            list<int>::iterator i;
            if(adj[j].size()!=0)
            {
                vertices++;
//                cout<<j<<"->";
//                for(i = adj[j].begin();i!=adj[j].end();i++)
//                {
//                    cout<<*i<<" ";
//                }
//                cout<<endl;
            }
        }
        int visited[26];
        int count;
        int flag =0;
        for(int i =0;i<26;i++)
        {
            count=0;
            memset(visited,0,sizeof(visited));
            dfs(adj,i,visited);
            for(int i =0;i<26;i++)
            {
                if(visited[i]==1)
                    count++;
            }
            if(count==vertices)
            {
                cout<<"Ordering is possible."<<endl;
                flag =1;
                break;
            }
        }
        if(flag==0)
            cout<<"The door cannot be opened."<<endl;

    }
}

void dfs(int v, list<int> *adj, int visited[], int &count)
{
    visited[v] = 1;
    count++;
    list<int>::iterator i;
    for(i = adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
        {
            dfs(*i, adj, visited,count);
        }
    }
}



bool ifeulerian(list<int>*adj, int indegree[])
{
    int s,e,odd;
    int visited[26];
    int nodes = 0;
    for(int i =0;i<26;i++)
    {
        visited[i] = 0;

    }
    odd = 0;
    //cout<<"nodes "<<nodes<<endl;
    int flag = 0;
    int p,n;
    p = n = 0;
    int diff;
    for(int i =0;i<26;i++)
    {
        diff = adj[i].size()-indegree[i];
        if(indegree[i]>0 || adj[i].size()>0)
            nodes++;
        if(abs(diff)>1)
        {
            flag = 1;
            break;
        }
        if(diff==1)
        {
            s = i;
            if(p==0)
                p++;
            else
            {
                flag = 1;            
                break;
            }

        }
        else if(diff==-1)
        {
            e = i;
            if(n==0)
                n++;
            else
            {
                flag = 1;
                break;
            }
        }

    }
    if(flag==0)
    {
        int count = 0;
        dfs(s,adj,visited, count);
        if(count==nodes)
            return true;
        else
            return false;
    }
    else
        return false;

}

void playonwords()
{
    int t;
    cin>>t;
    string s;

    while(t--)
    {
        int n;
        cin>>n;
        list<int>*adj = new list<int>[26];
        int indegree[26];
        for(int i =0;i<26;i++)
            indegree[i] = 0;
        while(n--)
        {

            cin>>s;
            int a = s[0]-'a';
            int b = s[s.size()-1]-'a';
            adj[a].push_back(b);
            indegree[b] +=  1;

        }
        if(ifeulerian(adj,indegree))
        {
            cout<<"Ordering is possible."<<endl;
        }
        else
        {
            cout<<"The door cannot be opened."<<endl;
        }
    }


}

int main()
{
    playonwords();
    return 0;
}

