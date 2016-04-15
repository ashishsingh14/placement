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
   int i =0;
   while(getline(cin,s))
   {
       //function(s);
       int p = s.find(' ');
       cout<<"space is "<<p<<endl;
       string x = s.substr(1,p-1);
       cout<<x<<endl;
       if(i==n)
           break;
       i++;
   }


}


void maximumsubpath()
{
    int ar1[] = {2, 3, 7, 10, 12};
    int ar2[] = {1, 5, 7, 8};
    int n = sizeof(ar1)/sizeof(ar1[0]);
    int m = sizeof(ar2)/sizeof(ar2[0]);

    int i, j ;
    i = j = 0;
    int sum1,sum2;
    sum1 = sum2= 0;
    int ans = 0;
    while(i<n && j<m)
    {
        if(ar1[i]<ar2[j])
        {
            sum1 += ar1[i];
            i++;

        }
        else if(ar2[j]<ar1[i])
        {
            sum2 += ar2[j];
            j++;
        }
        else
        {
            ans += max(sum1, sum2);
            //cout<<"sum1 "<<sum1<<endl;
            //cout<<"sum2 "<<sum2<<endl;
            sum1 =0, sum2 = 0;
            while(i<n && j<m && ar1[i]==ar2[j])
            {
                ans+= ar1[i];
                i++;
                j++;
            }

        }
    }

    while(i<n)
    {
        sum1 += ar1[i];
        i++;
    }

    while(j<m)
    {
        sum2 += ar2[j];
        j++;
    }
    ans += max(sum1,sum2);
    cout<<"maximum value is "<<ans<<endl;

}

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

void fraction()
{
    string s = "3/4+5/4";
    char * copy = new char[s.size()+1];
    strcpy(copy,s.c_str());
    char * t= strtok(copy,"+,/");
    int num[4];
    int j =0;
    while(t!=NULL)
    {
        num[j++] = atoi(t);
        t = strtok(NULL, "+,/");
    }

    for(int i =0;i<j;i++)
        cout<<num[i]<<" ";
    int lcm = num[1]*num[3];
    cout<<endl<<lcm;
    int x = num[0] * num[3];
    int y = num[2] * num[1];
    int sum = x+y;
    cout<<"sum"<<sum<<endl;

    int g = gcd(sum, lcm);
    cout<<g<<endl;

    cout<<(sum/g)<<"/"<<(lcm/g)<<endl;

}
int a[101][101];
bool isob[101][101];
vector<int>dp[101][101];
void kthshortestpath()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>n>>m;

        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                string s;
                stringstream ss;
                ss.clear();
                cin>>s;
                if(s=="##")
                {
                    isob[i][j] = true;
                    a[i][j] = -1;
                }
                else
                {
                    ss<<s;
                    ss>>a[i][j];
                }

            }
        }

        if(!isob[0][0])
            dp[0][0].push_back(a[0][0]);

        for(int i =1;i<n;i++)
        {
            if(!isob[i][0])
            {
                if(dp[i-1][0].size()>0)
                {
                    dp[i][0].push_back(a[i][0] + dp[i-1][0][0]);
                }
            }
        }

        for(int j =1;j<m;j++)
        {
            if(!isob[0][j])
            {
                if(dp[0][j].size()>0)
                {
                    dp[0][j].push_back(a[0][j] + dp[0][j-1][0]);
                }
            }
        }

        for(int i =1;i<n;i++)
        {
            for(int j =1;j<m;j++)
            {
                if(!isob[i][j])
                {
                    int s1 = dp[i-1][j].size();
                    int s2 = dp[i][j-1].size();
                    if(s1>0)
                    for(int k =0;k<s1;k++)
                    {
                        dp[i][j].push_back(a[i][j] + dp[i-1][j][k]);
                    }
                    if(s2>0)
                    for(int k =0;k<s2;k++)
                    {
                        dp[i][j].push_back(a[i][j] + dp[i][j-1][k]);
                    }
                }
            }
        }

        for(int i =1;i<n;i++)
        {
            for(int j =1;j<m;j++)
            {
                sort(dp[i][j].begin(),dp[i][j].end());
            }
        }

        int q;
        cin>>q;
        int a, b,x;
        while(q--)
        {
            cin>>a>>b>>x;
            if(isob[a][b])
            {
                cout << "Obstacle" << endl;
                continue;

            }
            else if(x>dp[a][b].size())
            {
                cout << "Not so many paths" << endl;
                continue;
            }
            else
                cout<<dp[a][b][x-1]<<endl;

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
    //maximumsubpath();
      //kthshortestpath();

    char a[] = "100 + ( 28 * 90)";
    int b[10];
    char * t = strtok(a, " ,+,*,(,)");
    int k =0;
    while(t!=NULL)
    {
        b[k++] = atoi(t);
        t = strtok(NULL, " ,+,*,(,)");
    }

    for(int i =0;i<k;i++)
        cout<<b[i]<<" ";

    return 0;
}

