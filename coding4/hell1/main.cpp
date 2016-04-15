#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

void calindex(int n)
{
    int res = 10;
    int factor = 1;
    int index = 0;
    while(n>=res)
    {
        index+= (pow(10,factor)-pow(10,factor-1))*factor;
        cout<<res<<endl;
        factor++;
        res = res*10;
    }
    res = res/10;
    index += (n-res)*factor;

    cout<<"index is "<<index<<endl;

}


void longestlength()
{
    int arr[] = {1,2,3,1,2,3};
    int n =sizeof(arr)/sizeof(arr[0]);
    int sum[n+1];

    sum[0] = 0;
    for(int i =1;i<=n;i++)
        sum[i] = arr[i-1] + sum[i-1];
    int ans =0;
    for(int l = 2;l<=n;l= l+2)
    {
        for(int i =0;i<=n-l;i++)
        {
            if((sum[i+l/2]-sum[i])==(sum[i+l]-sum[i+l/2]) && ans<l)
            {
                ans = l;
            }
        }
    }

    cout<<"Maximum length is "<<ans<<endl;

}

vector<int>v;

int solve(int *arr, int n, int sum)
{

    if(sum==0)
        return 1;
    if(n==0 && sum!=0)
    return 0;
//	if(arr[n-1]>sum)
//		return solve(arr, n-1, sum);
//
//	else
    if(arr[n-1]<=sum)
    {
        v.push_back(arr[n-1]);
    }
        return solve(arr, n-1, sum) || solve(arr, n-1, sum-arr[n-1]);

}

int a[100];

int sumofdigits(int n)
{
    if(n<10)
        return n*(n+1)/2;

    int d = log10(n);

    int p = ceil(pow(10,d));
    int msd = n/p;


    return msd*a[d] + (msd*(msd-1)/2)*p + msd*(1+n%p) + sumofdigits(n%p);

}

void function1()
{
    a[0] = 0;
    a[1] = 45;
    for(int i =2;i<=5;i++)
    {
        a[i] = a[i-1]*10 + 45*ceil(pow(10,i-1));
    }

    cout<<sumofdigits(328)<<endl;
}

void permute(char *s, int i, int n)
{
    if(i==n)
    {
        cout<<s<<endl;
        return;
    }
    if(isupper(s[i]))
    {
        if(i<n)
            permute(s,i+1,n);
    }

    for(int k = i;k<=n;k++)
    {
        if(islower(s[k]) && islower(s[i]))
        {
            swap(s[i],s[k]);
            permute(s,i+1,n);
            swap(s[i],s[k]);
        }
    }

}

struct sweet
{
    int s,q;
};

int compare1(sweet a, sweet b)
{
    return a.q>b.q;
}
int compare2(int a, int b)
{
    return a>b;
}

void royandsweets()
{
    int n,s,q,g,m,a,b;
    cin>>n;
    sweet input[n];
    for(int i =0;i<n;i++)
    {
        cin>>a>>b;
        input[i].s = a;
        input[i].q = b;
    }

    sort(input, input+n,compare1);
    cin>>g;
    int guest[g];
    for(int i =0;i<g;i++)
    {
        cin>>guest[i];
    }

    sort(guest,guest+g,compare2);

    int ans = 0;

    for(int i =0;i<g;i++)
    {

        for(int j =0;j<n;j++)
        {
            if(input[j].q>=guest[i] && input[j].s>=guest[i])
            {
                int x = input[j].q/guest[i];
                input[j].q = input[j].q%guest[i];
                ans += 100*x;
                break;
            }
        }
        sort(input, input+n,compare1);

    }

    cout<<ans<<endl;

}


