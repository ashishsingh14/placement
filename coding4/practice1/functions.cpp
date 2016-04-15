#include "functions.h"



Node*newnode(int a)
{
    Node * n = new Node;
    n->data = a;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void convertomirrortree(Node *root)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        return;
    convertomirrortree(root->left);
    convertomirrortree(root->right);
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


//bool roottoleafpath(Node *root, int sum, int currentsum, int level,int &ans)
//{
//    if(root==NULL)
//        return false;

//    currentsum +=root->data;
//    if(root->left==NULL && root->right==NULL && currentsum==sum)
//    {
//        ans = min(ans,level);
//        return true;
//    }
//    if(roottoleafpath(root->left,sum, currentsum,level+1))
//        return true;

//    if(roottoleafpath(root->right,sum, currentsum,level+1))
//        return true;
//    return false;


//}

//void roottoleafpathhelper(Node *root, int sum)
//{
//    int currentsum,level;
//    int ans=INT_MAX;
//    currentsum = level = 0;
//    if(root)
//        if(roottoleafpath(root,sum,currentsum,level,ans))
//            if(ans!=INT_MAX)
//                cout<<"height is "<<ans<<endl;
//            else
//                cout<<"not possible\n";
//}

string convertosgtring(int n)
{
    ostringstream ss;
    ss<<n;
    return ss.str();
}
int compare(char a, char b)
{
    return a>b;
}

void largestnumber(int *arr, int n){
    string s = "";
    for(int i =0;i<n;i++)
    {

        s = s + convertosgtring(arr[i]);

    }

    sort(s.begin(),s.end(),compare);
    cout<<s<<endl;
}

string removealloccurences(string a, string b)
{
    if(a.empty())
        return "";
    int i = a.find(b);

    if(i!=string::npos)
    {
        string n = "";
        n = a.substr(0,i);
        int l = b.size();
        int k = a.size();
        n = n + a.substr(i+l, k-i-l);
        return removealloccurences(n,b);
    }
    else
        return a;

}

void convertonestringintoanother(string a, string b)
{
    if(a.size()!=b.size())
        return ;
    for(int i =0;i<a.size();i++)
    {
        if(a[i]==b[i])
            continue;
        else
        {
            int j = i+1;
            while(b[i]!=a[j] && j<a.size())
            {
                j++;
            }
            while(a[i]!=b[i] && j!=i)
            {
                swap(a[j],a[j-1]);
                cout<<a<<endl;
                j--;
            }

        }
    }
}

int onechardistance(string a, string b)
{
    int c =0;
    if(a.size()!=b.size())
        return 0;
    else
    {
        int i =0;
        int j =0;
        while(i!=a.size() && j!=b.size())
        {
            if(a[i]!=b[j])
                c++;
           i++,j++;
        }
        if(c==1)
            return 1;
        else
            return 0;

    }
}

void minimumstepsfromonestringtoanother(string arr[], int n, string src, string dest)
{
    //list<string>*adj = new list<string>[n];
    map< string, list<string> >g;
    for(int i =0;i<n-1;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(onechardistance(arr[i],arr[j]))
            {
                g[arr[i]].push_back(arr[j]);
                g[arr[j]].push_back(arr[i]);
            }
        }
    }
//    map< string, list<string> >::iterator i;
//    for(i = g.begin();i!=g.end();i++)
//    {
//        list<string>::iterator j;
//        cout<<i->first<<" -> ";
//        for(j = (i->second).begin();j!=(i->second).end();j++)
//        {
//            cout<<*j<<" ";
//        }
//        cout<<endl;
//    }


    queue<string>q;
    q.push(src);
    map<string,int>distance;
    distance[src] = 0;
    map<string,int>visited;
    visited[src] = 1;
    while(!q.empty())
    {
        string temp = q.front();
        q.pop();
        cout<<temp<<endl;
        if(temp.compare(dest)==0)
            break;
        list <string> ::iterator i;
        for(i = g[temp].begin();i!=g[temp].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i] = 1;
                distance[*i] = distance[temp] + 1;
                q.push(*i);
            }
        }

    }
    cout<<"minimum distance is "<<distance[dest]<<endl;

}

bool dfsassign(int c, bool*seen, int *match, bool graph[M][N])
{
    for(int j = 0;j<N;j++)
    {

        if(graph[c][j] && seen[j] ==false)
        {
            seen[j]= true;
            if(match[j]<0 || dfsassign(match[j],seen,match,graph))
            {
                match[j] = c;
                return true;
            }
        }

    }
    return false;
}

void maximumbipartitemathching()
{
    bool graph[M][N] = {  {0, 1, 0, 0, 1},
                          {1, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0},
                          {0, 0, 1, 0, 0},
                          {1, 0, 0, 0, 0},
                          };

    bool seen[N];
    int match[N];
    memset(match, -1,sizeof(match));
    int count = 0;
    for(int i = 0;i<M;i++)
    {
        memset(seen,0,sizeof(seen));
        if(dfsassign(i,seen,match,graph))
            count++;
    }
    cout<<"The maximum matching is "<<count<<endl;


}

bool issafe(int a[5][6], int x, int y, bool visited[5][6])
{
    if(x>=0 && x<5 && y>=0 && y<6 && !visited[x][y] && a[x][y] )
        return true;
    return false;
}

