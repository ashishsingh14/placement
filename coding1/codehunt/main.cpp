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

//bool checkwonderful(int *in, int n)
//{
//    int flag =0;
//    int result = 0;
//    for(int i =0;i<n;i++)
//    {
//        if(in[i]<0)
//        {
//            return false;
//        }
//        else
//        {
//            for(int j =0;j<i;j++)
//            {
//                if(in[i]<in[j])
//                    flag = 1;

//            }
//            if(flag==0)
//            {
//                result = max(result, i-j+1);
//            }

//        }
//        if(flag)
//        {
//            return false;
//        }
//    }
//    return true;
//}

void wonderfulsequence()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int in[n];
        for(int i =0;i<n;i++)
            cin>>in[i];
        list<int>*a = new list<int>[n];
        int j;
        j =0;

        a[j].push_back(in[0]);
        int last = in[0];
        for(int i =1;i<n;i++)
        {
            if(in[i]>last)
            {
                a[j].push_back(in[i]);
                last = in[i];
            }
            else
            {
                j++;
                a[j].push_back(in[i]);
                last = in[i];
            }

        }

        list<int>::iterator k;
        for(int i =0;i<n;i++)
        {
            if(a[i].size()>0)
            {
                for(k = a[i].begin();k!=a[i].end();k++)
                {
                    cout<<*k<<" ";
                }
                cout<<endl;
            }

        }

    }
}


int main()
{
    int l,mid,right,left,t,n,i,y;
    long num,nm,a[100001]={0};
    cin>>t;
    while(t--)
    {
        cin>>n;
        l=0;l=0;
        for(i=0;i<n;i++)
        {
            cin>>num;
            nm=num-i;
            if(nm>0)
            {
                left=0;right=l-1;y=-1;
                while(left<=right)
                {
                    mid=(left+right)>>1;
                    if(a[mid]<=nm)
                     left=mid+1;
                    else
                    {
                        y=mid;
                        right=mid-1;
                    }
                }
                a[(y>=0) ? (y) : (l++)]=nm;
            }
        }
        cout<<n-l<<endl;
    }
    return 0;
}