void removesecondstring()
{
    string s = "HelloWorld";
    string r = "llo";
    int current,j,i;
    bool flag = false;
    char final[20];
    current = 0;
    j = 0;
    i = 0;
    int len1 = s.size();
    int len2 = r.size();
    while(i<len1)
    {
        final[current++] = s[i];

        if(s[i]==r[j])
        {
            flag = true;
            j++;
        }
        else if(flag)
        {
            j = 0;
            flag = false;
        }

        if(j==len2)
        {
            flag = false;
            current = current-j;
            j = 0;

        }
        i++;
    }

    final[current] = '\0';
    cout<<final<<endl;
}

void fill(){
    
    string s = "";
    string w = "";
    
}

void printstring(vector<string>v, string final, int index)
{
    if(final.size()==v.size())
    {
        cout<<final<<endl;
    }

    else
    {
        string temp = v[index];
        for(int i =0;i<temp.size();i++)
        {
            final.push_back(temp[i]);
            printstring(v,final,index+1);
            final.pop_back();
        }
    }
}

void cartesianProduct(vector<string> v,int start,char res[],int index){
    if(start==v.size()){
        for(int i=0;i<start;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else
    {
        string temp = v[index];
        for(int i =0;i<temp.size();i++)
        {
            res[start] = temp[i];
            cartesianProduct(v,start+1,res,index+1);

        }
    }
}

void function2()
{
//    vector<string>v;
//    v.push_back("abc");
//    v.push_back("def");
//    v.push_back("yz");

//    string final = "";
//    printstring(v,final, 0);

    vector<string> v;
    int start=0;
    char res[256];
    int index=0;
    v.push_back("ABCD");
    v.push_back("DEF");
    v.push_back("YZ");
    cartesianProduct(v,start,res,index);
}
map<string,int>m;
unordered_set<string> myset;

#define si 100

vector<int>table[si][si];



bool checkifgood(string s, int start, int end)
{
    string ans ="";
    string temp = "";
    if(table[start][end].size()>0)
    {
        return true;
    }

    for(int j =start;j<=end;j++)
    {
        ans = ans + s[j];
    }
    unordered_set<string>::const_iterator got;
    //cout<<"here is "<<ans<<endl;
    got = myset.find(ans);
    if(got!=myset.end())
    {
        dp[start][end].push_back(ans);
        return true;
    }
    else
    {
        int i;
        //cout<<"in else\n";
        for(i = start;i<=end;i++)
        {
            temp = temp + s[i];
            got = myset.find(temp);
            if(got!=myset.end())
             {

                 //cout<<"temp is "<<temp<<endl;
                 if(checkifgood(s,i+1,end))
                 {
                    string temp1 = temp;

                    int j = table[i+1][end].size();
                    for(int k =0;k<j;k++)
                    {
                        temp1 = temp1 + " "+table[i+1][end][k];
                    }
                    table[start][end].push_back(temp1);
                    return true;
                 }
                 else
                     table[start][end].pop_back();
            }
            else
                continue;
        }
        if(i==end+1)
            return false;
    }
    return false;
}



void function3()
{
    string s = "catsanddog";
    vector<string>final;
    int l = s.size()-1;
    vector<string>ans;
    string temp="";
    unordered_set<string>::const_iterator got;
    for(int i = 0;i<=l;i++)
    {
        temp = temp + s[i];
        got = myset.find(temp);
        if(got!=myset.end())
         {
             final.push_back(temp);
             if(checkifgood(s,i+1,l))
             {
                 string temp1 = final[0];
                 for(int i =1;i<final.size();i++)
                     temp1 = temp1 + " "+ final[i];
                 ans.push_back(temp1);
                 final.clear();
             }
              else
                  final.pop_back();
         }
        else
            continue;

    }

    //cout<<"size "<<ans.size()<<endl;
    for(int i =0;i<table[0][l].size();i++)
    {
        cout<<ans[i]<<endl;
    }
    //cout<<endl;


}


int main()
{
    char s[] = "AbDeC";
    myset = {"cat","cats","and","sand","dog"};

    function3();
    //swap(s[0],s[1]);
    //cout<<s<<endl;


    return 0;
}
