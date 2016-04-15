#include "functions.h"

void calling1()
{
    int arr [3] = {1,2,3};
    int c = noofwaystoreachscore(arr, 3, 3);
    cout<<"The total ways are "<<c<<endl;
}

void calling2()
{
    int base = 14;
    char str1[10] = "12A";
    char str2[10] = "CD3";
    char *s = addgeneralbase(str1, str2, base);
    cout<<"The result is: "<<s<<endl;
}

void calling3()
{
    cout<<getperiod(7)<<endl;
}

void calling4(int n)
{
   int d = log10(n);
   int * arr = new int[d+1];
   arr[0] = 0;
   arr[1] = 1;
   for(int i =2;i<=d;i++)
   {
       arr[i] = 9*arr[d-1] + ceil(pow(10,i-1));
   }
   cout<<"Total digits that contain 4 are "<<countnumberoffour(n,arr,d+1)<<endl;
}

int main()
{
    int n = 100;
    calling4(n);
    return 0;
}

