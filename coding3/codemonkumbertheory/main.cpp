#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <limits.h>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

double findbinomialcoefficient(int n, int k)
{
    if(k>n-k)
        k = n-k;
    double res = 1;
    for(int i = 0;i<k;i++)
    {
        res = res*(n-i);
        res = res/(i+1);
    }

    return res;

}

void threesum()
{
    int n,t;
    cin>>t;
    int input[n];
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>input[i];
        int k =3;
        //double res = findbinomialcoefficient(n,k);
        //cout<<"res"<<res<<endl;
        double ans = 0;
        double ways =0;
        double res = 0;
        for(int i =0;i<n-2;i++)
        {
            for(int j = i+1;j<n-1;j++)
            {
                for(int k = j+1;k<n;k++)
                {
                    int sum = input[i]+input[j]+input[k];
                    int val = (int )cbrt(sum);
                    //cout<<"sum "<<sum<<"va:"<<val<<endl;
                    if(val*val*val==sum)
                        ways++;
                    res++;

                }
            }
        }
        //cout<<ways<<res<<endl;
        ans = ways/res;
        printf("%.9f\n",ways/res);
    }
}


int main()
{
    threesum();
//    double a = cbrt(29);
//    cout<<a<<endl;
    return 0;
}

