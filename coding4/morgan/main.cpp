#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int ans = -9999;
int n;
int a[50];
void solverec2(int index)
{
    if(index==n)
    {
        int sum = 0;

        for(int i =1;i<=floor(n/2);i++)
            {

                sum += abs(a[i]-a[n-i+1]);
            }

        ans = max(sum, ans);
        return;
     }

    int temp = a[index];

    if((a[index-1]%2==0) && (a[index+1]%2==0))
        {


             a[index] = (a[index-1]+a[index+1])/2;
             solverec2(index+1);
         }

    a[index] = temp;
    solverec2(index+1);
    return;

}

void solve()
{

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i =1;i<=n;i++)
            cin>>a[i];
        ans = -9999;
        int index = 2;
        solverec2(index);
        cout<<ans<<endl;

    }

}

int min(int x, int y, int z)
{
    return min(min(x,y),z);
}

void mincost()
{
    int t;
    cin>>t;
    while(t--)
    {
        string x, y;
        cin>>x>>y;
        int a,b,c;
        cin>>a>>b>>c;

        string p = x;
        string q = y;
        sort(p.begin(),p.end());
        sort(q.begin(),q.end());
        if(p.compare(q)==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        else
        {
            int l1 = x.size();
            int l2 = y.size();
            int table[l1+1][l2+1];

            for(int i =0;i<=l1;i++)
            {
                for(int j =0;j<=l2;j++)
                {
                    if(i==0)
                        table[i][j] = b*j;
                    else if(j==0)
                        table[i][j] = a*i;
                    else if(x[i-1]==y[j-1])
                    {
                        table[i][j] = table[i-1][j-1];
                    }
                    else
                    {
                      table[i][j]=min(c+table[i-1][j-1],b+table[i][j-1],a+table[i-1][j]);
                    }

                }
            }

            cout<<table[l1][l2]<<endl;
        }

    }
}

int main() {
    //mincost();
    string a = "4";
    string b = "123";
    if(a>b)
    {
        cout<<"yes\n";
    }
    else
            cout<<"no"<<endl;
    return 0;
}
