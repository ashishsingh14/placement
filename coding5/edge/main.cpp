#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void function1()
{

    int m;
    cin>>m;
    int arr[m];
    for(int i =0;i<m;i++)
        cin>>arr[i];
    int n;
    cin>>n;
    int table[n+1];

   memset(table,0,sizeof(table));
   table[0] = 1;

   for(int j =0;j<m;j++)
   {
       for(int i =1;i<=n;i++)
       {
           if(i>=arr[j])
           {
               table[i] += table[i-arr[j]];

           }
       }
   }
   cout<<table[n]<<endl;
}

void reverse(string &s)
{
    int l = 0;
    int h = s.size()-1;
    while(l<h)
    {
        swap(s[l],s[h]);
        l++;
        h--;
    }
}

void function2()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    char map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
    reverse(s);
    cout<<s<<endl;
    int index;

    for(int i =0;i<s.size();i++)
    {
        if(s[i]=='.')
            index = 27;
        else if(s[i]=='_')
            index = 26;
        else
            index = s[i]-'A';
         s[i] = map[(index+n)%28];

    }
    cout<<s<<endl;

}

void function3()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
        cin>>arr[i];
    set<int>s;
    int i;
    for(i = 2;i<1000000;i++)
    {
        for(int j =0;j<n;j++)
        {
            s.insert(arr[j]%i);
        }
        if(s.size()==n)
            break;
        s.clear();
    }
    cout<<i<<endl;
}

int main()
{
    function3();
    return 0;
}