void islandshelper(int a[5][6], bool visited[5][6], int x, int y)
{
    static int row[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int col[] = {-1,  0,  1, -1, 1, -1, 0, 1};
    visited[x][y] = 1;
    for(int i = 0;i<8;i++)
    {
        int c = x+row[i];
        int b = y+col[i];
        if(issafe(a,c,b,visited))
        {
            islandshelper(a,visited,c,b);
        }
    }
}

void numberfislands()
{
    int a[5][6] = {  {1, 1, 0, 0, 0},{0, 1, 0, 0, 1},{1, 0, 0, 1, 1},
                     {0, 0, 0, 0, 0},{1, 0, 1, 0, 1}};

    bool visited[5][6];

    memset(visited,0,sizeof(visited));
    int count = 0;
    for(int i =0;i<5;i++)
    {
        for(int j =0;j<6;j++)
        {
            if(!visited[i][j] && a[i][j])
            {
                islandshelper(a,visited,i,j);
                count++;
            }
        }
    }

    cout<<"Total islands are "<<count<<endl;


}


bool bfsforford(int graph[V][V], int *parent, int s, int d)
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int i =0;i<V;i++)
        {
            if(graph[temp][i]>0 && !visited[i])
            {
                visited[i] = true;
                parent[i] = temp;
                q.push(i);
            }
        }
    }
    return visited[d]==true;

}

void dfsford(int graph[V][V], int s, bool visited[])
{
    visited[s] = true;
    for(int i =0;i<V;i++)
    {
        if(!visited[i] && graph[s][i])
        {
            dfsford(graph, i, visited);
        }
    }
}

void maxflow()
{
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    int res[V][V];
    for(int i =0;i<V;i++)
        for(int j =0;j<V;j++)
            res[i][j] = graph[i][j];
    int parent[V];
    int maxflow = 0;
    int s,d;
    s = 0;
    d = 5;
    while(bfsforford(res, parent, s,d))
    {
        int pathflow = INT_MAX;
        int u,v;
        for(v = d;v!=s;v = parent[v])
        {
            u = parent[v];
            pathflow = min(pathflow, res[u][v]);

        }

        for(v = d;v!=s;v = parent[v])
        {
            u = parent[v];
            res[u][v] -= pathflow;
            res[v][u] += pathflow;

        }
        maxflow += pathflow;

    }

    cout<<"The maximum flow is "<<maxflow<<endl;

    bool visited[V];
    memset(visited, false, sizeof(visited));

    dfsford(res, s,visited);

    for(int i =0;i<V;i++)
        for(int j =0;j<V;j++)
        {
            if(graph[i][j] && visited[i] && !visited[j])
                cout<<i<<"->"<<j<<endl;
        }


}

bool checkifalphabet(char a)
{
    if(a>='A' && a<='Z')
        return true;
    else if((a>='a' && a<='z'))
        return true;
    else
        return false;
}

bool psuedoanagram(string a, string b)
{
    map<int, int> m,n;

    for(int i =0;i<a.size();i++)
    {
        if(checkifalphabet(a[i]))
        {
            if(isupper(a[i]))
            {
                if(m[(a[i]^32)-'a']==0)
                    m[(a[i]^32)-'a']++;
            }
            else
            {
                if(m[a[i]-'a']==0)
                    m[a[i]-'a']++;
            }
        }
    }

    for(int i =0;i<b.size();i++)
    {
        if(checkifalphabet(b[i]))
           {
                if(isupper(b[i]))
                {
                    if(n[(b[i]^32)-'a']==0)
                        n[(b[i]^32)-'a']++;
                }
                else
                {
                    if(n[b[i]-'a']==0)
                        n[b[i]-'a']++;
                }
        }
    }

    int flag1,flag2;
    flag1 = flag2 = 0;
    for(int j =0;j<b.size();j++)
    {
        if(checkifalphabet(b[j]))
        {

            if(isupper(b[j]))
            {
                if(m[(b[j]^32)-'a']==0)
                    flag1=1;
            }
            else
            {
                if(m[b[j]-'a']==0)
                    flag1=1;
            }

        }
    }
    for(int j =0;j<a.size();j++)
    {
        if(checkifalphabet(a[j]))
        {
            if(isupper(a[j]))
            {
                if(n[(a[j]^32)-'a']==0)
                    flag2=1;
            }
            else
            {
                if(n[a[j]-'a']==0)
                    flag2=1;
            }


        }
    }
    if(!flag1 && !flag2)
        return true;
    else
        return false;

}

char valToChar(int val)
{
    char convArray[] =
    {'0','1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F'};

    if(val < 16 && val>=0)
    {
        return convArray[val];
    }

}

void convertdectoheaxa(int number)
{

    string h = "";
    while(number>0)
    {
        int r = number%16;
        h = valToChar(r) + h;
        number  = number /16;
    }
    cout<<h<<endl;
}
int charToVal(char curChar)
{
    char convArray[] =
    {'0','1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F'};
    for(int i=0;i<16; ++i)
    {
        if(curChar==convArray[i])
        {
        return i;
        }
    }
    return -1;
}

void convertodecimal(string h)
{
    int f = 1;
    int l = h.size()-1;
    int ans = 0;
    int base = 16;
    for(int i = l;i>=0;i--)
    {
        int x = charToVal(h[i]);
        ans += f*x;
        f = f*base;
    }
    cout<<"decimal value is "<<ans<<endl;
}


void binomialcoefficient()
{
    int table[10][10];

    for(int i =0;i<10;i++)
    {
        for(int j =0;j<=min(i,2);j++)
        {
            if(i==j || j==0)
                table[i][j] = 1;
            else
                table[i][j] = table[i-1][j-1] + table[i-1][j];
        }
    }

    cout<<"4 2 "<<table[4][2]<<endl;
}












