#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node * next;
};

node * newnode(int data)
{
    node * n = new node();
    n->data = data;
    n->next = NULL;
    return n;
}

node * reverse(node * head1)
{
    if(head1==NULL)
        return NULL;
    node * current = head1;
    node * prev, *next;
    prev = NULL;
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void addlinkedlist(node * head1, node * head2)
{

    if(head1==NULL)
        return ;
    if(head2==NULL)
        return;

    head1 = reverse(head1);
    head2 = reverse(head2);

    node * cur1, *cur2;
    cur1 = head1;
    cur2 = head2;
    int carry = 0;
    int sum ;
    node * head = NULL;
    node * temp;
    while(cur1 || cur2)
    {

        sum = carry + (cur1?cur1->data:0) + (cur2?cur2->data:0);
        carry = sum/10;
        temp = newnode(sum%10);
        if(head==NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }


    if(carry>0)
    {
        temp = newnode(carry);
        temp->next = head;
        head = temp;
    }

    node * p = head;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }

    cout<<endl;

}

void passtwolinkedlist()
{
    node * head1 = newnode(2);
    head1->next = newnode(2);
    head1->next->next = newnode(3);
    head1->next->next->next = newnode(4);

    node * head2 = newnode(9);
    head2->next = newnode(3);
    head2->next->next = newnode(8);
    head2->next->next->next = newnode(9);

    addlinkedlist(head1, head2);


}

struct ele
{
    int x,y;
};

void rottenoranges()
{
    int arr[3][5] = { {1, 1, 0, 2, 1},
                         {1, 0, 0, 2, 1},
                         {1, 1, 1, 2, 1}};

    queue<ele>q;
    ele temp;


    for(int i =0;i<3;i++)
    {
        for(int j =0;j<5;j++)
        {
            if(arr[i][j]==2)
            {
                temp.x = i;
                temp.y = j;
                q.push(temp);
            }
        }
    }
    int row[] = {1,-1,0,0};
    int col[] = {0,0,1,-1};

    int ans =0;
    temp.x = -1;
    temp.y = -1;
    q.push(temp);
    ele cur;
    int count = 0;
    while(!q.empty())
    {
        bool flag = false;
        while((q.front().x)!=-1 && (q.front().y)!=-1)
        {
           temp = q.front();
           for(int i =0;i<4;i++)
           {
               int nextx = temp.x + row[i];
               int nexty = temp.y + col[i];

               if(nextx>=0&&nextx<3 && nexty>=0 && nexty<5 && arr[nextx][nexty]==1)
               {
                   if(!flag) ans++;
                   flag = true;
                   arr[nextx][nexty] = 2;
                   cur.x = nextx;
                   cur.y = nexty;
                   q.push(cur);
               }
           }

           q.pop();

        }
        count++;
        q.pop();
        if(!q.empty())
        {
            temp.x = -1;
            temp.y = -1;
            q.push(temp);
        }
    }


    cout<<"Total time is "<<ans<<" "<<count<<endl;

}

struct Node
{
    Node * left, *right;
    int data;
};

int p[20];
int l;


Node* treenode(int data)
{
    Node * n = new Node();
    n->left = NULL;
    n->right = NULL;
    n->data  = data;
    return n;
}

void printnodesdown(Node * root, int k)
{
    if(root==NULL || k<0)
    {
        return;
    }
    if(k==0)
    {
        p[l++] = root->data;
        return;
    }
    printnodesdown(root->left, k-1);
    printnodesdown(root->right, k-1);

}

int nodesatkdistance(Node * root, Node * target, int k)
{

    if(root==NULL)
        return -1;
    if(root==target)
    {
        printnodesdown(root, k);
        return 0;
    }

    int dl = nodesatkdistance(root->left, target, k);
    if(dl!=-1)
    {
        if(dl+1==k)
            p[l++] = root->data;
        else
            printnodesdown(root->right, k-dl-2);
        return 1+dl;

    }
    int dr = nodesatkdistance(root->right, target, k);
    if(dr!=-1)
    {
        if(dr+1==k)
            p[l++] = root->data;
        else
            printnodesdown(root->left, k-dr-2);
        return 1+dr;

    }

    return -1;

}

void helperfork()
{
    Node * root = treenode(20);
    root->left = treenode(8);
    root->right = treenode(22);
    root->left->left = treenode(4);
    root->left->right = treenode(12);
    root->left->right->left = treenode(10);
    root->left->right->right = treenode(14);
    Node * target = root->left->right;
    nodesatkdistance(root, target, 2);

    for(int i =0;i<l;i++)
        cout<<p[i]<<" ";
    cout<<endl;
}
int findalloccurances(string s, string pattern)
{
   if(s.size()==0)
       return 0;
   int count = 0;
   for(size_t i = s.find(pattern);i!=-1 ;i = s.find(pattern, i+pattern.size()))
   {
       count++;
   }
   return count;
}

void push(node**s, int data)
{
    node * n = newnode(data);
    n->data = data;
    n->next = *s;
    *s = n;
}


int pop(node**s)
{
    if(*s==NULL)
        return 0;
    else
    {
        node * temp = *s;
        *s = (*s)->next;
        int res =  temp->data;
        delete temp;
        return res;

    }
}

bool matching(char a, char b)
{
    if(a=='(' && b==')')
        return 1;
    else if(a=='[' && b==']')
        return 1;
    else if (a=='{' && b=='}')
        return 1;
    return 0;
}

bool checkparenthesis(char * st)
{
    node *s = NULL;

    for(int i =0;i<strlen(st);i++)
    {
        if((st[i]=='(') || (st[i]=='[') || (st[i]=='{'))
            push(&s, st[i]);
        else
        {
            if(s==NULL)
                return 0;
            else if(!matching(pop(&s),st[i]))
                return 0;
        }
    }

    if(s==NULL)
        return 1;
    else
        return 0;

}




int main(){

    //cout<<findalloccurances("the three truths", "th");

    rottenoranges();
    return 0;

}
