#include "functions.h"

void calling1()
{
    int arr[10] = {2,2,2,1,1,3,4,5,0,0};
    radixsort(arr,10);
    printarray(arr,10);
}

void calling2()
{
    vector<int>arr;
    for(int i =0;i<5;i++)
        arr.push_back(i+1);
    for(int i =0;i<7;i++)
        arr.push_back(i+1);

    quicksort(arr,0,arr.size()-1);
    for(vector<int>::iterator i = arr.begin(); i!=arr.end();i++)
    {
        cout<<*i<<" ";
    }
//    arr.erase(arr.end()-1);
//    cout<<endl;
//    for(vector<int>::iterator i = arr.begin(); i!=arr.end();i++)
//    {
//        cout<<*i<<" ";
//    }
    cout<<endl;
}

int main()
{
    //calling2();
    list<int> l;
    l.push_back(2);
    l.push_back(5);

    return 0;
}

