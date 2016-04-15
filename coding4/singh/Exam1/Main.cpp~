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
int row[] = {1,-1,0};		// the valid moves for the snake in the up, down and right direction
int col[] = {0,0,1};
int dp[size][size];
long long int answer = -1;
int snake(int inputmatrix[size][size], bool visited[size][size], long long int value, int i, int j)
{

    if(j==n-1 && value>answer)
    {
        answer = value;				//if we reach the last column update the maximum value for the snake
    }

    for(int k =0;k<3;k++)
    {
        int nextx = i + row[k];			// calculate the next cordinates of the snake 
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
        if(nexty==m || inputmatrix[nextx][nexty]==-1 ||  visited[nextx][nexty])		// check for the next valid coordinates of the cell
            continue;
        visited[nextx][nexty] = true;

        if(raise)
        {									// raise variable is used to check the wrap of the cell from bottom to top or vise versa
            
            snake(inputmatrix,visited,inputmatrix[nextx][nexty],nextx,nexty);
        }

        else
        {
            
            snake(inputmatrix,visited,value + inputmatrix[nextx][nexty],nextx,nexty);
        }

        visited[nextx][nexty] = false;

    }
}

void callingsnake()
{
    cin>>n>>m;
    int inputmatrix[size][size];
    for(int i =0;i<n;i++)
        for(int j =0;j<m;j++)
            cin>>inputmatrix[i][j];
    bool visited[size][size];
    memset(visited,false,sizeof(visited));  // visited matrix is created to visit each vertex only one time
    for(int i =0;i<n;i++)
    {
        if(inputmatrix[i][0]!=-1 && !visited[i][0]){   // check if it is a valid cell and not visited
            visited[i][0] = true;
            snake(inputmatrix,visited,inputmatrix[i][0],i,0);
            visited[i][0] = false;		// reset the value for the next iteration
        }

    }

   cout<<answer<<endl;
}

int main()
{
    callingsnake();
    return 0;
}

