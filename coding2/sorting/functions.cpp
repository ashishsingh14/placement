#include "functions.h"

void quicksort(vector<int>&arr, int p, int h)
{
    if(p<h)
    {
        int q = partition(arr,p,h);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,h);
    }
}

int partition(vector<int>&arr, int l, int h)
{
   int i = l-1;
   int x = arr.at(h);
   for(int j = l;j<=h-1;j++)
   {
       if(arr.at(j)<=x)
       {
           i = i+1;
           swap(arr[i], arr[j]);

       }
   }
   swap(arr[i+1],arr[h]);
   return i+1;
}

void countsort(int *arr, int size)
{
    int count[range+1];
    memset(count,0,sizeof(count));
    for(int i =0;i<size;i++)
        count[arr[i]]++;
    for(int i =1;i<size;i++)
        count[i] += count[i-1];
    int output[size];

    for(int i = size-1;i>=0;i--)
    {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    for(int i =0;i<size;i++)
        arr[i] = output[i];
}

void printarray(int *arr, int size)
{
    for(int i =0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void countsortradix(int *arr, int exp, int size)
{
    int count[10];
    memset(count,0,sizeof(count));
    for(int i =0;i<size;i++)
        count[(arr[i]/exp)%10]++;
    for(int i =1;i<size;i++)
        count[i] += count[i-1];
    int output[size];

    for(int i = size-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i =0;i<size;i++)
        arr[i] = output[i];
}

void radixsort(int *arr, int size)
{
    int largest = INT_MIN;
    for(int i =0;i<size;i++)
        largest = max(largest,arr[i]);

    for(int exp = 1;largest/exp>0;exp = 10*exp)
    {
        countsortradix(arr,exp,size);
    }

}


