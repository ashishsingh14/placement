#include "functions.h"
int x[] = {0, 1, 1, -1, 1, 0, -1, -1};
int y[] = {1, 0, 1, 1, -1, -1, 0, -1};

int isvalid(int i, int j)
{
    if(i<0 || i>=size || j<0 || j>=size)
        return 0;
    return 1;
}

bool isadjacent(char a, char b)
{
    return ((b-a)==1);
}

void fibonacchimodified()
{
    int a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    long long int table[n+1];

    table[0] = a;
    table[1] = b;

    for(int i =2;i<n;i++)
    {
        table[i] = table[i-1]*table[i-1] + table[i-2];
    }

    cout<<table[n-1]<<endl;
}

void candies()
{
    int n;
    cin>>n;
    int c[n];
    for(int i =0;i<n;i++)
    {
        cin>>c[i];
    }

    int dp[n];

    for(int i =0;i<n;i++)
        dp[i] = 1;
    for(int i =1;i<n;i++)
    {
        if(c[i]>c[i-1])
            dp[i] = dp[i-1] +1;

    }

    for(int i =0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    for(int i = n-2;i>=0;i--)
    {
        if(c[i]>c[i+1])
            dp[i] = max(dp[i+1] +1,dp[i]);

    }

    for(int i =0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    long long ans =0;
    for(int i =0;i<n;i++)
    {
        ans +=dp[i];
    }
    cout<<ans<<endl;
}

int helperutil(char arr[size][size],int dp[size][size], int i, int j,char p)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    int res = 0;
    for(int k =0;k<8;k++)
    {
        if(isvalid(i+x[k],j+y[k]) && isadjacent(p,arr[i+x[k]][j+y[k]]))
            res = max(res, 1+ helperutil(arr,dp,i+x[k],j+y[k],arr[i+x[k]][j
                      +y[k]]));

    }

    return dp[i][j] = res;
}


void findlongestlength()
{
    char arr[size][size] = {'a','c','d', 'h','b','e','t','g','f'};

    char s = 'e';

    int dp[size][size];
    memset(dp,-1,sizeof(dp));
    int res;
    for(int i =0;i<size;i++)
    {
        for(int j =0;j<size;j++)
        {
            if(arr[i][j]==s)
            {
                res = helperutil(arr,dp,i,j,s);
            }
        }
    }

    cout<<"max length is "<<res<<endl;
}

void stock()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int price[n];
        for(int i = 0;i<n;i++)
            cin>>price[i];
        int dp[n];
        dp[0] = 0;

        for(int i =1;i<n;i++)
        {
            dp[i] = 0;
            for(int j =0;j<i;j++)
            {
                //dp[i] = max(price[i]-price[j],dp[i]);
                if(price[i]>price[j])
                    dp[i] = max(dp[i] + price[i]-price[j],dp[i]);
                else
                    dp[i] = dp[i-1];
            }
        }

        for(int j =0;j<n;j++)
        {
            cout<<dp[j]<<" ";
        }

        cout<<dp[n-1]<<endl;

    }
}

