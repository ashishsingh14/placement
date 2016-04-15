#include "functions.h"

BST::BST()
{
    root = NULL;
}

void BST::inserthelper(Node * a, int data)
{

    if(data <= (a->data))
        {
            if(a->left)
                inserthelper(a->left, data);
            else
            {
                a->left= new Node();
                a->left->data = data;
                a->left->left = NULL;
                a->left->right = NULL;
            }

        }
    else
    {
        if(a->right)
            inserthelper(a->right, data);
        else
        {
            a->right= new Node();
            a->right->data = data;
            a->right->left = NULL;
            a->right->right = NULL;
        }
    }

}

void BST::insert(int data)
{
    if(root==NULL)
        {
            Node * n = new Node();
            n->left = NULL;
            n->right = NULL;
            n->data = data;
            root = n;
        }
    else
    inserthelper(root, data);
}

void BST::inorderhelper(Node * node)
{
    if(node==NULL)
        return;

    inorderhelper(node->left);
    cout<<node->data<<" ";
    inorderhelper(node->right);

}

void BST::inorder()
{
    inorderhelper(root);
}

void BST::removekeysoutsidegivenrange()
{
    int l =-10;
    int h = 13;
    if(root)
        removekeysoutsidegivenrangehelper(root,l,h);
}

Node* BST::removekeysoutsidegivenrangehelper(Node * root, int l, int h)
{
    if(root==NULL)
        return NULL;

    root->left = removekeysoutsidegivenrangehelper(root->left, l,h);
    root->right = removekeysoutsidegivenrangehelper(root->right,l,h);

    if(root->data<l)
    {
        delete root;

        if(root->right)
            return root->right;
        root = NULL;

    }
    else if(root->data>h)
    {
        delete root;
        if(root->left)
            return root->left;
        root = NULL;
    }

    return root;
}

bool BST::triplet()
{

    if(root)
    {
        return triplethelper(root);
    }
    return false;
}


bool BST::findsumindll(Node *head, Node *tail, int sum)
{
    while(head!=tail)
    {
        if(head->data + tail->data == sum)
        {
            return true;
        }
        else if((tail->data+head->data) > sum)
        {
            tail = tail->left;
        }
        else
            head = head->right;
    }
    return false;
}

bool BST::triplethelper(Node *root)
{
    if(root==NULL)
        return false;
    Node * head,*tail;
    head=tail=NULL;
    converttodll(root, &head,&tail);
    Node * temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;

    while(head->data<0 && head->right!=tail)
    {
        if(findsumindll(head->right,tail,-1*(head->data)))
            return true;
        else
            head = head->right;
    }
    return false;
}

void BST::isbst()
{
    int min = INT_MIN;
    int max = INT_MAX;
    if(root)
    {
        if(isbsthelper(root,INT_MIN,INT_MAX))
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }

}

bool BST::isbsthelper(Node *root, int min, int max)
{
    if(root==NULL)
        return true;
    if(root->data<min)
        return false;
    if(root->data>max)
        return false;
    return isbsthelper(root->left,min,root->data) && isbsthelper(root->right,root->data,max);

}
Node* BST::newnode(int data)
{
    Node * n = new Node();
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    return n;
}

void BST::mergetwobstwithstack()
{
    Node * root2 = newnode(44);
    root2->left = newnode(11);
    root2->right = newnode(50);

    mergetwobststackhelper(root, root2);
}

void BST::mergetwobststackhelper(Node *root1, Node *root2)
{
    stack<Node *>s1,s2;
    Node*current1 = root1;
    Node * current2 = root2;


    while(!s1.empty() || !s2.empty()|| current1|| current2)
    {
        if(current1)
        {
            s1.push(current1);
            current1 = current1->left;
        }
        if(current2)
        {
            s2.push(current2);
            current2 = current2->left;
        }

        if(current1==NULL && current2==NULL)
        {
            if(!s1.empty() && !s2.empty())
            {
                Node* a = s1.top();
                Node* b = s2.top();
                s1.pop();
                s2.pop();
                if(a->data<=b->data)
                {
                    cout<<" "<<a->data<<" ";
                    current1 = a->right;
                    s2.push(b);
                }
                else
                {
                    cout<<" "<<b->data<<" ";
                    current2 = b->right;
                    s1.push(a);
                }


            }
            else
            {
                if(s1.empty())
                {
                    while(!s2.empty())
                    {
                        Node* a = s2.top();
                        inorderhelper(a);

                        s2.pop();
                    }
                    return;
                }
                else if(s2.empty())
                {
                    while(!s1.empty())
                    {
                        Node*b = s1.top();
                        inorderhelper(b);
                        s1.pop();
                    }
                    return;
                }
            }
        }

    }

}

