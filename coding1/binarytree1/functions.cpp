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
            n->nextright = NULL;
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

void BST::verticald()
{
    int hd = 0;
    map<int, int> mymap;
    if(root)
        verticaldhelper(root, hd, mymap);

    for (map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
       cout << it->first << " => " << it->second << '\n';
}


void BST::verticaldhelper(Node *root, int hd, map<int,int>&mymap)
{

    if(root==NULL)
        return;
    else
    {
        verticaldhelper(root->left,hd-1, mymap);
        mymap[hd]+=root->data;
        cout<<"data is "<<hd<<" "<<root->data<<endl;
        verticaldhelper(root->right,hd+1,mymap);
    }
}


void BST::connectnodessamelevel()
{
    if(root)
        connectnodessamelevelhelper(root);
}


void BST::connectnodessamelevelhelper(Node * root)
{
    queue<Node*>n;
    queue<int>l;

    n.push(root);
    int level = 1;
    l.push(level);

    while(!n.empty())
    {

        Node * t = n.front();
        n.pop();
        int getl = l.front();
        l.pop();
        if(l.empty())
        {
            t->nextright = NULL;
        }
        else
        {
            Node * next = n.front();
            if(l.front()==getl)
                t->nextright = next;
            else
                t->nextright = NULL;

        }
        getl++;
        if(t->left)
        {
            n.push(t->left);
            l.push(getl);
        }
        if(t->right)
        {
            n.push(t->right);
            l.push(getl);
        }

    }

}



void BST::printsamelevel()
{
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->left->nextright->data<<endl;
    cout<<root->left->left->nextright->data<<endl;
}


void BST::doubletree()
{
    Node * head;
    if(root)
        doubletree(root, &head);


    Node * temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}

void BST::doubletree(Node * root, Node **head)
{
    static Node * prev = NULL;
    if(root==NULL)
        return;
    doubletree(root->left, head);
    if(prev==NULL)
    {
        *head = root;
        prev = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
        prev = root;
    }
    doubletree(root->right, head);
}

void BST::findlca(int a, int b)
{
    int v1,v2,dist;
    v1 = v2 = -1;
    Node * lca;
    if(root)
    {
        lca = findlcahelper(root,a,b,v1,v2,0,dist);
    }

    if(v1!=-1 && v2!=-1)
    {
        cout<<"Ancestor is "<<lca->data<<endl;
        cout<<"The distance is "<<dist<<endl;
    }
    else
    {
        if( v1!=-1 && findhelper(root,b))
        {
            cout<<"Ancestor is "<<lca->data<<endl;
            dist = finddistancefromroot(lca,b,0);
            cout<<"The distance is "<<dist<<endl;
        }
        if(v2!=-1 && findhelper(root,a))
        {
            cout<<"Ancestor is "<<lca->data<<endl;
            dist = finddistancefromroot(lca,a,0);
            cout<<"The distance is "<<dist<<endl;
        }
    }
}

Node* BST::findlcahelper(Node *root, int a, int b, int& v1, int& v2, int level, int &dist)
{
    if(root==NULL)
        return NULL;
    if(root->data == a)
    {
        v1 = level;
        return root;
    }
    if(root->data == b)
    {
        v2 = level;
        return root;
    }
    Node * l = findlcahelper(root->left,a,b,v1,v2,level+1,dist);
    Node * r = findlcahelper(root->right,a,b,v1,v2,level+1,dist);

    if(l&&r)
    {
        dist = v1+v2-2*level;
        return root;
    }

     return (l!=NULL)?l:r;

}


void BST::findnode(int a)
{
    if(root)
        findhelper(root,a);
    else
        cout<<"Node is not there\n";
}


bool BST::findhelper(Node *root, int a)
{
    if(root==NULL)
        return false;
    if(root->data == a)
        return true;
    else
        return findhelper(root->left,a)||findhelper(root->right,a);

    return false;
}


int BST::finddistancefromroot(Node *root, int a, int level)
{
    if(root==NULL)
        return -1;
    if(root->data==a)
        return level;

    return finddistancefromroot(root->left,a,level+1) || finddistancefromroot(root->right,a,level+1);

}


void BST::sumfromrootleave()
{
    int sum = 0;
    int d = 0;
    if(root)
    {
        sumfromrootleave(root,sum,d);
    }

    cout<<"Final sum is "<<sum<<endl;
}

void BST::sumfromrootleave(Node *root, int &sum, int d)
{
    if(root==NULL)
        return;
    d = d * 10 + root->data;
    if(root->left==NULL && root->right==NULL)
    {
        sum+=d;
    }
    sumfromrootleave(root->left,sum,d);
    sumfromrootleave(root->right,sum,d);

}


//void BST::printancestorsworecursion(Node *root,int a)
//{
//    Node * r = root;
//    Node *temp;
//    stack<Node*>s;
//    while(true)
//    {
//        while(root && r->data!=a)
//        {
//            s.push(r);
//            r = r->left;
//        }

//        if(root && root->data==a)
//        {
//            cout<<"Found data"<<endl;
//            break;
//        }

//        if(root==NULL)
//        root = s.top();

//        if(root->right==NULL)
//        {
//            s.pop();
//            temp = s.top();
//            while(!s.empty() && temp->right==root)
//                s.pop();
//        }
//    }

//    while(!s.empty())
//    {
//        temp = s.top();
//        s.pop();
//        cout<<temp->data<<" ";
//    }
//    cout<<endl;


//}

void BST::printdistanceatk(int a, int b)
{
    if(root)
        printdistanceatkhelper(root,b,a);
}

void BST::printdownfromnode(Node * root, int a)
{
    if(root==NULL || a<0)
        return;
    if(a==0)
    {
        cout<<root->data<<" ";
        return ;
    }
    printdownfromnode(root->left,a-1);
    printdownfromnode(root->right,a-1);
}

int BST::printdistanceatkhelper(Node *root, int b, int a)
{
    if(root==NULL)
        return -1;
    if(root->data==b)
    {
        printdownfromnode(root,a);
        return 0;
    }

    int dl = printdistanceatkhelper(root->left,b,a);
    if(dl!=-1)
    {
        if(dl+1==a)
        {
            cout<<root->data<<" "<<endl;
        }
        else
            printdownfromnode(root->right,a-dl-2);
        return 1+dl;
    }

    int dr = printdistanceatkhelper(root->right,b,a);
    if(dr!=-1)
    {
        if(dr+1==a)
        {
            cout<<root->data<<" "<<endl;
        }
        else
            printdownfromnode(root->left,a-dr-2);
        return 1+dr;
    }
    return -1;
}

void BST::printvertivcal()
{
    int minr, maxr, hd;
    hd = 0;
    minr = INT_MAX;
    maxr = INT_MIN;
    if(root)
        calculateverticalhelper(root,minr,maxr,hd);

    for(int i = minr;i<=maxr;i++)
    {
        printvertivcalhelper(root,i);
        cout<<endl;
    }
}


void BST::printvertivcalhelper(Node * root, int i)
{
    if(root==NULL)
        return;
    if(i==0)
    {
        cout<<"Data is "<<root->data<<" ";
    }

    printvertivcalhelper(root->left,i+1);
    printvertivcalhelper(root->right, i-1);

}

void BST::calculateverticalhelper(Node * root, int &minr, int& maxr, int hd)
{
    if(root==NULL)
        return;
    maxr = max(hd,maxr);
    minr = min(hd,minr);
    calculateverticalhelper(root->left,minr,maxr,hd-1);
    calculateverticalhelper(root->right,minr,maxr,hd+1);

}

void BST::maxpathtwoleaves()
{
    int ans = INT_MIN;
    if(root)
    {
        maxpathtwoleaveshelper(root, ans);
    }
}

int BST::maxpathtwoleaveshelper(Node * root,int&ans)
{
    if(root==NULL)
        return 0;
    int lsum = maxpathtwoleaveshelper(root->left, ans);
    int rsum = maxpathtwoleaveshelper(root->right, ans);

    cout<<"data is "<<lsum + rsum + root->data<<endl;
    if((lsum + rsum + root->data)>ans)
    {
        ans = lsum + rsum + root->data;
    }

    return max(lsum,rsum) + root->data;
}

void BST::reversealternatelevels()
{
    int nodes[50];
    int index = 0;
    if(root)
        insertelementsintoarray(root, nodes, index, 0);
    int i =0;
    int j = index-1;
    while(i<j)
    {
        int temp = nodes[i];
        nodes[i] = nodes[j];
        nodes[j] = temp;
        i++;
        j--;
    }
    index = 0;
    reversealternatelevelshelper(root, nodes, index,0);

}

void BST::insertelementsintoarray(Node *root, int *a, int &i, int level)
{
    if(root==NULL)
        return;
    if(level&1)
    {
        a[i] = root->data;
        i++;
    }
    insertelementsintoarray(root->left,a,i,level+1);
    insertelementsintoarray(root->right,a,i,level+1);

}

void BST::reversealternatelevelshelper(Node * root, int *nodes, int &index, int level)
{
    if(root==NULL)
        return;
    reversealternatelevelshelper(root->left, nodes,index,level+1);
    if(level&1)
    {
        root->data = nodes[index];
        index++;
    }
    reversealternatelevelshelper(root->right,nodes, index, level+1);

}

void BST::clonebinarytree()
{
    Node * cloneroot;
    map<Node*,Node*>mymap;
    if(root)
    {
        clonebinarytreehelper(root, &cloneroot);
    }
    cout<<"Inorder of clone tree"<<endl;
    inorderhelper(cloneroot);
}

Node* BST::newnode(int data)
{
    Node * n = new Node();
    n->left = NULL;
    n->right = NULL;
    n->nextright = NULL;
    n->data = data;
    return n;
}

void BST::clonebinarytreehelper(Node *root, Node ** cloneroot)
{
    if(root==NULL)
        return ;
    (*cloneroot) = newnode(root->data);
     clonebinarytreehelper(root->left,&((*cloneroot)->left));
     clonebinarytreehelper(root->right,&(*cloneroot)->right);

}
























