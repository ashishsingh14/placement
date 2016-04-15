#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define si 20
int dp[si][si];

int findmin(int *coins, int i, int j)
{
    if(i==j)
        return dp[i][j] = coins[i];
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(j==i+1)
        return dp[i][j] = max(coins[i],coins[j]);

    return dp[i][j] = max(coins[i] + min(findmin(coins, i+2,j),findmin(coins,i+1,j-1)),
                          coins[j] + min(findmin(coins,i+1,j-1),findmin(coins,i,j-2)));
}

int dfs(list<int>*adj, int s, int& k, int *visited)
{
    int ans = 0;
    visited[s] = true;
    if(k<0)
        return 0;
    if(k==0)
        return 1;
    list<int>::iterator i;
    bool flag = false;

    for(i = adj[s].begin();i!=adj[s].end();i++)
    {
        int res = 1;
        if(!visited[*i] && k>0)
        {
            flag = true;
            k = k-1;
            res += dfs(adj,*i,k,visited);
            ans = max(res, ans);
        }

    }
    if(flag==false)
    {
        k--;
        return 1;
    }
    return ans;

}

void wheretogo()
{
    int arr[] = {-1,0,0,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    list<int>* adj = new list<int>[n+1];
    for(int i =1;i<n;i++)
    {
        adj[i].push_back(arr[i]);
        adj[arr[i]].push_back(i);
    }
    int k = 3;
    int * visited = new int[n];

    int ans = 1;

    list<int>::iterator i;
    bool flag = false;

    for(i = adj[0].begin();i!=adj[0].end();i++)
    {
        int res = 1;
        memset(visited,false, sizeof(visited));
        k = 2;
        if(!visited[*i] && k>0)
        {
            flag = true;
            k = k-1;
            res += dfs(adj,*i,k,visited);
            ans = max(res, ans);
        }

    }

    cout<<"ans is "<<ans<<endl;
}

void checkandpush(vector<pair<int, int> > &r, pair<int,int>p)
{
    if(r.size()>0)
    {
        pair<int,int> q = r[r.size()-1];

        if(q.second==p.second)
            return ;


        if(q.first==p.first)
        {
            int h = max(p.second , q.second);
            r[r.size()-1].second = h;
            return;
        }

        r.push_back(p);
    }
    else
    {
        r.push_back(p);
    }

}

vector<pair<int, int> > skymerge( vector<pair<int, int> >r1,

                                  vector<pair<int, int> > r2,
                                  int l, int m , int h)
 {

     vector<pair<int, int> > r;
     int n1 = r1.size();
     int n2 = r2.size();
     int i,j;
     i = j =0;
     int h1,h2;
     h1 = h2 = 0;
     while(i<n1 && j<n2)
     {

         if(r1[i].first< r2[j].first)
         {
             h1 = r1[i].second;
             int maxh = max(h1,h2);

            pair<int,int>p = make_pair(r1[i].first, maxh);
            checkandpush(r,p);
            i++;

         }
         else
         {
             h2 = r2[j].second;
             int maxh = max(h1,h2);

            pair<int,int>p = make_pair(r2[j].first, maxh);
            checkandpush(r,p);
            j++;
         }


     }

     while(i<n1)
     {
         checkandpush(r,r1[i]);
         i++;
     }


     while(j<n2)
     {
         checkandpush(r,r2[j]);
         j++;
     }

     return r;

 }


vector<pair<int, int> > skysort(vector<vector<int> >& buildings, int l, int h)
{
    if(l==h)
    {
         vector<pair<int, int> > r;
         r.push_back(make_pair(buildings[l][0], buildings[l][2]));
         r.push_back(make_pair(buildings[l][1], 0));
         return r;
    }


    int m = (l+h)/2;
    vector<pair<int, int> > r1 = skysort(buildings, l,m);
    vector<pair<int, int> > r2 = skysort(buildings, m+1,h);

    vector<pair<int, int> > r3 = skymerge(r1,r2,l,m,h);
    return r3;

}

vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {

   vector<pair<int, int> > r3;
   if(buildings.size()>0)
    r3 = skysort(buildings, 0,buildings.size()-1);
   return r3;

}


void generateallsubstrings()
{
    int t;
    string s;
    cin>>t;
    set<string>m;
    while(t--)
    {
        cin>>s;

        int n = s.size();
        for(int l =1;l<=n;l++)
        {
            for(int i =0;i<=n-l;i++)
            {
                string temp = s.substr(i,l);
                m.insert(temp);
            }
        }
        cout<<m.size()<<endl;
        m.clear();
    }
}


int main()
{
//    int coins[] = {20, 30, 2, 2, 2, 10};
//    int n = sizeof(coins)/sizeof(coins[0]);
//    memset(dp,-1,sizeof(dp));
//    cout<<"max value is "<<findmin(coins,0,n-1)<<endl;

    vector<vector<int> >v;

    vector<int>v1;
    vector<int>v2;
    v1.push_back(0);
    v1.push_back(2);
    v1.push_back(3);
    v2.push_back(2);
    v2.push_back(5);
    v2.push_back(3);
    v.push_back(v1);
    v.push_back(v2);

//    vector<pair<int, int> > v3 = getSkyline(v);

//    for(int i =0;i<v3.size();i++)
//    {
//        cout<<v3[i].first<<" "<<v3[i].second<<endl;
//    }b

    generateallsubstrings();


    return 0;
}

