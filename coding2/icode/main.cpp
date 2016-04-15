#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <limits.h>
#include <assert.h>
#include <math.h>
using namespace std;

struct point
{
    int x,y;
};

void findmimimumdistance()
{
    int n;
    cin>>n;
    int pos;
    int * input = new int[n];
    for(int i =0;i<n;i++)
    {
        cin>>input[i];
    }

    sort(input, input + n);
    if(n%2!=0)
    {
        pos = n/2;
        cout<<input[pos]<<endl;
    }
    else
    {
        int first,second;
        first = second = 0;
        pos = n/2;
        for(int i = 0 ;i<n;i++)
        {
            first+= abs(input[i]-input[pos-1]) * abs(input[i]-input[pos-1])* abs(input[i]-input[pos-1]);
            second+= abs(input[i]-input[pos]) * abs(input[i]-input[pos]) * abs(input[i]-input[pos]);
        }
        if(first>second)
            cout<<input[pos]<<endl;
        else if(first-second==0)
            cout<<input[pos-1]<<endl;
        else
            cout<<input[pos-1]<<endl;

    }
    delete input;
}

void gameofstrings()
{
    int t;
    string input;
    cin>>t;
    while(t--)
    {
        cin>>input;
        int length = input.size();
        assert(length>=1 && length<=1000);
        int total = 0;
        if(input=="a")
        {
            cout<<"Alice"<<endl;
        }
        else
        {
            for(int i = 0;i<input.size();i++)
                total+= input[i]-'a';
            if(total&1)
            {
                cout<<"Alice"<<endl;
            }
            else
                cout<<"Bob"<<endl;
        }
    }
}

void tworectanglesoverlap()
{
    struct point topleft1,bottomright1,topleft2,bottomright2;
    cin>>topleft1.x>>topleft1.y>>bottomright1.x>>bottomright1.y;
    cin>>topleft2.x>>topleft2.y>>bottomright2.x>>bottomright2.y;
    if(bottomright2.y>topleft1.y || bottomright1.y>topleft2.y)
    {
        cout<<"no overlap"<<endl;
    }
    else if(bottomright1.x<topleft2.x || bottomright2.x<topleft1.x)
    {
        cout<<"no overlap"<<endl;
    }
    else
        cout<<"overlap"<<endl;
}

int countsebbits(long long int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}
long long int power(int n, int p)
{
    long long int r = 1;
    for(long long int i = p;i>=1;)
    {
        if(i%2==0)
        {
            n = (n*n);
            i = i>>1;

        }
        else
        {
            r = (r*n);
            i--;
        }
        //cout<<"value of r"<<r<<endl;
    }
    return r;
}

void helpciscomanager()
{
    int t;
    int n,k;
    cin>>t;
    int c = 0;
    double input [1000];
    while(t--)
    {
        c = c+1;
        cin>>n>>k;
        for(int i =0;i<n;i++)
        {
            cin>>input[i];
        }
        double ans = 0;
        double val = 1;
        for(long long int i = 0;i<power(2,n);i++)
        {
            if(countsebbits(i)==k)
            {
                val = 1;
                for(int j = 0;j<n;j++)
                {
                    if(i&(1<<j))
                        val = val*input[n-j-1];
                    else
                        val = val*(1-input[n-j-1]);
                }

                ans += val;
            }
        }
        printf("Case %d: %.2f\n",c,ans);
    }
}
void helpciscomanagerdynamichelper(double *arr, int n , int k,int c);

void helpciscomanagerdynamic()
{
    int t;
    int n,k;
    cin>>t;
    int c = 0;
    double input [1000];
    while(t--)
    {
        c = c+1;
        cin>>n>>k;
        for(int i =0;i<n;i++)
        {
            cin>>input[i];
        }
        helpciscomanagerdynamichelper(input,n,k,c);
    }
}

void helpciscomanagerdynamichelper(double *arr, int n , int k,int c)
{
    double val = 1;
    double table[n+1][k+1];

    int i,j;
    for(j = 0;j<=k;j++)
    {
        table[0][j] = 0;
    }
    for(i = 1;i<=n;i++)
    {
        val = 1;
        for(int k = 0;k<i;k++)
        {
            val = val*(1-arr[k]);
        }
        table[i][0] = val;
    }
    table[0][0] = 1;
    for(i = 1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(j>i)
            {
                table[i][j] = 0;
            }
            else if(j==i)
            {
                table[i][j] = arr[i-1]*table[i-1][j-1];
            }
            else
            {
                table[i][j] =  arr[i-1]*table[i-1][j-1] + (1-arr[i-1])*table[i-1][j];
            }
        }
    }

//    cout<<"printing matrix"<<endl;
//    for(int i = 0;i<=n;i++)
//    {
//        for(int j =0;j<=k;j++)
//            cout<<table[i][j]<<" ";
//        cout<<endl;
//    }

    printf("Case %d: %.2f\n",c,table[n][k]);


}


int main()
{
    helpciscomanagerdynamic();
    //cout<<'b'-'a'<<endl;
    return 0;
}

