#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stack>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

void subarraylcm()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i =0;i<n;i++)
            cin>>arr[i];
        int start,end;
        int len = INT_MIN;
        for(int i =0;i<n-1;i++)
        {
            start = i;
            for(int j =i+1;j<n;j++)
            {
                if(gcd(arr[i],arr[j])==1)
                {
                    end = j;
                }
                if(end-start+1>len)
                    len = end-start;
            }

        }
    }
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

