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

string p = "fgheijklmnpabcdopqrstuvwxyz";
int search(string p, char a)
{
    for(int i =0;i<p.size();i++)
    {
        if(p[i]==a)
            return i;
    }
    return -1;
}

int compare(char x, char y)
{
    int a = search(p,x);
    int b = search(p,y);
    return a<b;
}

void sortaccordingtoorder()
{
    string s = "bcderfg";
    sort(s.begin(),s.end(),compare);
    cout<<s<<endl;

}


void teamformation()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a;
        cin>>n;
        vector<int>v(n);
        for(int i =0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);
        }

        sort(v.begin(),v.end());

        map<int, priority_queue< int , vector<int>, greater<int> > >m;
        for(int i =0;i<v.size();i++)
        {
            int now = 0;
            if(m[v[i]-1].size()>0)
            {
                now = m[v[i]-1].top();
                cout<<now<<endl;
                m[v[i]-1].pop();
            }
            now++;
            m[v[i]].push(now);

        }

        map<int, priority_queue< int , vector<int>, greater<int> > >::iterator i;
        int ans = INT_MIN;
        for(i = m.begin();i!=m.end();i++)
        {
            //if(i->second>0)
                cout<<i->first<<" "<<i->second.top()<<endl;
        }
        cout<<ans<<endl;
    }
}


void decipher()
{
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    bool x = 0;
    string final = "";
    for(int i =0;i<n;i++)
    {
        if(i>=k)
        {
            x = x^(final[i-k]-'0');
        }
        char a = ((s[i]-'0') ^ x) + '0';
        final.push_back(a);
        x = x^(a-'0');
    }
    cout<<final<<endl;
}

bool ifpoweroftwo(unsigned long long int n)
{
    return (n& !(n&(n-1)));
}

void reduceifpoweroftwo(unsigned long long int &n)
{
        //cout<<"power of two"<<endl;
        n = n>>1;
        //cout<<"n"<<n<<endl;

}

void reduceifnot(unsigned long long int &n)
{
    unsigned long long int c = n;
    int count  = 0;
    //cout<<"power of not two"<<endl;
    while(c)
    {
        c = c>>1;
        count++;
        //cout<<"count"<<endl;
    }
    n = n - (1<<(count-1));
    //cout<<"n"<<n<<endl;
}

void countergame()
{

    int t;
    cin>>t;
    while(t--)
    {
        unsigned long long int n;
        cin>>n;
        if(n==1)
        {
            //cout<<"Richard"<<endl;
            continue;
        }

        bool turn = 1;

        while(n>=1)
        {
           if(turn==1)
           {
               if(ifpoweroftwo(n))
               {
                   turn  = 0;
                   reduceifpoweroftwo(n);

               }
               else
               {
                   turn = 0;
                   reduceifnot(n);
               }
           }
           else
           {
               if(ifpoweroftwo(n))
               {
                   turn  = 1;
                   reduceifpoweroftwo(n);

               }
               else
               {
                   turn = 1 ;
                   reduceifnot(n);
               }
           }
           if(n==1)
               break;

        }

        if(turn==1)
            cout<<"Richard"<<endl;
        else
            cout<<"Louise"<<endl;

    }
}
bool prime[10000000];
void sieve()
{
    for(int i =0;i<10000000;i++)
        prime[i] = true;
    prime[0] = prime[1] = false;

    for(int i =2;i<10000000;i++)
    {
        if(prime[i])
        {
            for(int j = 2;j*i<10000000;j++)
                prime[i*j] = false;
        }
    }

}

void redjohnisback()
{
    sieve();

    int table[52];
    table[0] = 0;
    table[1] = 1;
    table[2] = 1;
    table[3] = 1;
    table[4] = 2;
    table[5] = 3;
    table[6] = 4;
    for(int i =7;i<=51;i++)
        table[i] = table[i-1] + table[i-4];

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        long long ans = 0;
        for(int i =1;i<=table[n];i++)
            if(prime[i])
                ans++;
        cout<<ans<<endl;
    }
}

void kmarsh()
{
    struct point
    {
        int l,b;
    };

    int m, n;
    cin>>m>>n;
    char d[m][n];
    for(int i =0;i<m;i++)
        for(int j =0;j<n;j++)
            cin>>d[i][j];

    point table[m][n];
    for(int i =0;i<m;i++)
        for(int j =0;j<n;j++)
        {
            table[i][j].l = 0;
            table[i][j].b = 0;
        }


//    for(int i =0;i<m;i++)
//    {
//        table[0][i].l = 0;
//        table[0][i].b = 0;
//    }
//    for(int i =0;i<m;i++)
//    {
//        table[i][0].l = 0;
//        table[i][0].b = 0;
//    }

    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(i==0 && j==0)
            {
                table[i][j].l = 0;
                table[i][j].b = 0;
                continue;

            }
            if(d[i][j]=='x')
            {
                table[i][j].l = 0;
                table[i][j].b = 0;
            }
            else
            {
                if(i>0 && d[i-1][j]!='x')
                {
                    table[i][j].b = table[i-1][j].b + 1;
                }
                if(j>0 && d[i][j-1]!='x')
                {
                    table[i][j].l = table[i][j-1].l + 1;
                }
            }
        }
    }

    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<table[i][j].l<<" "<<table[i][j].b;
            cout<<"   ";
        }
        cout<<endl;
    }


    int ma = INT_MIN;
    for(int i =0;i<m;i++)
        for(int j =0;j<n;j++)
            ma = max(ma,2*table[i][j].b + 2*table[i][j].l);
    if(ma!=0)
        cout<<ma<<endl;
    else
        cout<<"impossible"<<endl;


}


void findallstrings(char * arr, char *final, int j , int size, int k)
{
    if(k<0)
        return;
    if(k==0)
    {
        final[j] = '\0';
        cout<<final<<endl;
        return;
    }

    else
    {
        for(int i =0;i<size;i++)
        {
            final[j] = arr[i];
            findallstrings(arr,final,j+1,size,k-1);
        }
    }
}

void helperutil()
{
    char arr[] = {'a','b'};
    char final[20];

    findallstrings(arr,final,0,2,3);
}

int jk = 100;
//int jk;



int main()
{

    helperutil();
//    map<int, priority_queue< int , vector<int>, greater<int> > >m;
//    m[1].push(2);
//    m[1].push(4);
//    m[2].push(5);
//    m[2].push(10);

//    map<int, priority_queue< int , vector<int>, greater<int> > >::iterator i;
//    if(m[3].size()==0)
//    {
//        //m[3].pop();
//        cout<<"aser";
//    }
//    for(i = m.begin();i!=m.end();i++)
//        cout<<i->first<<" "<<i->second.top()<<endl;
    int arr[10] = {1};
    cout<<arr[1]<<endl;
    return 0;
}

