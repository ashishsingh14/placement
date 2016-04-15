#include "functions.h"

Graph::Graph(int v)
{
    this->v = v;
    this->adj = new list<int>[v];
}


void Graph::addedge(int s, int d)
{
    this->adj[s].push_back(d);
    //this->adj[d].push_back(s);
}

void Graph::bfs(int s)
{
    bool * visited = new bool[v];
    for(int i = 0;i<v;i++)
        visited[i] = false;
    queue<int>q;
    q.push(s);
    visited[s] = true;
    list<int>::iterator i;
    int t;
    while(!q.empty())
    {
        t = q.front();
        cout<<t<<" ";
        q.pop();
        for(i = adj[t].begin();i!=adj[t].end();i++)
        {
            if(visited[*i]==false)
            {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
    cout<<endl;
    delete visited;
}

void Graph::dfs()
{
    bool * visited = new bool[v];
    for(int i = 0;i<v;i++)
        visited[i] = false;
    list<int>::iterator i;
     for(int i = 0; i < v; i++)
    {
        if(visited[i]==false)
            dfshelper(i, visited);
    }
    delete visited;
    cout<<endl;
}

void Graph::dfshelper(int s, bool visited[])
{
    visited[s] = true;
    cout<<s<<" ";
    list<int>::iterator i;
    for(i = adj[s].begin();i!=adj[s].end();i++)
    {
        if(visited[*i]==false)
        {
            dfshelper(*i, visited);
        }
    }
}

bool Graph::iscyclic()
{
    bool * visited = new bool[v];
    for(int i = 0;i<v;i++)
        visited[i] = false;
    list<int>::iterator i;
     for(int i = 0; i < v; i++)
    {
        if(visited[i]==false)
            dfshelper(i, visited);
    }
    delete visited;
    cout<<endl;
}

//bool Graph::checkifdone(bool * visited, int n)
//{
//    for(int i = 0;i<n;i++)
//    {
//        for(int j = 0;j<n;j++)
//        {
//            if(*((visited + i*n) +j)==0)
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}

//void Graph::countstepsinmatrix()
//{
//    int n;
//    cin>>n;
//    int **a = new int*[n];
//    for(int i =0;i<n;i++)
//    {
//        a[i] = new int[n];
//    }

//    for(int i =0;i<n;i++)
//    {
//        for(int j =0;j<n;j++)
//            cin>>a[i][j];
//    }

//    bool visited[n][n];
//    memset(visited,0,sizeof(visited));
//    int count = 0;
//    int r,c,flag;
//    flag = 0;
//    for(int i = 0;i<n;i++)
//    {
//        for(int j = 0;j<n;j++)
//        {
//            if(a[i][j]==1)
//            {
//                r = i;
//                c = j;
//                flag=1;
//                break;
//            }
//        }
//        if(flag==1)
//            break;
//    }
//    int count =1;
//    while(!checkifdone((bool*)visited, n))
//    {
//        dfsmatrix(a,i,j,n,(bool*)visited,count);
//    }


//    for(int i =0;i<n;i++)
//    {
//        delete [] a[i];
//    }
//    delete [] a;
//}

//void Graph::countstepsinmatrixhelper(int **a, int i, int j, int n, bool *visited, int count)
//{
//    static int rowNbr[] = {-1, 0, 0, 1};
//    static int colNbr[] = {0, -1, 1, 0};
//    *((visited + i*n) +j) = true;
//    for(int k =0;k<4;k++)
//    {
//        if(issafe(a,i+rowNbr[k],j+colNbr[k],n,visited))
//        {
//            count++;
//            dfsmatrix(a,i+rowNbr[k],j+colNbr[k],n,visited);
//        }
//        else
//            count++;
//    }
//}

//bool Graph::issafecount(int **a, int i , int j, int n, bool *visited)
//{
//    if((i>=0) && (i<=n-1) && (j>=0) && (j<=n-1) && a[i][j] && (*((visited + i*n) +j)==0))
//    {
//        return true;
//    }
//    return false;
//}


void Graph::dfsmatrix(int **a, int i, int j, int n, bool *visited)
{
    static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};
    *((visited + i*n) +j) = true;
    for(int k =0;k<8;k++)
    {
        if(issafe(a,i+rowNbr[k],j+colNbr[k],n,visited))
        {
            dfsmatrix(a,i+rowNbr[k],j+colNbr[k],n,visited);
        }
    }
}

void Graph::countislands()
{
    int n;
    cin>>n;
    int **a = new int*[n];
    for(int i =0;i<n;i++)
    {
        a[i] = new int[n];
    }

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
            cin>>a[i][j];
    }

    bool visited[n][n];
    memset(visited,0,sizeof(visited));
    int count = 0;

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(a[i][j] && visited[i][j]==0)
            {
                dfsmatrix(a,i,j,n,(bool*)visited);
                count = count+1;
            }
        }
    }

    cout<<"Total islands are "<<count<<endl;

    for(int i =0;i<n;i++)
    {
        delete [] a[i];
    }
    delete [] a;

}

bool Graph::issafe(int **a, int i , int j, int n, bool *visited)
{
    if((i>=0) && (i<=n-1) && (j>=0) && (j<=n-1) && a[i][j] && (*((visited + i*n) +j)==0))
    {
        return true;
    }

    return false;
}

int Graph::findparent(int * parent, int i)
{
    if(parent[i]==-1)
        return i;
    return findparent(parent, parent[i]);
}

void Graph::takeunion(int*parent, int x, int y)
{
    int px = findparent(parent,x);
    int py = findparent(parent,y);
    parent[px] = py;
}

bool Graph::unionfind()
{
    map<int, int>m;
    m[0] = 1;
    m[1] = 2;
    m[2] = 0;
    int parent[3];
    for(int i =0;i<3;i++)
    {
        parent[i] = -1;
    }

    map<int,int>::iterator i;
    for(i = m.begin();i!=m.end();i++)
    {
        int x = findparent(parent,i->first);
        int y = findparent(parent,i->second);
        cout<<"x"<<x<<"y"<<y<<endl;
        if(x==y)
            return true;
        takeunion(parent, x, y);
    }
    return false;


}











