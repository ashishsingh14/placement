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


void BST::morrisinorder()
{
    if(root)
        morrisinorderhelper(root);
}

void BST::morrisinorderhelper(Node * root)
{
    Node * current = root;
    Node *pred = NULL;
    while(current)
    {
        if(current->left==NULL)
        {
            cout<<current->data<<" ";
            current = current->right;
        }
        else
        {
            pred = current->left;
            while(pred->right && pred->right!=current)
            {
                pred = pred->right;
            }
            if(pred->right==NULL)
            {
                pred->right=current;
                current=current->left;
            }
            else
            {
                pred->right=NULL;
                cout<<current->data<<" ";
                current = current->right;
            }

        }
    }
    cout<<endl;
}


void BST::morrispreorder()
{
    if(root)
        morrispreorderhelper(root);
}

void BST::morrispreorderhelper(Node * root)
{
    Node * current = root;
    Node *pred = NULL;
    while(current)
    {
        if(current->left==NULL)
        {
            cout<<current->data<<" ";
            current = current->right;
        }
        else
        {
            pred = current->left;
            while(pred->right && pred->right!=current)
            {
                pred = pred->right;
            }
            if(pred->right==NULL)
            {
                cout<<current->data<<" ";
                pred->right = current;
                current = current->left;
            }
            else
            {
                pred->right=NULL;
                current = current->right;
            }

        }
    }
    cout<<endl;
}

void BST::inorderstack()
{
    if(root)
        inorderstackhelper(root);
}

void BST::inorderstackhelper(Node * root)
{
    stack<Node*>s;
    Node * p = NULL;
    Node * current = root;
    while(!s.empty() || current!=NULL)
    {
        if(current)
        {
            s.push(current);
            current = current->left;
        }
        if(current==NULL)
        {
            p = s.top();
            s.pop();
            cout<<p->data<<" ";
            current = p->right;
        }
    }
}

void BST::preorderstack()
{
    if(root)
        preorderstackhelper(root);
}


void BST::preorderstackhelper(Node *root)
{
    Node * current = root;
    stack<Node *>s;
    s.push(current);
    while(!s.empty())
    {
        Node * temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
    }
    cout<<endl;
}

void BST::postorderstackhelper(Node * root)
{
    Node * current = root;
    stack<Node*>s;
    //cout<<"Ashish";
    do
    {
        while(current)
        {
            if(current->right)
                s.push(current->right);
            s.push(current);
            current = current->left;

        }


            current = s.top();
            s.pop();
            Node * r = s.top();
            if(current->right == r && (current->right!=NULL))
            {
                s.pop();
                s.push(current);
                current = current->right;
            }
            else
            {
                cout<<root->data<<" ";
                current = NULL;
            }

//        while(!s.empty())
//        {
//            cout<<"her is the "<<endl;
//            Node * t  = s.top();
//            cout<<t->data<<endl;
//            s.pop();
//        }

    }while(!s.empty());
    cout<<endl;
}


void BST::postorderstack()
{

    //cout<<root->data<<endl;
    if(root)
    {
        postorderstackhelper(root);
    }
}



void BST::roottoleaf()
{
    int sum = 49;
    if(root)
        cout<<roottoleafhelper(root, sum);
}

bool BST::roottoleafhelper(Node *root, int sum)
{
    if(root==NULL)
    {
        return (sum==0);
    }
   if(roottoleafhelper(root->left , sum-root->data) || roottoleafhelper(root->right, sum-root->data))
   {
       return true;
   }
   else
       return false;
}



















