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
#include <ctype.h>
#define mod 1000000007
using namespace std;

int arr[101][101][256];
char input[101][101];

struct position
{
    int x,y;
    int steps;
    int key;
};

void bfslandmine(int m, int n, int st, int end)
{
    queue<position> q;

    position start, next,now;
    start.x = st;
    start.y = end;
    start.steps = 0;
    start.key = 0;
    q.push(start);
    int row[] = {0,1,0,-1};
    int col[] = {1,0,-1,0};
    char key[4]={'b','y','r','g'};
    char door[4]={'B','Y','R','G'};
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        if(input[now.x][now.y]=='X')
        {
            cout<<now.steps<<endl;
            return;
        }
        cout<<"as\n";
        for(int i =0;i<4;i++)
        {
            next.x = now.x + row[i];
            next.y = now.y + col[i];
            next.key = now.key;
            next.steps = now.steps + 1;
        if(next.x<0 || next.y<0 || next.x>=m || next.y>=n || input[next.x][next.y]=='#'
                ||arr[next.x][next.y][next.key])
        {
            continue;
        }

            else if(isupper(input[next.x][next.y]) && input[next.x][next.y]!='X')
            {
                for(int k =0;k<4;k++)
                {
                    if(input[next.x][next.y]==door[k])
                    {
                        if((1<<k) & next.key)
                        {
                            arr[next.x][next.y][next.key]++;
                            q.push(next);

                        }

                    }

                }
            }

            else if(islower(input[next.x][next.y]))
            {
                for(int k =0;k<4;k++)
                {
                    if(input[next.x][next.y]==key[k])
                    {
                        if((1<<k & next.key)==0)
                        {
                            next.key += 1<<k;

                        }
                    arr[next.x][next.y][next.key] = 1;
                    q.push(next);
                    }

                }
            }
            else
            {
                arr[next.x][next.y][next.key] = 1;
                cout<<next.steps<<endl;
                q.push(next);
                cout<<"as dot\n";
            }

        }
    }
    cout<<"-1"<<endl;
    return;

}

void landminesofbyteland()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m, n;
        cin>>m>>n;
        int start,end;
        for(int i =0;i<m;i++)
            for(int j =0;j<n;j++)
            {
                cin>>input[i][j];
                if(input[i][j]='*')
                {
                    start = i;
                    end = j;
                }
            }
        memset(arr,0,sizeof(arr));
        bfslandmine(m,n,start,end);
    }

}

int main()
{
    landminesofbyteland();
    return 0;
}

