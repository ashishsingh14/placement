#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

void findbridges()
{
    int t;
    cin>>t;
    list<int>*adj;
    int n,m ;
    int a,b;

    while(t--)
    {
        cin>>n>>m;
        adj = new list<int>[n];
        int visited[n],distance[n];
        memset(visited,0,sizeof(visited));
        memset(distance,0,sizeof(distance));
        for(int i =0;i<m;i++)
        {
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }

        queue<int> q;
        q.push(0);
        visited[0] = 1;
        distance[0] =0;
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();

            for(list<int>::iterator i = adj[temp].begin();i!=adj[temp].end();i++)
            {
                if(!visited[*i])
                {
                    visited[*i] =1;
                    distance[*i] = distance[temp] + 1;
                    q.push(*i);
                }
            }
        }

        cout<<distance[n-1]<<endl;

    }
}

struct node{
    int v;
    int weight;
};

void mittalplay()
{
    int t;
    cin>>t;
    list<node>*adj;
    int n,m ;
    int a,b,c;

    while(t--)
    {
        cin>>n>>m;
        adj = new list<node>[n];
        int distance[n];

        for(int i =0;i<n;i++)
        {
            distance[i] = INT_MAX;
        }



        struct node temp1,temp2;
        for(int i =0;i<m;i++)
        {
            cin>>a>>b>>c;
            temp1.v = b-1;
            temp2.v = a-1;
            temp1.weight = c;
            temp2.weight = c;
            adj[a-1].push_back(temp1);
            adj[b-1].push_back(temp2);
        }
        #define pp pair<int,int>
        priority_queue<pp, vector<pp>, greater<pp> > q;
        q.push(pp(0,0));
        int c =0;
        distance[0] = 0;
        while(!q.empty())
        {
            c++;
            pp temp = q.top();
            q.pop();
            int x = temp.first;
            int y  = temp.second;

            if(distance[y]!=INT_MAX)
            {

                for(list<node>::iterator i = adj[y].begin();i!=adj[y].end();i++)
                {
                    if(distance[(*i).v]> x+(*i).weight)
                    {
                        distance[(*i).v] = x +(*i).weight;
                        q.push(pp(distance[(*i).v],(*i).v));
                    }
                }
            }
            if(c==n)
                break;
        }

//        for(int i =0;i<n;i++)
//            cout<<distance[i]<<" ";

        int q1;
        cin>>q1;
        int o,k;
        while(q1--)
        {
            cin>>o>>k;
            cout<<max(0,k-2*distance[o-1])<<endl;
        }


    }
}

void symmetricpairs()
{
    int arr[] = {10, 20, 30, 40, 5, 10, 40, 30, 10, 5};//{10, 20, 30, 40, 5, 10, 40, 30, 10, 5};
    map < int,int > m;
        int n = sizeof(arr)/sizeof(arr[0]);
        for(int i =0;i<n;i=i+2)
        {
            if(m[arr[i+1]])
            {
                if(m[arr[i+1]]==arr[i])
                    cout<<"Symmetric pair is "<<arr[i]<<" "<<arr[i+1]<<endl;
                else
                   m[arr[i]] = arr[i+1];
            }
            else
                m[arr[i]] = arr[i+1];
        }
        map<int,int>::iterator i;
        for(i = m.begin();i!=m.end();i++)
        {
            cout<<i->first<<" "<<i->second<<endl;
        }

}
int compare(const void *a, const void *b)
{
    return ( *(int*)a < *(int*)b );
}

