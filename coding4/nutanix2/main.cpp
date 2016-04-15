#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

void reverse(vector<int>&v, int start, int end)
{
    int l = start;
    int h = end;
    while(l<h)
    {
        swap(v[l],v[h]);
        l++;
        h--;
    }
}

void signature()
{
    string sig = "iiidd";
    vector<int>v;
    for(int i = 0;i<=sig.size();i++)
    {
        v.push_back(i+1);
    }

    int start = -1;
    int end = -1;
//    reverse(v,0,v.size()-1);
//    for(int i = 0;i<v.size();i++)
//    {
//        cout<<v[i]<<" ";
//    }
    cout<<endl;
    for(int i = 0;i<sig.size();i++)
    {
        if(sig[i]=='d' && start==-1)
        {
            start = i;
        }
        else if((sig[i]=='i' && end == -1 && start!=-1))
        {
            end = i;
            reverse(v,start,end);
            start = -1;
            end = -1;
        }
        if((i==(sig.size()-1) ) && sig[i]=='d' && start!=-1 && end==-1)
        {
            end = i+1;
            reverse(v,start,end);

        }
    }

    for(int i = 0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

}

void minmumsteps()
{
    int n = 10;
    //int arr[3][3] = {2,1,2,7,8,2,5,6,4};
    int a = 3, b = 4;
    int arr[3][4] = {2,4,1,2,6,10,11,12,3,5,8,1};
    int table[3][4];
    for(int i =0;i<a;i++)
        for(int j =0;j<b;j++)
            table[i][j] = INT_MAX;

    table[0][0] = 0;


    for(int i =0;i<a;i++)
    {
        for(int j =0;j<b;j++)
        {
            if(table[i][j]!=INT_MAX)
            {
                if(arr[i][j]>0)
                {
                    int nextx = i+arr[i][j];
                    if(nextx>=0 && nextx<a)
                    {
                        table[nextx][j] = min(table[i][j] +1,table[nextx][j]);
                    }
                    int nexty = j+arr[i][j];
                    if(nexty>=0 && nexty<b)
                    {
                        table[i][nexty] = min(table[i][j] +1,table[i][nexty]);
                }
                }
            }
        }
    }
    for(int i =0;i<a;i++)
    {
        for(int j =0;j<b;j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }


    if(table[a-1][b-1]!=0)
    {
        cout<<"min steps "<<table[a-1][b-1]<<endl;
    }
    else
        cout<<"not possible\n";
}

//void calculateexpresssion(int input, char *buff, int i,int j,int n)
//{
//    if(i==n)
//    {
//        buff[j]= '\0';
//        string ob(buff);
//        int sum = 5;
//        checkifequaltogivenvalue(ob,sum);

//    }
//    buff[j] = input[i] + '0';
//    calculateexpresssion(input,buff,i+1,j+1,n);
//    buf[j] = '+';
//    buf[j+1] = input[i]+ '0';
//    calculateexpresssion(input,buff,i+1,j+2,n);
//    buf[j] = '-';
//    buf[j+1] = input[i]+ '0';
//    calculateexpresssion(input,buff,i+1,j+2,n);

//}


void evaluateexpression(string input)
{
    int i =0;
    int res = 0;
    char sym;
    stack<int>s;
    stack<char>o;
    while(i<input.size())
    {
        int j = i;
        if(isdigit(input[j]))
        {
            while(isdigit(input[j]) && j<input.size())
            {
                res = res*10 + (input[j]-'0');
                j++;

            }
            cout<<"res "<<res<<endl;
            s.push(res);
            res = 0;
            i = j;
        }

        if(s.size()>1 && !o.empty())
        {
            int right = s.top();
            cout<<"right "<<right<<endl;
            s.pop();
            int left = s.top();
            cout<<"left "<<left<<endl;
            s.pop();
            char operat = o.top();
            if(operat=='+')
            {
                cout<<left+right;
                s.push(left+right);
            }
            else if(operat=='-')
            {
                cout<<left-right;
                s.push(left-right);
            }
            o.pop();
        }


        if((input[i]=='+' || input[i]=='-') && i<input.size())
        {

            o.push(input[i]);
            i++;
        }



    }

    cout<<"result is "<<s.top()<<endl;
}

void findsmalleststring()
{
    string in = "abard";
    bool visited[26];
    memset(visited,false,sizeof(visited));
    int l = in.size();
    int next[l];
    int last[26];
    for(int i = 0;i<26;i++)
    {
        last[i] = -1;
    }
    for(int i =in.size()-1;i>=0;i--)
    {
        int index = in[i]-'a';
        next[i] = last[index];
        last[index] = i;
    }

    string ans = "";
    for(int i =0;i<in.size();i++)
    {
        int cur = in[i]-'a';
        if(visited[cur]==true)
            continue;
        if(next[i]==-1)
        {
            ans += in[i];
            visited[cur] = true;
        }
        else
        {
            int j = i+1;
            char smaller = in[i];

            while(j<l)
            {
                if(visited[in[j]-'a']==false)
                {
                    smaller = min(smaller,in[j]);
                        if(next[j]==-1)break;
                }
                j++;

            }
            if(in[i]<=smaller)
            {
                ans += in[i];
                visited[cur] = true;
            }
        }

    }

    cout<<ans<<endl;


}

void minoperation()
{
    string a,b;
    a = "abced",b = "abcde";
    int n = a.size();
    int i,j;
    int ans = 0;
    for(i = n-1,j = n-1;i>=0;)
    {
        if(a[i]==b[j])
        {
            i--;
            j--;

        }
        else
        {
            for(int k = i-1;k>=0;k--)
            {
                if(a[k]==b[j] && k!=0)
                {
                    swap(a[k],a[0]);
                    swap(a[0],a[i]);
                    ans += 2;
                    break;
                }
                else if(a[k]==b[j] && k==0)
                {
                    swap(a[0],a[i]);
                    ans += 1;
                    break;
                }
            }
            i--;
            j--;

        }
    }

    cout<<"min operations are "<<ans<<endl;
}

void minimumchartomakebothstringssame()
{
    string a,b;
    a = "sunday";
    b = "saturday";
    int n = a.size();
    int m = b.size();
    int table[n+1][m+1];
    for(int i =0;i<=n;i++)
    {
        for(int j =0;j<=m;j++)
        {
            if(i==0)
                table[i][j] = j;
            else if(j==0)
                table[i][j] = i;
            else if(a[i-1]==b[j-1])
                table[i][j] = table[i-1][j-1];
            else
                table[i][j] = 1 +min(table[i-1][j],min(table[i-1][j-1],
                        table[i][j-1]));

        }


    }
    cout<<"min operations are "<<table[n][m];

}

void minimumjumps()
{
    int arr[] = {1, 3, 6, 1, 0, 9};
    int size = sizeof(arr)/sizeof(int);
    int jumps[size];
    if(arr[0]==0)
    {
        cout<<"not possible";
        return;
    }

    jumps[0] = 0;
    for(int i =1;i<size;i++)
        jumps[i] = INT_MAX;

    for(int i = 1;i<size;i++)
    {
        for(int j =0;j<i;j++)
        {
            if(j+arr[j]>=i && jumps[j]!=INT_MAX)
            {
                jumps[i] = min(jumps[i],jumps[j]+1);
            }
        }
    }

    cout<<"min jumps are "<<jumps[size-1]<<endl;
}

void bitoniclongest()
{
     int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
     int n = sizeof(arr)/sizeof(arr[0]);
     int lis[n],lds[n];
     for(int i =0;i<n;i++)
     {
         lis[i] = lds[i] = 1;
     }

     for(int i =1;i<n;i++)
     {
         for(int j =0;j<i;j++)
         {
             if(arr[i]>arr[j] && lis[i]<lis[j]+1)
             {
                 lis[i] = lis[j] +1;
             }
         }
     }

     for(int i = n-2;i>=0;i--)
     {
         for(int j =n-1;j>i;j--)
         {
             if(arr[i]>arr[j] && lds[i]<lds[j]+1)
             {
                 lds[i] = lds[j] +1;
             }
         }
     }

     int ma = lis[0]+lds[0]-1;

     for(int i =1;i<n;i++)
     {
         ma = max(ma,lis[i]+lds[i]-1);
     }

     cout<<"max length is "<<ma<<endl;
}

void printarray(int *a, int l)
{
    for(int i=0; i<l; i++)
    {
        cout<<a[i];
    }
    cout<<endl;
}

void multiply_largenumbers()
{
    char a[] = "12345";
    char b[] = "2367";
    int l1 = strlen(a);
    int l2 = strlen(b);
    int l3 = l1 + l2;
    int c[l3];
    memset(c, 0, sizeof(int)*l3);

    for(int i =l1-1;i>=0;i--)
    {
        for(int j =l2-1;j>=0;j--)
        {
            c[i+j+1]+= (a[i] - '0') * (b[j]-'0');
        }
    }

    for(int i = l3-1;i>0;i--)
    {
        if(c[i]>=10)
        {
            c[i-1]+= c[i]/10;
            c[i] = c[i]%10;

        }
    }
    printarray(c, l3);
}

void differentways(string a, char*buff, int i, int j, int left)
{
    if(i==a.size())
    {
        buff[j+1] = '\0';
        cout<<buff<<endl;
    }

    if(a[i]>='0' && a[i]<='9')
    {
        buff[j] = '(';
        buff[j+1] = a[i];
        left++;
        differentways(a,buff,j+2,i+1,left,right);
    }

    if((a[i]=='+' || a[i]=='-') && left>=1)
    {
        buff[j] = a[i];
        buff[j+1] = a[i+1];
        buff[j+2] = ')';
        //left++;
        left--;
        differentways(a,buff,j+3,i+2,left,right);
    }


}

int main()
{
    //string a = "24+13-10";
    //evaluateexpression(a);
    //minimumjumps();
    string s = "abcdef";
    //reverse(s.begin()+1, s.begin()+4);
    string a = "1+2+3";
    char buff[50];
    buff[0] = '(';
    int left,right;
    left = 1;
    right =0;
    //differentways(a,buff,0,1,left);


    return 0;
}

