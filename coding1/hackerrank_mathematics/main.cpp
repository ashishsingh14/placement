#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <assert.h>
#define mod 1000000007
using namespace std;
typedef long long int ll;
void movingtiles()
{
    long long int l,s1,s2;
    cin>>l>>s1>>s2;
    int q;
    cin>>q;
    long long int sq;
    double ans;
    while(q--)
    {
        if(s1<s2)
        {
            long long temp = s1;
            s1 = s2;
            s2 = temp;
        }
        cin>>sq;
        ans = sqrt(2)*((double)l-sqrt(sq))/(double)(s1-s2);
        printf("%.4f\n",ans);
        //cout<<ans<<endl;
    }
}


bool cango(long long  int a, long long int b, long long int x, long long int y)
{
    if(a==x && b==y)
        return true;
    else if(a==b && x==y && a!=x)
        return false;
    else
        {

        if( cango(a+b,b,x,y) || cango(a,a+b,x,y) || cango(a-b,b,x,y) ||cango(a,a-b,x,y))
            return true;
        else return false;

    }

}

void restaurant()
{
    int t;
    int a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int x = min(a,b);
        int ans = 99999;

        for(int i = 1;i<=x;i++)
        {
            int t = (a*b)%(i*i);

            if(t==0)
                {
                 ans = min(ans,(a*b)/(i*i));
                }

           }
        cout<<ans<<endl;
    }

}

void divisors()
{
    int t;
    cin>>t;
    while(t--)
    {
    long long int n;
    cin>>n;
    long long int count = 0;



    for(long long int i = 1;i*i<=n;i++)
        {


        if(n%i==0)
            {

            if(i%2==0)
                count++;
            if((n/i)!=i && (n/i)%2==0)
                count++;
        }

    }

    cout<<count<<endl;


}
}

void strangegrid()
{
    long long int r,ans;
    int c;
    cin>>r>>c;
    long long int n;
    int a;
    if(r%2==0)
    {
        a = 1;
        n = (r-1)/2;
        n = n*5;
        n = n+c;
        ans = a + (n-1)*2;

    }
    else
    {
        a = 0;
        n = (r-1)/2;
        n = n*5;
        n = n+c;
        ans = a + (n-1)*2;
    }

    cout<<ans<<endl;
}

int binomialcoff(int n, int r)
{
    int ans = 1;

    if(r>(n-r))
        r = n-r;
    for(int i = 0;i<r;i++)
    {
        ans = ans*(n-i);
        ans = ans/(i+1);
    }

    return ans;
}

long long int power(long long int n, long long int p)
{
    long long int r = 1;
    for(long long int i = p;i>=1;)
    {
        if(i%2==0)
        {
            n = ((n%mod)*(n%mod))%mod;
            i = i>>1;

        }
        else
        {
            r = (r*n)%mod;
            i--;
        }
        //cout<<"value of r"<<r<<endl;
    }
    return r;
}

void eulercriteria()
{
     int t;
     cin>>t;
     long long int a, m,p;
     while(t--)
     {
         cin>>a>>m;
         p = (m-1)/2;

         if(power(a,p)==1)
             cout<<"YES"<<endl;
         else
             cout<<"NO"<<endl;

     }
}

int A[100009];
int B[100009];

void powerofbignumbers()
{
    int t;
    cin>>t;
    string a,b;
    long long int M = 1000000007;
    long long int N = 1000000006;
    while(t--)
    {
        cin>>a>>b;
        long long int t1,t2;
        t1=t2=0;
        for(int i =0;i<a.length();i++)
        {
            A[i] = a[i] - '0';

        }
        for(int i =0;i<b.length();i++)
        {
            B[i] = b[i] - '0';

        }
        assert(a[0]!='0');
        assert(b[0]!='0');
        assert(a.length() <=100000);
        assert(b.length() <= 100000);
        for(int i =0;i<a.length();i++)
        {
            t1 = (t1*10 + A[i])%M;
        }

        for(int i =0;i<b.length();i++)
        {
            t2 = (t2*10 + B[i])%N;
        }


        cout<<power(t1,t2)<<endl;

    }
}
int pow(ll a,int b)
{
ll ans=1;
while(b){
    if(b&1){
        ans = ans*a;
        assert(ans<=upper);
    }
    a=a*a;
    b>>=1;
}
return ans;
}

ll modpow(ll a,ll n,ll temp)
{
        ll res=1,y=a;
        while(n>0)
        {
                if(n&1)res=(res*y)%temp;
                y=(y*y)%temp;
                n/=2;
        }
        return res%temp;
}

long long int expn(long long int N, long long int K)
{
    if(K==0) return 1;
    if(K==1) return N%MOD;
    if(K%2 ==0)
    {
        long long int temp = expn(N,K/2);
        return (temp*temp)%MOD;
    }
    else
    {
        long long int temp = expn(N,K/2);
        temp = (temp*temp)%MOD;
        return (temp*N)%MOD;
    }
}

int main()
{
//    int t;
//    cin>>t;
//    long long int a,b,x,y;
//    while(t--)
//    {
//        cin>>a>>b>>x>>y;
//        if(cango(a,b,x,y))
//            {
//            cout<<"YES"<<endl;
//        }
//        else
//        {
//            cout<<"NO"<<endl;
//        }

//    }
    powerofbignumbers();
    return 0;
}

