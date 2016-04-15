#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

void printpermutations(char*input, int l, int h)
{
    if(l==h)
    {
        cout<<input<<endl;
    }

    else
    {
        for(int i =l;i<=h;i++)
        {
            swap(input[i],input[l]);
            printpermutations(input,l+1,h);
            swap(input[i],input[l]);
        }
    }
}

int main()
{
    char input[] = "abcd";
    //printpermutations(input,0,3);

    return 0;
}

