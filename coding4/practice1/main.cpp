#include "functions.h"

int getelement(int *arr, int i, int size)
{
    if(i<size)
        return arr[i];
    else
        return INT_MIN;
}

bool isheap(int *arr, int i, int size)
{
    if(i>=size-1)
        return true;

    if(arr[i]>=getelement(arr, 2*i+1,size) && arr[i]>=getelement(arr, 2*i+2,size) &&
            isheap(arr,2*i+1,size) && isheap(arr,2*i+2,size))
        return true;

    return false;
}

bool checkifbinarypalindrome(int n)
{
    int i = 32;
    int j = 1;
    while(i>j)
    {
        if((n&(1<<(i-1))) != (n&(1<<(j-1))))
            return false;
        i--;
        j++;
    }
    return true;
}

int calculatesum(int *arr, int l, int h)
{
    int sum =0;
    for(int i = l;i<=h;i++)
    {
        sum+= arr[i];
    }
    return sum;
}

int twosidesequal(int *arr, int n)
{
    int sum =0;
    for(int i = 0;i<n;i++)
    {
        sum += arr[i];
    }
    int leftsum = 0;
    for(int i =0;i<n;i++)
    {
        leftsum += arr[i];
        sum = sum - arr[i];
        if(sum == leftsum)
            return i+1;
    }
    return -1;
}

int main()
{
//    int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
//    int n = sizeof(arr) / sizeof(int);
//    if(isheap(arr,0,n))
//        cout<<"Yes\n";
//    else
//        cout<<"No\n";
//    Node * root = newnode(4);
//    root->left = newnode(2);
//    root->right = newnode(3);
//    root->left->left = newnode(1);
//    inorder(root);
//    cout<<endl;

//    string a,b;
//    a = "cat";
//    b = "cat";
//    string arr[] = {"cat","bat","bet","bed"};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    minimumstepsfromonestringtoanother(arr,n,a,b);


//    int arr [5];
//    memset(arr,-1,sizeof(arr));
//    for(int i =0;i<5;i++)
//        cout<<arr[i]<< " ";

    //maxflow();

//    string a,b;
//    a = "abcd";
//    b = "ABCD@#$abqw";
//    if(psuedoanagram(a,b))
//        cout<<"Indeed they are\n";
//    else
//        cout<<"No"<<endl;
//    convertdectoheaxa(1000);
//    convertodecimal("3E8");

    binomialcoefficient();

    return 0;
}

