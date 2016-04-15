#include "functions.h"


int noofwaystoreachscore(int *arr, int n, int m)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
        return 0;
    if(n>0 && m==0)
        return 0;

    return noofwaystoreachscore(arr, n,m-1) + noofwaystoreachscore(arr, n-arr[m-1], m-1);

}

char* addgeneralbase(char *str1, char *str2, int base)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1!=len2)
        return NULL;
    char * result = new char [len1 +1];
    int carry = 0;
    for(int i = len1-1; i>=0; i--)
    {
        int x = converttonumber(str1[i]);
        int y = converttonumber(str2[i]);
        int r = carry + x + y;
        if(r>=base)
        {
            r = r-base;
            carry = 1;

        }
        else
            carry = 0;
        result[i+1] = converttochar(r);
    }

    if(carry==1)
    {
        result[0] = '1';
        return result;
    }
    return result+1;
}

char converttochar(int a)
{
    if(a>=0 && a<=9)
        return (a + '0');
    if (a>=10 && a<=35)
        return (a - 10 + 'A');
    assert(0);
}

void powermatrix(int F[2][2], int n)
{
  if(n==0 || n==1)
      return;
  int M[2][2] = {{1,1},{1,0}};

  for(int i = n;i>=1;i=n/2)
  {
      multiply(F,F);
      if(i%2!=0)
      {
          multiply(F,M);
      }
  }
}

void power(int F, int n)
{
  if(n==0 || n==1)
      return;
  int M = F;
  int x =1;
  for(int i = n;i>=1;)
  {
      if(i%2==0)
      {
          F = F*F;
          i = i/2;
      }
      else
      {
        x = x*F;
        i--;
      }

      cout<<i<<endl;
  }

  cout<<"The power is: "<<x<<endl;
}

int converttonumber(char a)
{
    if(a>='0' && a<='9')
        return (a-'0');
    if (a>='A' && a<='Z')
        return (a-'A' + 10);
    assert(0);
}

void multiply(int F[2][2], int M[2][2])
{
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

int getperiod(int n)
{
    int p;
    map<int,int>m;
    map<int,int>::iterator i;
    int r =1;
    p=1;
    while(true)
    {
        r= (r*10)%n;
        i = m.find(r);
        if(i!=m.end())
        {
            return (p-i->second);
        }
        m[r] = p;
        p++;
    }
}

int countnumberoffour(int n, int *arr, int size)
{
    if(n<4)
        return 0;
    int d = log10(n);
    int p = pow(10,d);
    int msb = n/p;
    if(msb<4)
        return msb*arr[d] + countnumberoffour(n%p,arr,size);
    if(msb==4)
        return msb*arr[d] + n%p + 1;
    if(msb>4)
        return (msb-1)*arr[d] + p + countnumberoffour(n%p,arr,size);

}
