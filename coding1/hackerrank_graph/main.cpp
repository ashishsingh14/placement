#include "functions.h"

void callingbfs()
{
    int n,m,t;
    cin>>t;
    int a,b,s;
    while(t--)
    {
        cin>>n>>m;
        list<int>*adj;
        adj = new list<int>[n];
        for(int i = 0;i<m;i++)
        {
            cin>>a>>b;
            adj[a-1].push_back(b-1);
        }
        //printgraph(adj, n);
        cin>>s;
        bfs(s-1, n, adj);
    }

}

void printarray(int *a, int size)
{
    for(int i =0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}


void printgraph(list<int> *adj, int v)
{
    for(int j =0;j<v;j++)
    {
        cout<<j<<":";
        for(list<int>::iterator i = adj[j].begin(); i!=adj[j].end(); ++i)
        {
            cout<<(*i)<<" ";
        }
        cout<<endl;
    }
}

void bfs(int s, int v, list<int>*adj)
{
    bool * visited = new bool[v];
    int * distance = new int[v];
    for(int i = 0;i<v;i++)
    {
        visited[i] = false;
        distance[i] = -1;
    }
    queue<int>q;
    q.push(s);
    visited[s] = true;
    distance[s] = 0;
    list<int>::iterator i;
    int t;
    while(!q.empty())
    {
        t = q.front();
        //cout<<t<<" ";
        q.pop();
        for(i = adj[t].begin();i!=adj[t].end();i++)
        {
            if(visited[*i]==false)
            {
                visited[*i] = true;
                distance[*i] = distance[t] + 6;
                q.push(*i);
            }
        }
    }
    for(int i =0;i<v;i++)
    {
        if(i==s)
            continue;
        else
            cout<<distance[i]<<" ";
    }
    cout<<endl;
    delete visited;
    delete distance;
}

void dfs(list<int> *adj, int n)
{
    bool * visited = new bool[n];
    for(int i = 0;i<n;i++)
        visited[i] = false;
    list<int>::iterator i;
    int vertices, components;
    components = 0;
    int c[100000];
    for(int i = 0; i < n; i++)
    {
        if(visited[i]==false)
        {
            vertices = 0;
            dfshelper(adj,i, visited, vertices);
            c[components++] = vertices;
        }
    }
    long long int t = n*(n-1)/2;
    long long same = 0;
    for(int i =0;i<components;i++)
    {
        same+=(c[i])*(c[i]-1)/2;
    }
    cout<<t-same<<endl;
    delete visited;
}

void dfshelper(list<int> *adj, int s, bool visited[], int &vertices)
{
    visited[s] = true;
    vertices++;
    //cout<<s<<" ";
    list<int>::iterator i;
    for(i = adj[s].begin();i!=adj[s].end();i++)
    {
        if(visited[*i]==false)
        {
            dfshelper(adj, *i, visited,vertices);
        }
    }
}

void journeytomoon()
{
    int n,l;
    cin>>n>>l;
    if(n == 1)
    {
        cout <<"0\n";
        return;
    }

    int a , b;
    list<int>*adj;
    adj = new list<int>[n];
    for(int i=0;i<l;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(adj, n);
}

int countsetbits(long long int n)
{
    int count =0;
    while(n>0)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}

void subsetcomponents()
{
    int n;
    cin>>n;
    unsigned long long int input[21];
    for(int i =0;i<n;i++)
    {
        cin>>input[i];
    }
    long long ans = 64;
    int c;
    long long int r = 0;
    for(int i =1;i<pow(2,n);i++)
    {
        c = 0;
        for(int j = 0;j<n;j++)
        {
            if(i&(1<<j))
            {
                c = countsetbits(input[j]);
                ans = ans - c + 1;
            }

        }
        ans = ans + 64;
    }
    cout<<ans<<endl;
}

void snakeandladder()
{
    int t;
    cin>>t;
    int snakes[101],ladders[101],distance[101],visited [101];
    while(t--)
    {
        int s,l;
        int a,b;
        memset(snakes,-1,sizeof(snakes));
        memset(ladders,-1,sizeof(ladders));
        memset(distance,0,sizeof(distance));
        memset(visited,0,sizeof(visited));
        cin>>l;
        for(int i =0;i<l;i++)
        {
            cin>>a>>b;
            ladders[a] = b;
        }

        cin>>s;
        for(int i =0;i<s;i++)
        {
            cin>>a>>b;
            snakes[a] = b;
        }
        queue<int>q;
        q.push(1);
        visited[1] = 1;
        distance[1] = 0;
        int top;
        while(!q.empty())
        {
            top = q.front();
            if(top==100)
                break;
            q.pop();
            for(int i =1;i<=6 && top+i<=100;i++)
            {
                if(!visited[top+i] && snakes[top+i]==-1 && ladders[top+i]==-1)
                {
                    visited[top+i] = 1;
                    if(distance[top+i]==0)
                        distance[top+i] = distance[top] + 1;
                    //cout<<"first"<<top+i<<endl;
                    q.push(top+i);
                }
                else if(!visited[top+i] && snakes[top+i]!=-1)
                {
                    visited[snakes[top+i]] = 1;
                    //visited[top+i] = 1;
                    if(distance[snakes[top+i]]==0)
                        distance[snakes[top+i]] = distance[top] + 1;
                    //cout<<"second"<<snakes[top+i]<<endl;
                    q.push(snakes[top+i]);
                    //distance[top+i] = distance[top] +1;
                }
                else if(!visited[top+i] && ladders[top+i]!=-1)
                {
                    visited[ladders[top+i]] = 1;
                    //visited[top+i] = 1;
                    if(distance[ladders[top+i]]==0)
                        distance[ladders[top+i]] = distance[top] + 1;
                    //cout<<"third"<<ladders[top+i]<<endl;
                    q.push(ladders[top+i]);
                   // distance[top+i] = distance[top] +1;
                }
            }
        }
        if(distance[100]!=0)
            cout<<distance[100]<<endl;
        else
            cout<<"-1"<<endl;

//      cout<<"The distance from the source is "<<distance[100]<<endl;
//      for(int i =0;i<101;i++)
//          if(distance[i]!=0)
//              cout<<i<<" "<<distance[i]<<endl;
    }

}

void matrix()
{

}

long long int in[100001];

int main() {
    int t;
    cin>>t;
    long long int n,k,q,idx;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i =0;i<n;i++)
            {
            cin>>in[i];
        }
        for(int i =0;i<q;i++)
            {
            cin>>idx;
            int a = (idx-k+n)%n;
            //cout<<"v: "<<a<<endl;
            cout<<in[a]<<endl;


        }
    }
    return 0;
}

