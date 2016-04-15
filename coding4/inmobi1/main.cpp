#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

void detectingvalidandinvalid()
{
    int n;
    cin>>n;
    char s[100];
    double val[3];
    while(n--)
    {
        cin>>s;
        char * token = strtok(s," ,(,)");
        while(token!=NULL)
        {
            double d = strtod(token,NULL);
            cout<<d<<endl;
            token = strtok(NULL," ,(,)");
        }

    }
}

void function(string s)
{
    int p = s.find(' ');
    cout<<"space is "<<p<<endl;
    string x = s.substr(1,p-1);
    cout<<x<<endl;
}

void detectingvalidandinvalid1()
{
   int n;
   cin>>n;
   string s;
   getline(cin,s);
   while(n--)
   {
       //function(s);
       getline(cin,s);
       int p = s.find(' ');
       cout<<s<<endl;
       cout<<"space is "<<p<<endl;
       string x = s.substr(1,p-2);
       string y = s.substr(p+1, s.size()-p-2);
       cout<<x<<endl<<y<<endl;


   }


}

void finddomainname()
{
    int n;
    cin>>n;
    string s;
    getline(cin,s);
    string match[] = {"http://", "https://", "http://www.","https://www."};
    vector<string>v;
    while(n--)
    {
        getline(cin,s);

        for(int i =0;i<4;i++)
        {
            int p = s.find(match[i]);
            if(p!=-1)
            {

            }
        }
    }
}


int main()
{
//    string s = "(12.3, 1222)";
//    int p = s.find(' ');
//    cout<<"space is "<<p<<endl;
//    string x = s.substr(1,p-1);
//    string y = s.substr(p+1, s.size()-p-2);
//    cout<<x<<endl<<y<<endl;
    detectingvalidandinvalid1();
    return 0;
}

