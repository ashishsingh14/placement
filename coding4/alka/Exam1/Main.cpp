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
            

            helperutil2(arr,visited,arr[nextx][nexty],nextx,nexty);
        }

        else
        {
            

            helperutil2(arr,visited,value + arr[nextx][nexty],nextx,nexty);
        }

        visited[nextx][nexty] = false;

    }
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
            visited[i][0] = true;
            helperutil2(arr,visited,arr[i][0],i,0);
            visited[i][0] = false;
        }

    }

   cout<<answer<<endl;
}



int main()
{
    function1();
    return 0;
}

