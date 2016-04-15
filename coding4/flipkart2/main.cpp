#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define size 10
int arr[50][50];
void  minstrips()
{
    int m,n;
    cin>>m>>n;
    char ch;
    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            cin>>ch;
            if(ch=='.')
                arr[i][j] = 0;
            else if(ch=='b')
                arr[i][j] = -1;
            else if(ch=='r')
                arr[i][j] = 1;
            else
                arr[i][j] = 2;
        }
    }


    int count =0;
    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(arr[i][j]==0)
                continue;
            else if (arr[i][j]==-1)
            {
                int k =i;
                count +=1;
                while(k<m && (arr[k][j]==-1 || arr[k][j]==2))
                {
                    if(arr[k][j]==-1)
                        arr[k][j]= 0;
                    else
                        arr[k][j] = 1;
                    k++;
                }
            }
            else if(arr[i][j]==1)
            {
                int l = j;
                count+=1;
                while(l<n && (arr[i][l]==1 || arr[i][l]==2))
                {
                    if(arr[i][l]==1)
                    {
                        arr[i][l] = 0;
                    }
                    else
                        arr[i][l] = -1;
                    l++;
                }
            }
            else if(arr[i][j]==2)
            {
                count +=2;

                int k =i;
                while(k<m && (arr[k][j])==-1 || arr[k][j]==2)
                {
                    if(arr[k][j]==-1)
                        arr[k][j]= 0;
                    else
                        arr[k][j] = 1;
                    k++;
                }

                int l = j;

                while(l<n && (arr[i][l]==1 || arr[i][l]==2))
                {
                    if(arr[i][l]==1)
                    {
                        arr[i][l] = 0;
                    }
                    else
                        arr[i][l] = -1;
                    l++;
                }

            }

        }
    }

    cout<<"Total strips are "<<count<<endl;



}


int main()
{
    minstrips();
    return 0;
}

