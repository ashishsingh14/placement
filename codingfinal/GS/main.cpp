#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void runLengthEncoded()
{
    string s = "wwaadexxxxxx"; //
    int l = s.size();
    string enc = "";
    int count = 1;
    enc = enc + s[0];
    for(int i =1;i<l;i++)
    {

        if(s[i]!=s[i-1])
        {
            if(count!=1)
            {
                enc = enc + to_string(count);
                enc = enc + s[i];

            }
            else
                enc = enc + s[i];
            count = 1;
        }

        else
            count++;

    }
    enc += to_string(count);

    cout<<enc<<endl;
}

unsigned uglyNumber(unsigned n)
{
    unsigned ugly[n];
    unsigned i2, i3, i5;
    i2 = i3 = i5 = 0;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_ugly_no = 1;
    ugly[0] = 1;
    for(int i =1;i<n;i++)
    {
        next_ugly_no = min(next_multiple_of_2,min(next_multiple_of_3,next_multiple_of_5));
        ugly[i] = next_ugly_no;
        if(next_ugly_no==next_multiple_of_2)
        {
            i2 = i2 +1;
            next_multiple_of_2 = 2*ugly[i2];
        }
        if(next_ugly_no==next_multiple_of_3)
        {
            i3 = i3 + 1;
            next_multiple_of_3 = 3*ugly[i3];
        }
        if(next_ugly_no==next_multiple_of_5)
        {
            i5 = i5 +1;
            next_multiple_of_5 = 5*ugly[i5];
        }
    }
    return ugly[n-1];
}

vector<int> calculate(int i, int j)
{
    vector<int>v;
    if(i)
    {
        vector<int>temp = calculate(i-1,j);
        vector<int>::iterator it;
        if(temp.size())
        {
            for(it = temp.begin();it!=temp.end();it++)
            {
                cout<<*it<<" ";
                v.push_back(10*(*it)+4);
            }
        }

    }
    if(j)
    {
        vector<int>temp = calculate(i,j-1);
        vector<int>::iterator it;
        if(temp.size())
        {
            for(it = temp.begin();it!=temp.end();it++)
            {
                cout<<*it<<" ";
                v.push_back(10*(*it)+5);
            }
        }
    }

    if(v.empty())
    {
        v.push_back(0);
    }
    return v;
}

void numberFormation(int x, int y, int z)
{
    long long res = 0;
//    for (int i = 0; i <= x; ++i)
//        for (int j = 0; j <= y; ++j)
//            for (int k = 0; k <= z; ++k)
//            {
    vector<int>temp = calculate(1,2);
    vector<int>::iterator it;
    long long sum = 0;
    if(temp.size())
    {
        for(it = temp.begin();it!=temp.end();it++)
        {
            cout<<*it<<" ";
            sum += *it;
        }
        cout<<"sum "<<sum<<endl;
    }
            //}
}
int ans = 0;
int merge(int arr[], int l, int m, int h)
{
    int n1,n2;
    n1 = m-l+1;
    n2 = h-m;
    vector<int>left(n1,0);
    vector<int>right(n2,0);
    for(int i =0;i<n1;i++)
    {
       left[i] = arr[l+i];
    }
    for(int j =0;j<n2;j++)
    {
        right[j] = arr[m+1+j];
    }

    int k;
    int i=0,j=0;
    for(k=l;k<=h;k++)
    {
        if((i<n1 && left[i]<right[j]) || j>=n2)
        {
            arr[k] = left[i++];

        }
        else
        {
            arr[k] = right[j++];
            ans += n1-i;
        }
    }
}


void mergeSort(int arr[], int l,int h)
{
    int mid;
    if(l<h)
    {
        mid = (l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

void countInversions()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr, 0,n-1);
    cout<<"Total inversions are "<<ans<<endl;

}
void generatenextPalindromeutil(int num [], int n)
{
    int mid = n/2;
    int i = mid-1;
    int j = (n&1)?mid+1:mid;
    int leftsmaller = false;
    while(i>= 0 && num[i]==num[j])
    {
        i--;
        j++;
    }

    if(i<0 || num[i] < num[j])
        leftsmaller = true;
    while(i>=0)
    {
        num[j++] = num[i--];

    }

    if(leftsmaller == true)
    {
        int carry = 1;
        i = mid - 1;
        if(n%2==1)
        {
            num[mid]+= carry;
            carry = num[mid]/10;
            num[mid] = num[mid]%10;
            j = mid + 1;
        }
        else
            j = mid;
        while(i>=0)
        {
            num[i] += carry;
            carry = num[i]/10;
            num[i] = num[i]%10;
            num[j++] = num[i--];
        }
    }

}

void generatenextPalindrome(int num[], int n)
{
    int i;
    int count9 = 0;
    for(i = 0; i < n; ++i)
    {
        if(num[i]==9)
            count9++;
    }
    if(count9==n)
    {
        cout<<"1";
        for(int j = 1;j<n;j++)
            cout<<"0";
        cout<<"1\n";
    }
    else
    {
        generatenextPalindromeutil(num, n);
        for(i = 0; i < n; ++i)
            cout<<num[i]<<" ";
        cout<<endl;
    }
}

struct TreeNode
{
    TreeNode * left;
    TreeNode * right;
    int data;
};

typedef struct TreeNode TreeNode;

TreeNode* newNode(int data)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int sum(TreeNode * root)
{
    if(root==NULL)
        return 0;
    else
        return sum(root->left) + root->data + sum(root->right);
}

bool checkifSumTree(TreeNode * root)
{
    if(root==NULL || (!root->left && !root->right))
        return true;
    if(checkifSumTree(root->right) && checkifSumTree(root->left) && (root->data ==sum(root->left)+sum(root->right)))
        return true;
    return false;
}

void convertSumTree()
{

}

int main()
{
    //runLengthEncoded();
    //cout<<uglyNumber(11)<<endl;
    //numberFormation(1,1,1);
//    int num [] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};
//    int n = sizeof(num)/sizeof(num[0]);
//    generatenextPalindrome(num,n);
    //countInversions();

    TreeNode *root  = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
    if(checkifSumTree(root))
        printf("The given tree is a SumTree ");
    else
        printf("The given tree is not a SumTree ");


    return 0;
}