void findthelargestrectangle()
{
    bool mat[3][5] = { {0, 1, 0, 1, 0},
                          {0, 1, 0, 1, 1},
                          {1, 1, 0, 1, 0}
                        };

    int sum[3][5];
    //memset(sum,0,sizeof(sum));
    for(int j =0;j<5;j++)
    {
        sum[0][j] = mat[0][j];// remember this point in the matrix
        for(int i =1;i<3;i++)
        {
            sum[i][j] = (mat[i][j]==0)?0:sum[i-1][j]+1;
        }
    }

    for(int i =0;i<3;i++)
    {
        for(int j =0;j<5;j++)
        {
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i =0;i<3;i++)
    {
        for(int j =0;j<5;j++)
        {
            for(int k = j+1;k<5;k++)
                if(sum[i][k]>sum[i][j])
                {
                    int temp = sum[i][k];
                    sum[i][k] = sum[i][j];
                    sum[i][j] = temp;
                }
        }
        cout<<endl;
    }

    for(int i =0;i<3;i++)
    {
        for(int j =0;j<5;j++)
        {
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
    int maxsum =0;
    int cursum;
   for(int i =0;i<3;i++)
   {
       for(int j =0;j<5;j++)
       {
           cursum = (j+1)*sum[i][j];
           if(maxsum<cursum)
               maxsum = cursum;

       }
   }

   cout<<"Maximum area of rectangle is "<<maxsum<<endl;

}

void computelps(int *lps, char *y, int m)
{
    lps[0] = 0;
    int len =0;
    int i =1;
    while(i<m)
    {
        if(y[i]==y[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(char *x, char * y, int n, int m)
{
    int * lps = new int[m];
    int i = 0;
    int j =0;
    computelps(lps,y,m);
    int best = 0;
    int res =0;
    int ans;
    //cout<<"lpsis\n";
    while(i<n)
    {
//        while(q>0 && y[q]!=x[i])
//                 q=lps[q];
//              if(y[q]==x[i])
//              {
//                  //i++;
//                 q++;
//              }

//              if(q>best)
//              {
//                 best=q;
//                 ans=i-q+1;
//              }
        if(x[i]==y[j])
        {
            i++;
            j++;
            best++;
        }
        if(best>res)
        {
            res = best;
            ans = i-j;
        }
        if(j==m)
        {
            //cout<<"Pattern found at index:"<<i-j<<endl;
            break;
        }
        else if(i<n && y[j]!=x[i])
        {
            best =0;
            if(j!=0)
                j = lps[j-1];
            else
                i = i+1;
        }

    }
    cout<<ans<<endl;
    delete lps;
}

void shiftoperations()
{
    int n;
    char a[20000],b[20000];
    cin>>n;
    cin>>a;
    cin>>b;

    int n1 = strlen(b);
    int m = strlen(a);
    int c = n1;
    for(int i =0;i<n1;i++)
    {
        b[c++] = b[i];
    }
    b[c] = '\0';
    //cout<<b<<endl;

    kmp(b,a,c,m);
}

int dfs(list<node>*adj, int s, int*visited)
{
    visited[s] = 1;
    int currenttime = 2;
    list<node>::iterator i;
    for(i = adj[s].begin();i!=adj[s].end();i++)
    {
        if(visited[(*i).v]==0)
        {
            visited[(*i).v]= 1;
            currenttime += (*i).weight;
            currenttime += dfs(adj,(*i).v,visited);
        }
    }
    if(adj[s].empty())
    {
        //visited[s] = 0;
        return 0;
    }
    return currenttime;
}

void childfreetime()
{
    int t;
    cin>>t;
    list<node>*adj;
    int n,m ;
    int a,b,c;

    while(t--)
    {
        cin>>n>>m;
        adj = new list<node>[n];
        struct node temp1;
        for(int i =0;i<m;i++)
        {
            cin>>a>>b>>c;
            temp1.v = b-1;
            temp1.weight = c;
            adj[a-1].push_back(temp1);
        }
        int maxtime = INT_MIN;
        int visited[n];
        int currtime;
        for(int i =0;i<n;i++)
        {
            currtime =0;
            memset(visited,0,sizeof(visited));
            if(!adj[i].empty())
                currtime = dfs(adj,i,visited);
            if(maxtime<currtime)
                maxtime = currtime;
        }

        cout<<"Maximum time is:"<<maxtime<<endl;
        //delete adj;
    }
}

int checkifmultipleof3(int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return 0;
    if(n<0)
        return checkifmultipleof3(-n);
    int odd,even;
    odd = even =0;
    while(n)
    {
        if(n&1)
            odd++;
        n = n>>1;
        if(n&1)
            even++;
        n = n>>1;
    }
    return checkifmultipleof3(abs(odd-even));
}

void countabc()
{
    string s;
    cin>>s;
    int a,b,c;
     a= b = c=0;
    typedef pair<int,int>p;
    map<p,int>m;
    m[make_pair(0,0)] =1;
    long long ans =0;
    for(int i =0;i<s.size();i++)
    {
        if(s[i]=='A')
            a++;
        if(s[i]=='B')
            b++;
        if(s[i]=='C')
            c++;
        ans += m[make_pair(a-b,a-c)];
        m[make_pair(a-b,a-c)]++;

    }
    cout<<ans<<endl;
}

int main()
{
//    node a,b;
//    list<node>l;

//    int x,y;
//    for(int i =0;i<3;i++)
//    {
//        cin>>x>>y;
//        a.v = x;
//        a.weight = y;
//        l.push_back(a);
//    }

//    list<node>::iterator i;
//    for(i = l.begin();i!=l.end();i++)
//    {
//        cout<<(*i).v<<(*i).weight<<endl;
//    }
    char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";
    //kmp(txt,pat,strlen(txt),strlen(pat));
    if(checkifmultipleof3(14))
        cout<<"yes\n";
    else
        cout<<"no\n";

    return 0;
}

