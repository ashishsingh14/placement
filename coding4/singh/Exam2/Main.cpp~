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

/*

The function uses the standard BFS Algorithm to calculate the shortest distance to the nearest festive city.
The graph is taken as input using the STL container in C++ throught list container. In this code the indexing starts from the index 0.
For each query the answer is displayed on the screen for query type 2
*/


void festivecitycelebration()
{
    int n,m;
    cin>>n>>m;
    list<int>*adj = new list<int>[n];  // adjacency list representation of the graph using the list
    int a,b;
    for(int i =0;i<n-1;i++)
    {
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }


    int x,y;
    int distance[n];
    bool visited[n];  // distance and visited boolean array to keep track of the visited and the shortest distance from the source
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
            while(!q.empty()) 			// loop while the queue is not empty
            {
                int top = q.front();		
                q.pop();
                if(festive[top])		// if the city popped is festice city break the loop as we have reached shortest distance festive city from the given source
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
    festivecitycelebration();
    return 0;
}