void BST::printdoublelinkedlist(Node *head)
{
    if(head==NULL)
        return;
    Node*temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}
void BST::converttodll(Node *root, Node ** head, Node **tail)
{
    if(root==NULL)
        return;
    converttodll(root->left, head,tail);
    if(*tail==NULL)
    {
        *head = root;
    }
    else
    {
        (*tail)->right = root;
        root->left = (*tail);
    }
    *tail = root;
    converttodll(root->right, head,tail);
}

Node* BST::mergetwodll(Node *head1, Node *head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    Node*result = NULL;
    if(head1->data<=head2->data)
    {
        result = head1;
        result->right = mergetwodll(head1->right,head2);
        result->right->left = result;
    }
    else
    {
        result = head2;
        result->right = mergetwodll(head1,head2->right);
        result->right->left = result;
    }
    return result;
}

void BST::mergetwobstusingdll()
{
    Node*head1,*head2,*tail1,*tail2;
    head1=tail1=NULL;
    head2=tail2=NULL;
    Node * root2 = newnode(44);
    root2->left = newnode(11);
    root2->right = newnode(50);
    converttodll(root,&head1,&tail1);
    converttodll(root2,&head2,&tail2);
    cout<<endl;
    printdoublelinkedlist(head1);
    cout<<endl;
    printdoublelinkedlist(head2);
    Node * head = mergetwodll(head1,head2);
    cout<<endl;
    printdoublelinkedlist(head);


}

void BST::sortedlinkedlisttobst()
{
    Node * head;
    head = newnode(10);
    head->right = newnode(11);
    head->right->right = newnode(12);
    head->right->right->right = newnode(13);
    head->right->right->right->right = newnode(14);
    head->right->right->right->right->right = newnode(15);

    Node*root;
    int size = 6;
    root = sortedlinkedlisttobsthelper(&head, 6);
    inorderhelper(root);
}

Node* BST::sortedlinkedlisttobsthelper(Node **head, int n)
{
    if(n<=0 || head==NULL)
        return NULL;
    Node*left = sortedlinkedlisttobsthelper(head, n/2);
    Node*root = newnode((*head)->data);
    root->left = left;
    *head = (*head)->right;

    root->right = sortedlinkedlisttobsthelper(head,n-n/2-1);

    return root;
}

int search(int *in, int el, int l, int h)
{
    for(int i =l;i<=h;i++)
    {
        if(in[i]==el)
            return i;
    }
    return -1;
}

int* constructlevel(int *in, int *level, int l, int h,int size)
{
    int * le = new int[h-l+1];
    int j = 0;
    for(int i =0;i<size;i++)
    {
        if(search(in,level[i],l,h)!=-1)
        {
            le[j] = level[i];
            j++;
        }
    }
    return le;
}

Node * BST::treepreandlevelhelper(int *in, int * level, int l, int h, int size)
{
    if(l>h)
        return NULL;
    Node * root = newnode(level[0]);
    if(l==h)
        return root;
    int index = search(in,level[0],l,h);

    int * le = constructlevel(in, level, l,index-1,size);
    int * ri = constructlevel(in, level, index+1 ,h,size);


    root->left = treepreandlevelhelper(in, le, l, index-1,size);
    root->right = treepreandlevelhelper(in, ri,index+1, h, size);
    delete le;
    delete ri;
    return root;


}

void BST::treepreandlevel()
{
    int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);

    Node * root = treepreandlevelhelper(in, level, 0,n-1,n);
    inorderhelper(root);
}

