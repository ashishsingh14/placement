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



void chefandarray()
{

        int n,a ;
        cin>>n;
        long long int x;
        vector<long long int>v;
        for(int i =0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }

        cin>>x;

        int add = 0;
        sort(v.begin(),v.end());
        long long int ans = 0;
        long long int d;
        for(int i = v.size()-1;i>=0;i--)
        {
            if((v[i] + add) >=0)
                continue;

            d =  -(v[i] + add);
            //cout<<"d is "<<d<<endl;
            if((i+1) > x)
            {
                add += d;
                ans += d * x;
                continue;
            }
            else
            {
                ans += d;
                continue;
            }
                //cout<<"ans is "<<endl;



        //cout<<ans<<endl;


    }
        cout<<ans<<endl;
}


bool iswalprime(int n)
{
    return n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0;
}

void countwalprimes(char* s , char* res, int i, int j, int n)
{
    if(i==n)
    {
        res[j] = '\0';
        cout<<res<<endl;
//        string d(res);
//        int a = atoi(res);
//        if(iswalprime(a))
//        cout<<"It is walprime with value "<<a<<endl;
        return;
    }

    res[j] = s[i];
    countwalprimes(s,res,i+1,j+1,n);

    res[j] = '+';
    res[j+1] = s[i];
    countwalprimes(s,res,i+1,j+2,n);
    res[j] = '-';
    res[j+1] = s[i];
    countwalprimes(s,res,i+1,j+2,n);


}


void function()
{

    int t;
    cin>>t;
    int c = 0;
    while(t--)
    {
        c++;
        int n;
        cin>>n;
        int tab[n];
        if(n==0)
        {
            cout<<"Case 1: 0"<<endl;
            continue;
        }
        for(int i =0;i<n;i++)
            cin>>tab[i];


        int dp[n];
        for(int i =0;i<n;i++)
        dp[i] = 0;

        dp[0] = tab[0];

        dp[1] = max(tab[0], tab[1]);
        for(int i =2;i<n;i++)
        {

            dp[i] = max(dp[i-1], tab[i] + dp[i-2]);
        }
        printf("Case %d: %d\n", c, dp[n-1]);
        //cout<<"Case "<<count<< ": " << dp[n-1]<<endl;
    }


}

void totalways(int arr[3][3], int x, int y, int &ans, int m, int n)
{
    if(x==m && y==n)
    {
        ans++;
        cout<<"coming here\n";
        return;
    }

    int row[4] = {0,0,1,-1};
    int col[4] = {1,-1,0,0};

    for(int i =0;i<4;i++)
    {
        int nextx = x + row[i];
        int nexty = y + col[i];
        cout<<"next x"<<nextx<<endl;
        cout<<"next y"<<nexty<<endl;
        if(nextx >= 3 || nexty >=3 || nextx<0 || nexty<0 || arr[nextx][nexty]>arr[x][y])
            continue;
        else
        {
            cout<<"coming\n";
            totalways(arr,nextx,nexty,ans,m,n);
        }
    }

}


int main()
{
//    char *str = "011";
//    char res[20];
//    res[0] = str[0];
//    //countwalprimes(str, res, 1,1,3);

////    char str [] = "2+3";
////    int a = atoi(str);
////    cout<<a<<endl;



//    int arr[3][3] = {{10,9,8},
//                     {6,8,7},
//                     {5,4,1}};
//    int result = 0;
//    totalways(arr,0,0,result,2,2);
//    cout<<"total ans "<<result<<endl;

//    int a = 10;
//    void * p = (int*)a;
//    cout<<*(int*)p<<endl;

    //char b[2] = "a";
    //cout<<b<<endl;

    int c[2][2] = {0};
    cout<<c[1][1]<<endl;

    return 0;
}

