#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;


int binarysearch(int *a, int low, int high)
    {

    if(high>=low)
        {
        int mid = low + (high-low)/2;
        cout<<"mid"<<mid<<endl;
        if((mid==0 && a[mid+1]==0 && a[mid]==1) || (a[mid]==1 && a[mid+1]==0) || (mid==high && a[mid]==1))
            return mid;

            if(a[mid]==0)
                return binarysearch(a,low,mid-1);
            else
                return binarysearch(a,mid+1,high);
    }
    return -1;
}

int maxOnes(int *a, int N) {
/* N: size of the array
The array is a row-major contiguous buffer of size N*N,
it's a 2-D array
*/

    int rownumber;
    int maxo  = -1;

    for(int i =0;i<N;i++)
        {

        int r = binarysearch(a+i*N,0,N-1);
        if(r!=-1 && r+1>maxo)
            {
            maxo = r+1;
            rownumber = i;
        }
    }

    return rownumber;

}

bool matchingpair(char a, char b)
{
   if(a == '(' && b == ')')
     return 1;
   else if(a == '[' && b == ']')
     return 1;
   else
     return 0;
}

int areBracketsMatched(string s) {

    int i = 0;
    stack<char>s1;
    while(i<s.size())
   {

      if(s[i] == '(' || s[i] == '[')
        s1.push(s[i]);
      if(s[i] == ')' || s[i] == ']')
      {
         if(s1.empty())
           return 0;
         else
          {

             char t = s1.top();
             s1.pop();
             if(!matchingpair(t, s[i]))
                return 0;
         }
      }
      i++;
   }

    if(s1.empty())
        return 1;
    else
        return 0;

}

struct s
{
    int a;
}st;

union test1
{
   int x;
   int y[10];
};
int main()
{
                int mat[4] = { 0,0,1,0};


                test1 t;
                t.x = 12;
                cout<<t.y[0]<<endl;

                st.a = 112;
                int i = 1;
                    printf("%d %d %d\n", i++, i++, i);

//                vector<int> myvector;
//                  for (int i=1; i<=5; i++) myvector.push_back(i);

//                  vector<int>::iterator l = myvector.begin();
//                  vector<int>::iterator h = myvector.end()-1;
//                  while(l<h)
//                  {
//                      if(*l+*h==5)
//                      {
//                          cout<<"found"<<endl;
//                          l++;
//                          h--;
//                      }
//                      else if(*l+*h>5)
//                          h--;
//                      else
//                          l++;
//                  }



                //int a[3][3][2] = {{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18}};
                //cout<<*(*(*(a+0)+2)+1)<<endl<<*(*(*(a+2)+1)+1);
    return 0;
}

