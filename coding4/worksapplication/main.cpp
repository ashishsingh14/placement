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
#define size 50
int m,n;
int row[] = {1,-1,0};
int col[] = {0,0,1};
int dp[size][size];

long long int answer = -1;

int helperutil2(int arr[size][size], bool visited[size][size], long long int value, int i, int j)
{

    if(j==n-1 && value>answer)
    {
        answer = value;
    }

    //cout<<"current "<<i<<" "<<j<<endl;

    for(int k =0;k<3;k++)
    {
        int nextx = i + row[k];
        int nexty = j + col[k];
        bool raise= false;
        if(nextx==-1)
        {
            raise = true;
            nextx = n-1;

        }
        if(nextx==n)
        {
            raise = true;
            nextx = 0;
        }
        if(nexty==m || arr[nextx][nexty]==-1 ||  visited[nextx][nexty])
            continue;
        visited[nextx][nexty] = true;

        if(raise)
        {
            //cout<<"next with flag "<<nextx<<" "<<nexty<<endl;

            helperutil2(arr,visited,arr[nextx][nexty],nextx,nexty);
        }

        else
        {
            //cout<<"next without flag "<<nextx<<" "<<nexty<<endl;

            helperutil2(arr,visited,value + arr[nextx][nexty],nextx,nexty);
        }

        visited[nextx][nexty] = false;

    }
}


int helperutil(int arr[size][size], bool visited[size][size], int i, int j)
{
    visited[i][j] = 1;
    cout<<"Setting visited true for"<<i<<"and "<<j<<endl;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans = arr[i][j];
    int save = arr[i][j];
    int temp = INT_MIN;
    if(j==m-1)
    {
        static int lastrow[] = {-1,1};

        for(int k =0;k<2;k++)
        {
            int nextx = (i + lastrow[k])%n;
            if(nextx<0)
                nextx = nextx + n;
            if(nextx>=0 && nextx<n && j>=0 && j<m && arr[nextx][j]!=-1
                    && !visited[nextx][j])
            {
                if((i==0 && nextx==n-1) || (i==n-1 && nextx==0))
                {
                    ans = 0;
                    save = 0;
                }
                temp = max(temp,helperutil(arr,visited,nextx,j));
                ans = max(ans, save + temp);
                cout<<"coming"<<ans<<endl;

            }

        }
    }
    else
    {
        for(int k =0;k<3;k++)
        {
            int nextx;

            nextx = (i + row[k])%n;
            if(nextx<0)
                nextx = nextx + n;

            int nexty = j + col[k];

            if(nextx<n && nextx>=0 && nexty>=0 &&
                    nexty<m && arr[nextx][nexty]!=-1 &&  !visited[nextx][nexty])
            {
                if((i==0 && nextx==n-1) || (i==n-1 && nextx==0))
                {
                    ans = 0;
                    save = 0;
                }

                cout<<"Callig for "<<nextx<<"and "<<nexty<<endl;
                temp = max(temp,helperutil(arr,visited,nextx,nexty));
                ans = max(ans, save + temp);

                cout<<"coming here"<<ans<<endl;
            }
        }
    }
    return dp[i][j] = ans;

}

void function1()
{
    cin>>n>>m;
    int arr[size][size];
    for(int i =0;i<n;i++)
        for(int j =0;j<m;j++)
            cin>>arr[i][j];


    bool visited[size][size];
    memset(visited,false,sizeof(visited));
    for(int i =0;i<n;i++)
    {
        if(arr[i][0]!=-1 && !visited[i][0]){
            //cout<<"Calling main helper"<<endl;
            visited[i][0] = true;
            helperutil2(arr,visited,arr[i][0],i,0);
            visited[i][0] = false;
        }

    }

   cout<<answer<<endl;
}



void function2()
{
    int n,m;
    cin>>n>>m;
    list<int>*adj = new list<int>[n];
    int a,b;
    for(int i =0;i<n-1;i++)
    {
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }


    int x,y;
    int distance[n];
    bool visited[n];
    bool festive[n];
    memset(festive,false,sizeof(festive));
    while(m--)
    {
        cin>>x>>y;
        queue<int>q;
        y = y-1;
        memset(distance,0,sizeof(distance));
        memset(visited,false,sizeof(visited));
        festive[0] = true;
        if(x==1)
        {
            festive[y] = true;
            continue;
        }
        else if(x==2 && festive[y]==true)
        {
            cout<<"0"<<endl;
            continue;
        }
        else if(x==2 && festive[y]==false)
        {
            q.push(y);
            visited[y] = true;;
            distance[y]  = 0;
            int ans = -1;
            while(!q.empty())
            {
                int top = q.front();
                q.pop();
                if(festive[top])
                {
                    ans = distance[top];
                    break;
                }
                list<int>::iterator i;
                for(i = adj[top].begin();i!=adj[top].end();i++)
                {
                    if(!visited[*i])
                    {
                        visited[*i] = true;
                        distance[*i] = distance[top] + 1;
                        q.push(*i);
                    }
                }
            }
            cout<<ans<<endl;
        }

    }


}



int main()
{
    function1();
    return 0;
}

