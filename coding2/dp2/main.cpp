#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int kadane(string inp)
{
   int max_so_far = 0, max_ending_here = 0;
   int i;
   int end,start,tempstart;
   tempstart = 0;
   for(i = 0; i < inp.size(); i++)
   {
     if(inp[i]=='K')
         max_ending_here +=1;
     else
         max_ending_here -=1;
     //max_ending_here = max_ending_here + a[i];
     if (max_ending_here < 0)
     {
        max_ending_here = 0;
        tempstart = i+1;
     }
     if (max_so_far < max_ending_here)
     {
        max_so_far = max_ending_here;
        start = tempstart;
        end = i;
     }
    }
   int r =0;
   for(i = 0; i < inp.size(); i++)
       if(inp[i]=='R')
           r++;
   if(r==inp.size())
       return r;

//   for(int i =start;i<=end;i++)
//   {
//       cout<<inp[i];
//   }
//   cout<<endl;
   long long count =0;
   for(int i = 0;i<start;i++)
       if(inp[i]=='R')
           count++;
   for(int i = end+1;i<inp.size();i++)
       if(inp[i]=='R')
           count++;
    return count+end-start+1;
}

void maxSumIS()
{
    int n,k,t;

    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        long long int arr[n];
        for(int i =0;i<n;i++)
            cin>>arr[i];

       long long int *msis, i, j;
       long long int max = 0;
       msis = (long long int*) malloc ( sizeof( long long int ) * n );


       for ( i = 0; i < n; i++ )
          msis[i] = arr[i];


       for ( i = 1; i < n; i++ )
          for ( j = 0; j <=i-k-1; j++ )
             if ( arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];


       for ( i = 0; i < n; i++ )
          if ( max < msis[i] )
             max = msis[i];




        cout<<max<<endl;
        free( msis );
    }
}

int main()
{

    maxSumIS();
    return 0;
}

