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

struct node
{
    int x,y,step;
};

char arr[3][3] = {{'@','.','.'},{'.','*','.'},{'.','#','.'}};
int visited[3][3];

void findshortestpath(int a, int b, int n)
{
    node start;
    node now,next;
    start.x = a;
    start.y = b;
    start.step = 0;
    queue<node>q;
    q.push(start);
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};

    memset(visited,0,sizeof(visited));
    visited[a][b] = 1;
    while(!q.empty())
    {
        now = q.front();
        cout<<now.x<<" "<<now.y<<endl;
        q.pop();
        if(arr[now.x][now.y]=='#')
        {
            cout<<"min distance is "<<now.step<<endl;

        }
        else
        {
            for(int i = 0;i<4;i++)
            {
                next.x = now.x + dx[i];
                next.y = now.y + dy[i];
                next.step = now.step +1;
                if(next.x<0 || next.x>=n || next.y<0 || next.y>=n || arr[next.x][next.y]=='*')
                    continue;
                if(arr[next.x][next.y]=='.' && !visited[next.x][next.y])
                {
                    visited[next.x][next.y] = 1;

                    q.push(next);
                }
                if(arr[next.x][next.y]=='#' && !visited[next.x][next.y])
                {
                    visited[next.x][next.y] = 1;

                    q.push(next);
                }
            }

        }
    }
}

void printtheoccurences()
{
    int i,j;
    i = 0;
    int first;
    string a = "10011abc10000001";
    int n = a.size();
    int count = 0;
    while(i<n)
    {
        if((a[i]=='0' && first==0) )
        {
            i++;
        }
        else if(isalpha(a[i]))
        {
            first = 0;
            i++;
        }
        else if(a[i]=='1' && first==0)
        {
            first = 1;
            i++;
        }
        else if((a[i]=='0' && first==1))
        {
            i++;
        }

        else if(first == 1 && a[i]=='1')
        {
            count++;
            i++;
        }

    }

    cout<<"The total count is "<<count<<endl;
}



int main()
{
    register int x ;
    cout<<sizeof('a');
    cout<<x<<endl;
    return 0;
}

