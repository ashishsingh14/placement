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

void xornumber()
{
    int t;
    cin>>t;
    long long int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0)
            cout<<"3"<<endl;
        else if(n%2==0)
        {
            cout<<"-1"<<endl;
        }
    }
}

bool tocheckifchar(char a)
{
    if(a>='a' && a<='z')
        return true;
    return false;
}

void wildcardmatching()
{
    int t;
    string s1,s2;
    cin>>t;
    int len1,len2;
    while(t--)
    {
        cin>>s1>>s2;
        len1 = s1.size();
        len2 = s2.size();
        if(len1+len2==0)
        {
            cout<<"Yes"<<endl;
        }
        int i = 0,j=0;
        while(true)
        {
            if((s1[i]==s2[j]) ||(tocheckifchar(s1[i]) && s2[j]=='?') || (tocheckifchar(s2[j]) && s1[i]=='?') )
            {
                i++;j++;
            }
            else if(tocheckifchar(s1[i]) && tocheckifchar(s1[i]) && s1[i]!=s2[j])
            {
                cout<<"No"<<endl;
                break;
            }
            if(i==len1 && j==len2)
            {
                cout<<"Yes"<<endl;
                break;
            }
        }
    }
}

int main()
{
    wildcardmatching();
    return 0;
}

