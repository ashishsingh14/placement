#include <iostream>

using namespace std;

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

  cout<<x<<" "<<y<<endl;
  cout<<z<<" "<<w<<endl;
}

int power(int n)
{
    int a[2][2]={{1,0},{0,1}};
    int F[2][2] = {{1,1},{1,0}};
  for(int i = n;i>=1;)
  {
      if(i%2==0)
      {
          multiply(F,F);
          i = i/2;
      }
      else
      {
          multiply(a,F);
          i--;
      }
  }
  return a[0][0];
}

int main()
{
    cout<<power(2)<<endl<<endl;
    return 0;
}

