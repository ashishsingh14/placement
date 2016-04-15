#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <vector>
using namespace std;
#include <math.h>
#define SIZE 100005
#define SIZEP 10000004
bool prime[SIZEP];
#define MOD 1000000007
long long int power(long long int n, long long p);

void potions()
{
    long long int A, B;
    char day[SIZE];
    cin>>A>>B;
    cin>>day;
    int l = strlen(day);
    long long ans = 0;
    long long int pow = A;
    for(int i = 0;i<l;i++)
    {
        if(day[i]=='1')
        {
           ans+= (pow);
           ans = ans%B;
        }

        pow = (pow*pow)%B;

    }

    cout<<ans<<endl;
}


long long int power(long long int n, long long int p)
{
    long long int r = 1;
    for(long long int i = p;i>=1;)
    {
        if(i%2==0)
        {
            n = (n*n)%MOD;
            i = i>>1;

        }
        else
        {
            r = (r*n)%MOD;
            i--;
        }
        //cout<<"value of r"<<r<<endl;
    }
    return r;
}

void sieveforprimes()
{
    for(int i = 0;i*i<=SIZEP;i++)
        prime[i]=1;
    prime[0] = 0;
    prime[1] = 1;
    for(int i = 2;i<SIZEP;i++)
    {
        if(prime[i])
        {
            for(int j = 2;i*j<SIZEP;j++)
            {
                prime[i*j] = 0;
            }
        }
    }
}

void chanduinterns()
{
    sieveforprimes();
    long long int n,x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(prime[x])
            cout<<"NO"<<endl;
        else
        {
            int sq = sqrt(x);
            //cout<<sq<<endl;
            if(prime[sq] && sq*sq==x)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;

        }
    }

}

long long int gcd(long long int a, long long int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

void confusedmonk()
{
    int n;
    cin>>n;
    int in[n];
    for(int i = 0;i<n;i++)
    {
        cin>>in[i];
    }
    long long int g = in[0];
    long long int tp = 1;
    for(int i =0;i<n;i++)
    {
        g = gcd(in[i],g);
        tp = (tp *in[i])%MOD;
        //cout<<"a"<<g<<endl<<tp<<endl;

    }


    long long ans = power(tp,g);

    cout<<ans<<endl;

}

void generousmaggi()
{
    int t;
    long long int x,y;
    cin>>t;

    while(t--)
    {
        cin>>x>>y;
        if(x-y==0 || y>x)
        {
            cout<<"-1"<<endl;
            continue;
        }
        else
        {
            vector<int>v;
            long long int z = x-y;
            long long ans =0;
            for(int i = 1;i*i<=z;i++)
                if(z%i==0)
                {
                    if(i>y)ans++;
                    if((z/i)!=i && (z/i)>y)ans++;
                }

            cout<<ans<<endl;
        }
    }
}

/*
 * ll fast_exp(int base, int exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}*/

#define size 1000000
void modifiedsieve()
{
    int * prime = new int[size];
    int * primefactors = new int[size];
    for(int i =0;i<1000000;i++)
    {
        prime[i] = 1;
        primefactors[i] =0;
    }
    prime[0] = 0;
    prime[1] = 0;

    for(int i =2;i<size;i++)
    {
        if(prime[i])
        {
            primefactors[i] = 1;
            for(int j = 2*i;j<size;j=j+i)
            {
                prime[j] = 0;
                primefactors[j] = primefactors[j]+1;
            }
        }
    }

    int n;
    cin>>n;
    int q;
    cin>>q;
    while(q--)
    {
        int k;
        cin>>k;
        long long int ans =0;
        for(int i =2;i<=n;i++)
            if(primefactors[i]==k)
                ans++;
        cout<<ans<<endl;
    }
    delete []prime;
    delete [] primefactors;
}

int main()
{
    //confusedmonk();
    //cout<<power(12,2);
    modifiedsieve();
    return 0;
}

