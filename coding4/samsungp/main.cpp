#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std;

void kadanewithindex(int *arr, int size)
{
    int currentsum, maxsofar;

    currentsum = maxsofar = 0;
    int start,end;
    start = 0;
    for(int i =0;i<size;i++)
    {
        currentsum += arr[i];
        if(currentsum>maxsofar)
        {
            maxsofar = currentsum;
            end = i;
        }
        if(currentsum<0)
        {
            currentsum = 0;
            start = i+1;
        }
    }

    cout<<"the length is "<<end-start+1<<" with sum "<<maxsofar<<endl;
}

void modifiedkadane(int *arr, int size)
{
    int currentsum, maxsofar;

    currentsum = maxsofar = 0;
    int start,end;
    start = 0;
    map<int,int>m;
    for(int i =0;i<size;)
    {
        if(m[arr[i]]==1)
        {
            currentsum = arr[i];
            m.clear();
            m[arr[i]] = 1;
            start = i;
            continue;
        }
        if(m[arr[i]]==0)
        {
            currentsum += arr[i];
            m[arr[i]] = 1;
            i++;
        }

        if(currentsum>maxsofar)
        {
            maxsofar = currentsum;
            end = i;
        }
        if(currentsum<0)
        {
            currentsum = 0;
            start = i+1;
        }
    }
    cout<<"the length is "<<end-start+1<<" with sum "<<maxsofar<<endl;

    for(int i = start;i<=end;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}


struct node
{
    int data;
    node *next;
};

class abc
{
    struct node
    {
        int a;
        struct node *n;
    };
};

node *newnode(int data)
{
    node * n = new node();
    n->next = NULL;
    n->data = data;
    return n;
}

void detectandremoveloop(node *head)
{
    node * slow = head;
    node * fast = head;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            cout<<"loop found\n";
            break;
        }

    }
}

void nextgreaterelement()
{
    stack<int>s;
    int arr[] = {11, 13, 21, 3};
    s.push(arr[0]);
    for(int i =1;i<4;i++)
    {
        if(!s.empty())
        {
            while(!s.empty() && arr[i]>s.top())
            {
                cout<<s.top()<<" "<<arr[i]<<endl;
                s.pop();
            }

        }
        s.push(arr[i]);
    }
    while(!s.empty())
    {
        cout<<s.top()<<"-1"<<endl;
        s.pop();
    }
}

void function1()
{
    int num = 123;
    string a;
    stringstream convert;
    convert<<num;
    a = convert.str();
    cout<<a<<endl;
    int res;
    istringstream con(a);
    if(!(con>>res))
        res = 0;
    cout<<res<<endl;

}

int main()
{


//    char* str="hello\0world\0";
//    printf("%s",str);
//    str=str+5;
//    printf("%s",str);
//    cout<<"as\n";
//    str=str+7;
//    printf("%s",str);

//    char* ptr[]={"samsung","electronics","india"};
//    char**ptr1;
//    ptr1 = ptr;
//    cout<<*ptr1++<<endl;
//    cout<<*ptr1<<endl;


//    int num[]={1,4,8,12,16};
//    int *p=num;
//    int *q=num+2;
//    int i=*p++;
    //p++;
    //printf("%d %d %d\n",i,*p,*q );

//    int arr[]= {-1, 3, -5, 4, 6, -1, 2, -7, 13, -3} ;
//    int size = sizeof(arr)/sizeof(arr[0]);
//    kadanewithindex(arr,size);
//    int arr1[] = {4, 2, 3, 4, 5, 2,4,5,9,10};
//    //modifiedkadane(arr1,10);

//    char st[] = "hello";
//    st[6] = 'n';
//    cout<<st<<endl;


//    int b = 23;
//    int *p = &b;
//    cout<<*p++<<endl;
    unsigned char i = 0x80;
    cout<<(i<<1)<<endl;
    //cout<<*p<<endl;
   // int b = 2;
    //~b, -b;
//    cout<<b<<endl;
//    int a;
//    if(a=0)
//        cout<<"asdfd";
//    else
//        cout<<"ere\n";
//    char str[] = "ashi\0sh";
//    cout<<strlen(str+4)<<endl;

//    abc t;
//    cout<<sizeof(t)<<""<<sizeof(abc)<<endl;
//    cout<<sizeof('a')<<endl;

//    char a[] = "hello";
//    char b[] = "hello";
//    if(strcmp(a,b))
//    printf("string is same");
//    else
//    printf("not same");
    nextgreaterelement();
    return 0;
}


