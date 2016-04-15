#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void progresstracker(string s)
{
    int n = s.size();
    char * in = new char[n+1];
    strcpy(in, s.c_str());
    char * tok = strtok(in, ":");
    int time[3];
    int k =0;
    double rate = 5.0/42.0;
    while(tok!=NULL)
    {
        time[k++] = atoi(tok);
        tok = strtok(NULL, ":");
    }

    for(int i =0;i<k;i++)
        cout<<time[i]<<" ";
    int sec = 0;
    int fac = 3600;
    for(int i =0;i<k;i++)
    {
        sec += fac * time[i];
        fac = fac/60;
    }
    cout<<sec<<endl;

    cout<<(rate*sec)-1<<endl;

    cout<<endl;
}

int main()
{
    //progresstracker("00:14:00");

    return 0;
}