void BST::constructfrompostorderhelper(Node *root)
{
    stack<Node*>s;
    Node * current  = root;
    do
    {
        if(current)
        {
            if(current->right)
                s.push(current->right);
            s.push(current);
            current = current->left;
        }
        else
        {
            if(!s.empty())
            {
                current = s.top();
                s.pop();
            }


            if(!s.empty() && current->right && current->right == s.top())
            {
                s.pop();
                s.push(current);
                current = current->right;
            }
            else
            {
                cout<<current->data<<" ";
                current = NULL;
            }
        }


    }while(!s.empty());
}

nodel* newnodel(int data)
{
    nodel * n = new nodel();
    n->data = data;
    n->next = NULL;
}

void BST::constructfrompostorder()
{
    if(root)
        constructfrompostorderhelper(root);
}

void BST::constructcompletefromlinkedlist()
{
    nodel * head = newnodel(10);
    head->next = newnodel(12);
    head->next->next = newnodel(14);
    head->next->next->next = newnodel(16);
    head->next->next->next->next = newnodel(18);
    head->next->next->next->next->next = newnodel(20);
    queue<Node*> q;
    Node * root = newnode(head->data);
    nodel * temp = head;
    q.push(root);
    temp = temp->next;
    while(temp)
    {
        Node * p = q.front();
        if(p->left==NULL)
        {
            p->left = newnode(temp->data);
            temp = temp->next;
            q.push(p->left);
        }
        if(p->right==NULL)
        {
            if(temp)
            {
                p->right = newnode(temp->data);
                temp = temp->next;
                q.push(p->right);
            }
        }
        q.pop();
    }

    inorderhelper(root);

}

bool BST::storeancestorshelper(Node * root, int key,vector<int>&v, int i)
{
    if(root==NULL)
        return false;
    if(root->data==key)
    {
        return true;
    }
    if(storeancestorshelper(root->left, key, v,i+1) || storeancestorshelper(root->right, key, v,i+1))
    {
       v.push_back(root->data);
        return true;
    }
    return false;
}

void BST::storeancestors()
{
    int key = 7;
    vector<int>v;
    if(root)
        storeancestorshelper(root,key,v,0);

    vector<int>::iterator i ;
    for(i = v.begin();i!=v.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}

void BST::findlcainbst(int n1, int n2)
{
    Node * current = root;
    while(true)
    {
        if(current->data > n1 && current->data>n2)
            current = current->left;
        else if(current->data<n1 && current->data<n2)
            current = current->right;
        else
            break;

    }

    cout<<"The lowest common lca is "<<current->data<<endl;
}

void BST::findfloor(int key)
{
    if(root)
        cout<<"The floor is "<<findfloorhelper(root, key)<<endl;
}

int BST::findfloorhelper(Node *root, int key)
{
    if(root==NULL)
        return INT_MAX;
    if(root->data==key)
    {
        return root->data;
    }
    if(root->data>key)
        return findfloorhelper(root->left,key);
    int floor = findfloorhelper(root->right, key);
    return (floor<=key)?floor:root->data;

}
void BST::findpreandsuccesorhelper(Node *root, int key, int &succ, int &pred)
{
    if(root==NULL)
        return ;
    if(root->data==key)
    {
        if(root->left)
        {
            Node * left = root->left;
            while(left->right)
                left = left->right;
            pred = left->data;
        }
        if(root->right)
        {
            Node * right = root->right;
            while(right->left)
                right = right->left;
            succ = right->data;
        }
    return;
    }
    if(root->data>key)
    {
        succ = root->data;
        findpreandsuccesorhelper(root->left,key,succ,pred);
    }
    if(root->data<key)
    {
        pred = root->data;
        findpreandsuccesorhelper(root->right,key,succ,pred);
    }
}

void BST::findpreandsuccesor(int key)
{
    int pred,succ;
    pred = succ = 0;
    if(root)
        findpreandsuccesorhelper(root,key, succ,pred);

    cout<<"Predecessor is "<<pred<<" Sucessor is "<<succ<<endl;
}
