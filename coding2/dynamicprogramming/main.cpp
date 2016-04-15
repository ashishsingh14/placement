#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <limits.h>
using namespace std;

void longestincreasingsequence()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);

    int lis[n];
    for(int i =0;i<n;i++)
    {
        lis[i] = 1;
    }
    for(int i =1;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(arr[i]>arr[j] && lis[j]+1>lis[i])
                lis[i] = lis[j]+1;
        }

    }
    int len = INT_MIN;
    for(int i =0;i<n;i++)
    {
        len = max(len,lis[i]);

    }

    cout<<"The maximum length of lis is "<<len<<endl;

}

void longestdecreasingsequence()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);

    int lis[n];
    for(int i =0;i<n;i++)
    {
        lis[i] = 1;
    }
    for(int i =1;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(arr[i]<arr[j] && lis[j]+1>lis[i])
                lis[i] = lis[j]+1;
        }

    }
    int len = INT_MIN;
    for(int i =0;i<n;i++)
    {
        len = max(len,lis[i]);

    }

    cout<<"The maximum length of lds is "<<len<<endl;

}


void coinchangeproblem()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 3;

    int table[n+1];
    memset(table,0,sizeof(table));
    table[0] = 1;
    for(int i =1;i<=n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(i>=arr[j])
            {
                table[i] += table[i-arr[j]];
                //cout<<table[i]<<endl;
            }

        }
    }

    cout<<"Total number of ways are if order matter "<<table[n]<<endl;

    memset(table,0,sizeof(table));
    table[0] = 1;

    for(int j =0;j<m;j++)
    {
        for(int i =1;i<=n;i++)
        {
            if(i>=arr[j])
            {
                table[i] += table[i-arr[j]];
                cout<<i<<" "<<arr[j]<<" "<<table[i]<<endl;
            }
        }
    }
    cout<<"Total number of ways are if order doesn't matter "<<table[n]<<endl;
}

void longestpalindromicsequence()
{
    char seq[] = "ababb";
    int n = strlen(seq);
    int L[n][n];
    for(int i =0;i<n;i++)
    {
        L[i][i] = 1;
    }
    int j,i,len;
    for(len = 2;len<=n;len++)
    {
        for(i = 0;i<=(n-len);i++)
        {
            j = i+len-1;
            if(len==2 && seq[i]==seq[j])
            {
                //if(seq[i]==seq[j])
                    L[i][j] = 2;
            }
            else
            {
                if(seq[i]==seq[j])
                    L[i][j] = 2 + L[i+1][j-1];
                else
                    L[i][j] = max(L[i+1][j],L[i][j-1]);
            }
        }
    }
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"The longest palindromic sequence length is "<<L[0][n-1]<<endl;
}

void longestcommonpalindromicsubstring()
{

}

struct box {
    int h,w,d;
};

int compare(const void*a,const void*b)
{
    return ((*(box*)b).w  *  (*(box*)b).d) -
            ((*(box*)a).w  *  (*(box*)a).d);
}



void boxstacking()
{
    box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    int n = sizeof(arr)/sizeof(arr[0]);

    box*copy = new box[3*n];

    int index = 0;
    for(int i =0;i<n;i++)
    {
        copy[index] = arr[i];
        index++;

        copy[index].h = copy[i].d;
        copy[index].w = copy[i].h;
        copy[index].d = copy[i].w;
        index++;
        copy[index].h = copy[i].w;
        copy[index].w = copy[i].d;
        copy[index].d = copy[i].h;
        index++;
    }
    n = 3*n;
    qsort(copy,n,sizeof(box[0]),compare);

    for (int i = 0; i < n; i++ )
      printf("%d x %d x %d\n", copy[i].h, copy[i].w, copy[i].d);

    int msh[n];
    for(int i =0;i<n;i++)
    {
        msh[i] = 1;
    }
    for(int i =1;i<n;i++)
    {
        for(int j =0;j<i;j++)
        {
            if(copy[i].d < copy[j].d &&
                    copy[i].w<copy[j].w &&
                    msh[i]<msh[j] +copy[i].h)
            {
                msh[i] = msh[j] +copy[i].h;
            }
        }
    }

    int h = INT_MIN;
    for( int i =0;i<n;i++)
    {
        h = max(h,msh[i]);
    }

    cout<<"The maximum length in case of box stacking is "<<h<<endl;

}

void printarray(int *n,int size)
{
    for(int i =0;i<size;i++)
    {
        cout<<n[i]<<" ";
    }
    cout<<endl;
}

int findminimumcoinsrecursive(int * arr, int size, int n, int index)
{
    static int print[10];
    if(n==0)
    {
        printarray(print, index);
        return 0;
    }
    if(n<0)
        return INT_MAX;
    int count = 0;
    int ans = INT_MAX;
    for(int i =0;i<size;i++)
    {
        print[index] = arr[i];
        count = findminimumcoinsrecursive(arr,size,n-arr[i], index+1);
        if(count!=INT_MAX && count+1<ans)
            ans = count+1;
    }
    return ans;
}

