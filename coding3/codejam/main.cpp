#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#define size 1000000
using namespace std;

int prime[size];
char table[size];
void sieve()
{
    for(int i =0;i<size;i++)
        prime[i] = 1;
    prime[0] =0;
    prime[1] =1;
    for(int i =2;i*i<=size;i++)
    {
        if(prime[i])
            for(int j =i;j*i<size;j=j+1)
                prime[i*j] = 0;
    }


//    for(int i =0;i<100;i++)
//        if(prime[i])
//                cout<<i<<" "<<endl;
}


int calculatesum(long long int n)
{
    if(n<10)
        return prime[n];
    else
    {
        long long int sum =0;
        while(n)
        {
            sum += n%10;
            n = n/10;
        }
        return prime[sum];
    }
}

int precompute1(long long int i)
{
    if(i<10 && prime[i])
        return 0;
    else if(i<10 && !prime[i])
        return 1;
    else
    {
        long long int sum = calculatesum(i);
        if(prime[sum])
            return 0;
        else
        {
            if(prime[i])
                return 0;
            else
            {
                long long int c = i;
                while(c%2==0)
                {
                    c = c/2;
                }
                if(prime[calculatesum(c)])
                    return 1;
                for(int j = 3; j*j<=i;j=j+2)
                {
                    c = i;
                    while(c%j==0)
                        c = c/j;
                    if(prime[calculatesum(c)])
                    {
                        return 1;
                    }
                }
                return 0;
            }

        }
    }

}



void precompute()
{
    for(int i =1;i<=10000;i++)
    {
        if(i<10 && prime[i])
            table[i] = 'L';
        else if(i<10 && !prime[i])
            table[i] = 'W';
        else
        {
            long long int sum = calculatesum(i);
            if(prime[sum])
                table[i] = 'L';
            else
            {
                if(prime[i])
                    table[i]='L';
                else
                {
                    long long int c = i;
                    while(c%2==0)
                    {
                        c = c/2;
                    }
                    if(table[calculatesum(c)] == 'L')
                        table[i]='W';
                    for(int j = 3; j*j<=i;j=j+2)
                    {
                        c = i;
                        while(c%j==0)
                            c = c/j;
                        if(table[calculatesum(c)]=='L')
                        {
                            table[i] = 'W';
                            break;
                        }
                    }
                }

            }
        }

    }

//    for(int i =0;i<=1000;i++)
//        cout<<table[i]<<" ";
//    cout<<endl;

}


void gnumbers()
{
    int t;
    cin>>t;
    sieve();
    int count =0;
    long long int n;

    while(t--)
    {
        count++;
        cin>>n;
        printf("Case #%d: ", count);
        if(!precompute1(n))

            cout<<"Seymour"<<endl;
        else
            cout<<"Laurence"<<endl;
    }

}

int main()
{
    gnumbers();
    return 0;
}

