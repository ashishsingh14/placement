#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define sez 50

int n,k;

void anagrams()
{
    int n;
    cin>>n;
    string arr[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr, arr+n);

    map<string ,vector<string> >m;


    for(int i =0;i<n;i++)
    {
        string a = arr[i];
        sort(a.begin(),a.end());
        m[a].push_back(arr[i]);

    }

    map<string ,vector<string> >::iterator i;
    int ans =0;
    for(i = m.begin();i!=m.end();i++)
    {
        if(i->second.size()>1)
            ans += i->second.size();

    }
    string smallest;
    for(int i =0;i<n;i++)
    {
        string a = arr[i];
        sort(a.begin(),a.end());
        if(m[a].size()>1)
        {
            smallest = arr[i];
            break;
        }
    }

    cout<<"the answer is "<<ans<<" "<<smallest<<endl;


}

bool issafe(int arr[sez][sez], int v, int *subject, int c)
{
    for(int i =0;i<n;i++)
    {
        if(arr[v][i] && subject[i]==c)
        {
            return false;
        }
    }
    return true;
}

bool check(int arr[sez][sez], int v, int * subject)
{
   if(v==n)
    return true;

   else
   {
       for(int i = 1;i<=k;i++)
       {
           if(issafe(arr,v,subject, i))
           {
               subject[v] = i;
               if(check(arr,v+1,subject))
                   return true;
               subject[v] = 0;
           }
       }
   }

   return false;
}


void assign()
{
    cin>>n>>k;
    int table[sez][sez];
    //memset(table,0,sizeof(table));
    for(int i =0;i<n;i++)
        for(int j =0;j<n;j++)
        {
           cin>>table[i][j];
        }

    int * subject = new int[n];
    memset(subject, 0 ,sizeof(subject));

    if(check(table,0, subject))
    {
        cout<<"possible\n";
    }
    else
        cout<<"not possible\n";

    for(int i =0;i<n;i++)
        cout<<subject[i]<<" ";
}

void packerandmover()
{
    int m,p;
    cin>>m>>p;
    int arr[p];
    for(int i =0;i<p;i++)
    {
        cin>>arr[i];
    }



}


int main()
{
    anagrams();
    return 0;
}

