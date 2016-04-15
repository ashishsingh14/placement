#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void function1()
{
    string s;
    int q;
    cin>>s;
    cin>>q;


    int table[26];
    for(int i =0;i<26;i++)
        table[i] = 0;

    int l = s.size();
    int j;
    for(int i=0;i<l;)
    {

        if(isalpha(s[i]))
        {
            j = i+1;
            int res = 0;
            while(isdigit(s[j]) && j<l)
            {
                res = res*10 + (s[j]-'0');
                j++;
            }

            table[s[i]-'a'] += res;
            i = j;

        }


    }

    for(int i =0;i<26;i++)
        cout<<table[i]<<" ";
    cout<<endl;
    long long int sum,k;
    while(q--)
    {

        cin>>k;
        sum = 0;
        int i;
        for(i =0;i<26;i++)
        {

            sum = sum + table[i];
            if(sum>=k)
                break;
        }
        if(i!=26)
        {
            char final = 'a' + i;
            cout<<final<<endl;
        }
        else
            cout<<"-1"<<endl;


    }
}

int main()
{
    function1();

    return 0;
}