void currencydenomination()
{
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        int table[n+1];
        int coins[4] = {2,3,5,7};
        //table[2] = 100;
        for(int i =0;i<=n;i++)
        {
            table[i] = 9999999;
        }
        table[0] = 0;
        table[4] = 2;
        table[2] = 1;
        table[3] = 1;
        table[5] = 1;
        table[6] = 2;
        table[7] = 1;
        for(int i =8;i<=n;i++)
        {
            for(int j =0;j<4;j++)
            {
                if(coins[j]<=i)
                {
                    int sub = table[i-coins[j]];
                    if(sub!=INT_MAX && sub+1<table[i])
                    table[i] = 1 + sub;
                }
            }
        }
//        for(int i =0;i<=n;i++)
//        {
//            cout<<table[i]<<" ";
//        }
//        cout<<endl;
        if(table[n]!=9999999)
            cout<<table[n]<<endl;
        else
            cout<<"-1"<<endl;
    }

}

long long countofndigitshelper(int sum, int n)
{
    if(n==0 && sum==0)
        return 1;
    if(n==0 && sum>0)
        return 0;
    long long count =0;
    for(int i =0;i<=9;i++)
    {
        if(sum>=i)
        {
            cout<<"s: "<<sum-i<<" n:"<<n-1<<endl;
            count+= countofndigitshelper(sum-i,n-1);
        }
    }
    return count;
}


long long int countofndigits(int sum, int n)
{
    long long count =0;
    for(int i =1;i<=9;i++)
    {
        if(sum>=i)
            count += countofndigitshelper(sum-i,n-1);
    }
    return count;
}

int countofndigitsdphelperdp(int sum, int n, int table[100][100])
{
    if(n==0 && sum==0)
        return 1;
    if(n==0 && sum>0)
        return 0;
    if(table[sum][n]!=-1)
    {
        return table[sum][n];
    }
    long long count =0;
    for(int i =0;i<=9;i++)
    {
        if(sum>=i)
        {
            //cout<<"s: "<<sum-i<<" n:"<<n-1<<endl;
            count+= countofndigitshelper(sum-i,n-1);
        }
    }
    return table[sum][n]= count;
}

long long countofndigitsdp(int sum, int n)
{
    int table[100][100];
    memset(table,-1,sizeof(table));
    long long count =0;
    for(int i =1;i<=9;i++)
    {
        if(sum>=i)
            count += countofndigitshelper(sum-i,n-1);
    }
    return count;
}

#define mod 1000000007

long long int gridwalking(int x, int d, int s)
{
    if(s==0 && x>=0 && x<=d)
        return 1;
    else
    {
        long long int ways = 0;
        if(x+1<=d && s>0)
        {
            cout<<x+1<<" "<<s-1<<endl;
            ways += gridwalking(x+1,d,s-1)%mod ;
        }
        if(x-1>=0 && s>0)
        {
            cout<<x-1<<" "<<s-1<<endl;
            ways+= gridwalking(x-1,d,s-1)%mod;
        }
        return ways;
    }



}
#define max 9999

void coloringhouse(int n)
{
    int value[] = {1,2,1};
    int color[n+1];
    int cost[n+1];
    for(int i =0;i<=n;i++)
    {
        cost[i] = max;
        color[i] = -1;
    }
    cost[0] = 0;
    //cost[1] = min(value[0],min(value[1],value[2]));
    //cout<<cost[1]<<endl;
    //color[1] = 0;
    for(int i = 1;i<=n;i++)
    {
        for(int j =0;j<3;j++)
        {
            if(i==1)
            {
                if(cost[i-1]!=max && cost[i]>(cost[i-1]+value[j]))
                {
                    cost[i] = cost[i-1]+value[j];
                    color[i] = j;
                }
            }
            else
            {
                if(color[i-1]!=j)
                {
                    //cout<<"for house "<<i<<" j "<<j<<endl;

                    if(cost[i-1]!=max && cost[i]>(cost[i-1]+value[j]))
                    {
                        cost[i] = cost[i-1]+value[j];
                        color[i] = j;
                    }
                }
            }
        }
    }
//    for(int i =1;i<=n;i++)
//        cout<<color[i]<<" ";
//    cout<<endl;
//    for(int i =0;i<=n;i++)
//        cout<<cost[i]<<" ";
//    cout<<endl;
    cout<<"Minimum cost is "<<cost[n]<<endl;

}

int main()
{
//    int coins[] =  {1,2,3};
//    int m = sizeof(coins)/sizeof(coins[0]);
//    int V = 4;
//    cout<<"Minimum coins are "<<currencydenomination(12);


//    char * a = "ashus",*p;
//    //char * p;
//    p = a;
//    a = "de";
//    cout<<a<<endl<<p;

//    char a [13] = "ashi";
//    a[5] = 'n';
//    cout<<a;

    //cout<<"With two digits "<<gridwalking(44,78,287)<<endl;
    coloringhouse(6);

    return 0;
}

