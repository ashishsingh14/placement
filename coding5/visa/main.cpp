#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int lim=1000000000;

void solve()
{

    int t;
    cin>>t;
    int n,m,s,a,h;
    while(t--)
    {
        cin>>n>>m;
        int dis[n+1][n+1];
        int table[n+1][n+1];

        int p,q,r;

        for(int i =1;i<=n;i++)
        {
            for(int j =1;j<=n;j++)
            {
                if(i==j)
                {
                    table[i][j] = 0;
                }
                else
                {
                    table[i][j] = lim;
                }
            }
        }
        for(int i =0;i<m;i++)
        {
            cin>>p>>q>>r;
            table[p][q] = min(table[p][q],r);
            table[q][p] = r;
        }

        cin>>s>>a>>h;
        for(int k =1;k<=n;k++)
        {
            for(int i =1;i<=n;i++)
            {
                for(int j =1;j<=n;j++)
                {


                   table[i][j] = min(table[i][j],table[i][k] + table[k][j]);

                }
            }
        }
// 		for(int i =1;i<=n;i++)
//        {
//            for(int j =1;j<=n;j++)
//            {
//                cout<<table[i][j]<<" ";
//            }
//            cout<<endl;
//        }



        int ans = 0;

       for(int i=1;i<=n;i++)
        {
          if(i==s || i==a || i==h)continue;
          if(table[s][i]==lim || table[i][a]==lim || table[i][h]==lim)
            assert(0);
          ans=max( table[s][i]+ 2*table[i][a] + table[i][h],ans);
        }

        cout<<ans<<endl;

    }

}

void zigzagarray()
{
    int arr[] = {5,2,7,8,-2,25,25};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    sort(arr,arr+n);
    for(int i =0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    int i = 0;
    int j = n-1;
    while(v.size()<=n)
    {
        v.push_back(arr[j]);
        v.push_back(arr[i]);
        i++;
        j--;
    }
    for(int i =0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

int main()
{
    //solve();
//    int ** a = new int*[5];
//    for(int i =0;i<5;i++)
//        a[i] = new int[5];
//    //delete after use
//    for(int i =0;i<5;i++)
//        delete a[i];
//    delete a; vector<vector<bool> > mark(row, vector<bool>(col,true));
    zigzagarray();
    return 0;
}
