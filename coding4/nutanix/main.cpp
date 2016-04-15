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
    int data;
    node*left;
    node*right;
};

node *newnode(int data)
{
    node *n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int searchinin(int *in, int el, int start,int end)
{
    for(int i = start;i<=end;i++)
    {
        if(in[i]==el)
            return i;
    }
}

void printpostorder(node *root)
{
    if(root==NULL)
        return ;
    printpostorder(root->left);
    printpostorder(root->right);
    cout<<root->data<<" ";
}

node* constructtree(int *in, int*pre, int start, int end, int size)
{
    if(start>end)
    {
        return NULL;
    }

    static int preindex = 0;
    node * root = newnode(pre[preindex]);

    preindex++;

    if(start==end)
        return root;
    int index = searchinin(in, root->data, start,end);

    root->left = constructtree(in,pre,start,index-1,size);
    root->right = constructtree(in,pre,index+1,end,size);
    return root;
}

struct cell
{
    int steps;
    int x,y;
};


void minimumstepstoreachwithbfs()
{
    queue<cell>q;
    cell start,now,next;
    start.x = 0;
    start.y = 0;
    start.steps = 0;
    q.push(start);
    int row[] = {1,-1,0,0};
    int col[] = {0,0,1,-1};
    while(!q.empty())
    {
        now = q.front();
        q.front();
        q.pop();
        if(now.x==s && now.y==d)
        {
            cout<<"Reached "<<now.steps<<endl;
            break;
        }
        else
        {
            for(int i =0;i<4;i++)
            {
                next.x = now.x + row[i];
                next.y = now.y + col[i];
                next.steps = now.steps +1;
                if(next.x<0 || next.y<0 || next.x>3 || next.y>3 ||
                        arr[next.x][next.y]==0)
                    continue;
                else if(!visited[next.x][next.y] && arr[next.x][next.y]==1)
                {
                    visited[next.x][next.y] = 1;
                    q.push(next);

                }
            }
        }

    }

}

void minimumstepstoreachusingdp()
{
    int table[3][3];


    for(int i =0;i<3;i++)
    {
        if(arr[0][i]==1)
        {
            table[0][i] = i;
        }
        else if(arr[0][i]==0)
        {
            table[0][i] = -1;
        }
    }

    for(int i =0;i<3;i++)
    {
        if(arr[i][0]==1)
        {
            table[i][0] = i;
        }
        else if(arr[i][0]==0)
        {
            table[i][0] = -1;
        }
    }


    for(int i =1;i<3;i++)
    {
        for(int j =1;j<3;j++)
        {
            if(arr[i][j]==0)
            {
                table[i][j]=-1;
                continue;

            }
            else
            {
                if(table[i][j-1]!=-1 &&table[i-1][j]!=-1 && table[i-1][j-1]!=-1 )
                table[i][j] = min(table[i][j-1],min(table[i-1][j],table[i-1][j-1])) +1;
                else if(table[i][j-1]==-1 && table[i-1][j]>0 &&table[i-1][j-1]>0)
                {
                    table[i][j] = min(table[i-1][j],table[i-1][j-1]) +1;
                }
                else if(table[i][j-1]>0 && table[i-1][j]==-1 &&table[i-1][j-1]>0)
                {
                    table[i][j] = min(table[i-1][j],table[i-1][j-1]) +1;
                }
                else if(table[i][j-1]>0 && table[i-1][j]==-1 &&table[i-1][j-1]>0)
                {
                    table[i][j] = min(table[i-1][j],table[i-1][j-1]) +1;
                }
                else
                    table[i][j] = -1;
            }
        }
    }


}


int main()
{
    int in [] = {4,2,5,1,6,3,7};
    int pre[] = {1,2,4,5,3,6,7};

    node * root = constructtree(in,pre,0,6,7);
    printpostorder(root);
    return 0;
}

