#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <limits.h>
using namespace std;

long long int minimum(long long int a, long long int b)
{
    return (a<b)?a:b;
}

void playwithstring()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string r ="";
        int len = s.size();
        for(int i =0;i<len;i++)
            r = r + s[len-i-1];
        //cout<<r<<endl<<s<<endl;

        int i,j;
        i = j = 1;
        int flag =0;
        while(i<len && j <len)
        {
            if(abs(s[i]-s[i-1])!=abs(r[i]-r[i-1]))
            {
                flag = 1;
                break;
            }
            else
            {
                i++,j++;
            }

        }
        if(flag)
            cout<<"Not Funny"<<endl;
        else
            cout<<"Funny"<<endl;

    }
}

void studentscore()
{
    long long int n;

    cin>>n;
    int arr[n];

    for(int i =0;i<n;i++)
        cin>>arr[i];
    int maxsumsofar = 0;
    int currentmax = 0;
    for(int i =0;i<n;i++)
    {
        currentmax+= arr[i];
        if(currentmax<0)
            currentmax = 0;
        else if(currentmax>maxsumsofar)
            maxsumsofar = currentmax;

    }
    int count =0;
    for(int i =0;i<n;i++)
    {
        if(arr[i]<0)
            count +=1;
    }
   if(count==n)
        cout<<"0"<<endl;
    else
        cout<<maxsumsofar<<endl;
}

void rahulbday()
{
    int t;
    cin>>t;
    long long int b,w,x,y,z;
    while(t--)
    {
     cin>>b>>w;
     cin>>x>>y>>z;


     long long int ans =0;

     if(x<=z&&y<=z)
     {
         ans = (long long)b*x + (long long)w*y;
     }
     else
     {
         if(x<=z && y>z)
         {
             ans = b*x;
             long long int c = minimum(y*w, (x+z)*w);
             ans = ans +c;
         }
         if(x>z && y<=z)
         {
             ans = w*y;
             long long int c = minimum(x*b, (y+z)*b);
             ans = ans +c;
         }
         if(x>z && y>z)
         {
             ans = x*b + y*w;
             ans = minimum(ans, (y*w) + (y+z)*b);
             ans = minimum(ans, (x*w) + (x+z)*w);

         }
     }
     cout<<ans<<endl;

    }
}

void printnonincreasingsequence(int sum, int* arr, int i)
{
    if(sum==0)
    {
        //cout<<"i"<<i<<endl;
        for(int j =0;j<i;j++)
            cout<<arr[j]<<" ";
        cout<<endl;
        return;
    }
    for(int k =1;k<=sum;k++)
    {
        if(k<=sum && (i==0 || k<=arr[i-1]))
        {
            arr[i] = k;
            printnonincreasingsequence(sum-k,arr,i+1);
        }
    }

}

void password()
{
    map<string, int>m;
    int t;
    cin>>t;
    string s;
    int count;
    while(t--)
    {
        cin>>s;
        int l = s.size();
        m[s]++;
        reverse(s.begin(),s.end());
        if(m[s])
        {
            count = m[s];
        }
        if(count)
        {
            cout<<l<<" "<<s[l/2]<<endl;
        }
    }
}

int deedeeshopping(int n, int *arr, int size)
{
    if(n==0)
        return 0;
    int res = INT_MAX;
    for(int i =0;i<size;i++)
        if(arr[i]<=n)
        {
            int sub = deedeeshopping(n-arr[i],arr,size);
            if(sub!=INT_MAX && 1+sub<res)
                res = sub +1;
        }
    return res;
}

void deedeeshoppingutil()
{
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        int arr[2] = {6,8};
        int res = deedeeshopping(n,arr,2);
        if(res!=INT_MAX)
            cout<<res<<endl;
        else
            cout<<"-1"<<endl;
    }
}

void printnonincreasingsequenceutil()
{
    int sum = 4;
    int arr[4];
    int i =0;
    printnonincreasingsequence(sum, arr, i);
}

void beverage()
{
    int n,sum;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }

    cin>>sum;
    sort(arr,arr+n);
    int flag =0;

    for(int i=0;i<n-2;i++)
    {
        int l,h;
        l = i+1;
        h = n-1;
        while(l<h)
        {
            if(arr[i]+arr[l]+arr[h]==sum)
            {
                flag = 1;
                break;
            }
            else if(arr[i]+arr[l]+arr[h]<sum)
                l++;
            else
                h--;
        }
        if(flag ==1)
            break;
    }

    if(flag)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
}

void softdrinks()
{
    char table[101][101][101];


    for(int i =0;i<101;i++)
    {
        for(int j =0;j<101;j++)
        {
            for(int k =0;k<101;k++)
            {
                if((i>0 && table[i-1][j][k]=='L')||
                        (j>0 && table[i][j-1][k]=='L')||
                        (k>0 && table[i][j][k-1]=='L')||
                        (i>0 && j>0 && table[i-1][j-1][k]=='L')||
                        (i>0 && k>0 && table[i-1][j][k-1]=='L')||
                        (j>0 && k>0 && table[i][j-1][k-1]=='L')||
                        (i>0 && k>0 && j>0 && table[i-1][j-1][k-1]=='L'))
                    table[i][j][k] = 'W';
                else
                    table[i][j][k] = 'L';
            }
        }
    }


    int q;
    cin>>q;
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(table[a][b][c]=='W')
            cout<<"Ashima"<<endl;
        else
            cout<<"Aishwarya"<<endl;
    }
}

int main()
{
    //beverage();
    softdrinks();
    return 0;
}
