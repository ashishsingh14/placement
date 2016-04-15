#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define size 1001

int arr[size][size];
bool visited[size][size];
int r,c;

void dfs(int i, int j)
{
    static int row[] = {1,0,-1,0};
    static int col[] = {0,1,0,-1};
    //cout<<"coming here "<<i<<" "<<j<<endl;
    visited[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int nextx = i + row[k];
        int nexty = j + col[k];
        if(nextx>=0 && nextx<r && nexty>=0 && nexty<c && !visited[nextx][nexty]
                && arr[nextx][nexty]==1)
        {
            dfs(nextx, nexty);
        }
    }
}

void solve()
{
    int t;
    cin>>t;
    int count = 0;
    while(t--)
    {
        count++;
        cin>>r>>c;
        for(int i =0;i<r;i++)
            for(int j =0;j<c;j++)
            {
                char p;
                cin>>p;
                arr[i][j] = p-'0';
            }
    int n ;
    cin>>n;
    cout<<"Case #"<<count<<":"<<endl;
    while(n--)
    {
        char o;
        int a,b;
        int z;

        cin>>o;

        if(o=='M')
        {
            cin>>a>>b>>z;
            arr[a][b] = z;
        }       
        else if(o=='Q')
        {
            memset(visited,false,sizeof(visited) );
            long long int count =0;
            for(int i =0;i<r;i++)
            {
                for(int j =0;j<c;j++)
                {
                    if(arr[i][j]==1 && !visited[i][j])
                    {
                        dfs(i,j);
                        count++;
                    }
                }
            }

            cout<<count<<endl;
        }


    }
}


}

int main()
{
    solve();
    return 0;
}

