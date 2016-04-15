#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void function2()
{
    int cities,query;
    cin>>cities>>query;
    list<int>*adjacency = new list<int>[cities];
    int city_a, city_b;
    for(int i =0;i<cities-1;i++)
    {
        cin>>city_a>>city_b;
        adjacency[city_a-1].push_back(city_b-1);
        adjacency[city_b-1].push_back(city_a-1);
    }


    int query1,query2;
    int distance_bfs[cities];
    bool visited_bfs[cities];
    bool festive_bfs[cities];
    for(int l =0;l<cities;l++)
    {
		festive_bfs[l] = false;	
    }
    while(query--)
    {
        cin>>query1>>query2;
        queue<int>q;
        query2 = query2-1;

	for(int l =0;l<cities;l++)
	{
	distance_bfs[l] = 0;
	visited_bfs[l] = false;
	}
       
        festive_bfs[0] = true;
        if(query1==1)
        {
            festive_bfs[query2] = true;
            continue;
        }
        else if(query1==2 && festive_bfs[query2]==true)
        {
            cout<<"0"<<endl;
            continue;
        }
        else if(query1==2 && festive_bfs[query2]==false)
        {
            q.push(query2);
            visited_bfs[query2] = true;;
            distance_bfs[query2]  = 0;
            int finalanswer = -1;
            while(!q.empty())
            {
                int t = q.front();
                q.pop();
                if(festive_bfs[t])
                {
                    finalanswer = distance_bfs[t];
                    break;
                }
                list<int>::iterator i;
                for(i = adjacency[t].begin();i!=adjacency[t].end();i++)
                {
                    if(!visited_bfs[*i])
                    {
                        visited_bfs[*i] = true;
                        distance_bfs[*i] = distance_bfs[t] + 1;
                        q.push(*i);
                    }
                }
            }
            cout<<finalanswer<<endl;
        }

    }


}



int main()
{
    function2();
    return 0;
}


